#include "src/utils/Arduboy2Ext.h"


// ---------------------------------------------------------------------------------------------------------------------------
//  Render the state .. 
// ---------------------------------------------------------------------------------------------------------------------------
// 
void playGame_Render() {

  TimeOfDay timeOfDay = TimeOfDay::Night;

  switch (playGameVars.viewState) {

    case ViewState::InTown:

      timeOfDay = TimeOfDay::Day;

      for (int16_t x = -4 + (playGameVars.world.cloudsXPos & 3); x < 128; x = x + 4) {
        SpritesB::drawOverwrite(x, 0, Images::Sky, 0);
      } 

      for (int16_t x = -128 + (playGameVars.world.cloudsXPos & 127); x < 256; x = x + 128) {
        ardBitmap.drawCompressed(x, 0, Images::Cloud_01, WHITE, MIRROR_NONE);
        ardBitmap.drawCompressed(x + 55, -3, Images::Cloud_01, WHITE, MIRROR_NONE);
        ardBitmap.drawCompressed(x + 90, 3, Images::Cloud_02, WHITE, MIRROR_NONE);
      }

      playGame_RenderTrees(playGameVars.world.buildingXPos);
      playGame_RenderTownItems(RenderPosition::Background);


      // Render buildings ..

      {
        int16_t xPos = playGameVars.world.buildingXPos;
        int16_t x = playGameVars.world.buildings[0];
        
//        SpritesB::drawExternalMask(x + xPos - 33, 4, Images::ItemsBuilding_Top, Images::ItemsBuilding_Top_Mask, 0, 0);
        SpritesB::drawPlusMask(x + xPos - 33, 4, Images::ItemsBuilding_Top, 0);
        SpritesB::drawOverwrite(x + xPos - 38, 22, Images::ItemsBuilding_Bottom, 0);
        SpritesB::drawExternalMask(x + xPos + 10, 12, Images::Pumpkin, Images::Pumpkin_Mask, 0, 0);

        if (playGameVars.gameOver) {
//          SpritesB::drawExternalMask(x + xPos - 6, 36, Images::ClosedDoor, Images::ClosedDoor_Mask, 0, 0);
          SpritesB::drawOverwrite(x + xPos - 6, 36, Images::ClosedDoor, 0);
        }

      }

      {
        int16_t xPos = playGameVars.world.buildingXPos;
        int16_t x = playGameVars.world.buildings[1];

//        SpritesB::drawExternalMask(x + xPos - 26, 1, Images::RunesBuilding_Top, Images::RunesBuilding_Top_Mask, 0, 0);
        SpritesB::drawPlusMask(x + xPos - 26, 1, Images::RunesBuilding_Top, 0);
        SpritesB::drawOverwrite(x + xPos + 22, 32, Images::RunesBuilding_Side, 0);
        SpritesB::drawOverwrite(x + xPos - 45, 32, Images::RunesBuilding_Side, 0);
        SpritesB::drawOverwrite(x + xPos - 26, 17, Images::RunesBuilding_Bottom, 0);

        if (playGameVars.gameOver) {
//          SpritesB::drawExternalMask(x + xPos - 6, 36, Images::ClosedDoor, Images::ClosedDoor_Mask, 0, 0);
          SpritesB::drawOverwrite(x + xPos - 6, 36, Images::ClosedDoor, 0);
        }

      }


      // Render town items

      playGame_RenderTownItems(RenderPosition::FrontOfBuildings);

      for (int16_t x = -48 + (playGameVars.world.buildingXPos % 48); x < 128; x = x + 48) {
        SpritesB::drawExternalMask(x, 47, Images::Grass, Images::Grass_mask, 0, 0);
      }

      for (int16_t x = -16 + (playGameVars.world.foregroundXPos % 16); x < 128; x = x + 16) {
        SpritesB::drawOverwrite(x, 50, Images::Town_Gound, 0);
      }
      
      playGameVars.player.render(arduboy, ardBitmap, false);
      playGame_RenderTownItems(RenderPosition::FrontOfPlayer);

      break;

    case ViewState::InShopItems:
    case ViewState::InShopItems_ConfirmPurchase:
      {
        uint8_t gp = pgm_read_byte(&Player_Items[(playGameVars.itemIdx * 4) + 3]);

        playGame_CommonShopItems(Images::ShopKeeper_Item, Images::gpGauge);

        switch (playGameVars.itemIdx) {

          case 0 ... Constants::PlayerItems_Count - 1:
            {
              playGame_CommonPrice(Images::UOM_GP, gp / 5);

              if (playGameVars.itemIdx < static_cast<uint8_t>(HelmetType::Count)) {
                
                ardBitmap.drawCompressed(5, 19, Images::ItemShop_HelmetBase, WHITE, MIRROR_NONE);
                ardBitmap.drawCompressed_WithMask(24, 7, reinterpret_cast<const uint8_t *>(pgm_read_ptr(&Images::ItemShop_Helmet[playGameVars.itemIdx])), Images::ItemShop_Helmet_Mask, MIRROR_NONE);

              }
              else {

                uint8_t idx = playGameVars.itemIdx - static_cast<uint8_t>(HelmetType::Count);
                ardBitmap.drawCompressed(5, 19, Images::ItemShop_HelmetBase, WHITE, MIRROR_NONE);
                ardBitmap.drawCompressed(13, 16, Images::ItemShop_Potion_Mask, BLACK, MIRROR_NONE);
                ardBitmap.drawCompressed(44, 16, Images::ItemShop_Potion_Mask, BLACK, MIRROR_NONE);
                SpritesB::drawSelfMasked(13, 8, Images::ItemShop_Potions, idx);
                SpritesB::drawSelfMasked(44, 8, Images::ItemShop_Potions, idx);

              }

              playGame_RenderShopItemOrRune(reinterpret_cast<const uint8_t *>(pgm_read_ptr(&Images::ItemShop_Names[playGameVars.itemIdx])), reinterpret_cast<const uint8_t *>(pgm_read_ptr(&Images::ItemShop_Effect[playGameVars.itemIdx])));
              
            }
            break;

          case Constants::PlayerItems_Count:
            // arduboy.fillRect(83, 36, 32, 12, WHITE);
//            SpritesB::drawExternalMask(83, 36, Images::Bye, Images::Bye_Mask, 0, 0);
            SpritesB::drawPlusMask(83, 36, Images::Bye, 0);
            ardBitmap.drawCompressed(15, 10, Images::LeaveShop_Image, WHITE, MIRROR_NONE);
            ardBitmap.drawCompressed(12, 34, Images::LeaveShop, WHITE, MIRROR_NONE);
            break;

        }

        playGame_RenderNumber(playGameVars.player.getGP());

      }

      break;

    case ViewState::InShopRunes:
    case ViewState::InShopRunes_ConfirmPurchase:
      {
        playGame_CommonShopItems(Images::ShopKeeper_Rune, Images::spGauge);

        switch (playGameVars.runeIdx) {

          case 0 ... static_cast<uint8_t>(RuneCombinationType_Purchased::Count) - 1:
            {
              uint8_t sp = pgm_read_byte(&RuneCombinations[(playGameVars.runeIdx * Constants::RuneCombinations_RecordLength) + 5]);
              playGame_RenderShopItemOrRune(reinterpret_cast<const uint8_t *>(pgm_read_ptr(&Images::RuneShop_Names[playGameVars.runeIdx])), reinterpret_cast<const uint8_t *>(pgm_read_ptr(&Images::RuneShop_Effect[playGameVars.runeIdx])));
              playGame_CommonPrice(Images::UOM_SP, sp / 5);
              playGame_RenderRunes(5, 11, playGameVars.runeIdx);
            }
            break;

          default:
//            arduboy.fillRect(83, 36, 32, 12, WHITE);
//            SpritesB::drawExternalMask(83, 36, Images::Bye, Images::Bye_Mask, 0, 0);
            SpritesB::drawPlusMask(83, 36, Images::Bye, 0);
            ardBitmap.drawCompressed(15, 10, Images::LeaveShop_Image, WHITE, MIRROR_NONE);
            ardBitmap.drawCompressed(12, 34, Images::LeaveShop, WHITE, MIRROR_NONE);
            break;

        }

        playGame_RenderNumber(playGameVars.player.getSP());

      }
      break;

    case ViewState::InDungeon_Entry:
    case ViewState::InDungeon_PlayersTurn:
    case ViewState::InDungeon_EnemysAttacksFirst:
    case ViewState::InDungeon_EnemysTurn:

      if (playGameVars.viewState != ViewState::InDungeon_EnemysAttacksFirst && playGameVars.viewState != ViewState::InDungeon_EnemysTurn) {
        playGame_RenderRuneHand(0, 10, 13);
      }

      SpritesB::drawOverwrite(52, 0, Images::RollsLeft, 0);
      SpritesB::drawSelfMasked(56, 2, Images::Numbers_4x4, playGameVars.numberOfRecasts - playGameVars.reroll);
      playGame_RenderCastleInterior();
      playGameVars.player.render(arduboy, ardBitmap, true);
      playGameVars.enemy.render(arduboy, ardBitmap, font3x6);

      if (playGameVars.matchedRuneCombination.prevDmg1_Fire > 0)         { SpritesB::drawSelfMasked(68, 0, Images::DMGFire, 0); }
      else if (playGameVars.matchedRuneCombination.prevDmg1_Venom > 0)   { SpritesB::drawSelfMasked(68, 0, Images::DMGMist, 0); }

      break;

    case ViewState::InDungeon_PlayerDead:
      playGame_RenderCastleInterior();
      SpritesB::drawOverwrite(playGameVars.player.getX(), 34, Images::Tombstone2, 0);
      playGameVars.enemy.render(arduboy, ardBitmap, font3x6);

      break;

    case ViewState::InDungeon_EnemyDead:

      if (arduboy.everyXFrames(16)) { playGameVars.victoryFrame++; if (playGameVars.victoryFrame == 4) playGameVars.victoryFrame = 0; }

      if (playGameVars.gameOver) {
        
        ardBitmap.drawCompressed(64, 28, Images::AztaroK_Dead, WHITE, MIRROR_NONE);
      
      }

      playGame_RenderCastleInterior();
      playGameVars.player.render(arduboy, ardBitmap, true);

      if (playGameVars.victoryGP > 0) {
        SpritesB::drawSelfMasked(Constants::Castle_GoldPosition, 42, Images::Coins, playGameVars.victoryFrame);
      }

      break;

  }


  if (!fadeInEffect.isComplete()) {

    fadeInEffect.draw(arduboy);
    fadeInEffect.update();

  }

  if (playGameVars.inventory.show) {

    constexpr uint8_t xPos = 55;
    constexpr int8_t yPos = -1;
    constexpr uint8_t width = 74;
    constexpr uint8_t height = 64;

    drawMessageBox(xPos, yPos, width, height);
    font3x6.setCursor(xPos + 19, yPos + 2);
    SpritesB::drawOverwrite(xPos + 10, yPos + 3, Images::Arrow_Left, 0);
    SpritesB::drawOverwrite(xPos + 61, yPos + 3, Images::Arrow_Right, 0);

    switch (playGameVars.inventory.mode) {

      case InventoryMode::Inventory:

        font3x6.print(F(" Inventory"));
        
        if (playGameVars.player.getDistinctItemCount() == 0) {
          playGame_NoneMessage();
        }
        else {
          font3x6.setCursor(xPos + 8, yPos + 19);
          uint8_t renderedItems = 0;

          for (int8_t x = playGameVars.inventory.topIndex; x < Constants::PlayerItems_Count; x++) {

            uint8_t qty = playGameVars.player.getItemCount(x);

            if (qty > 0) {
              if (renderedItems < 4) {
                font3x6.print(readFlashStringPointer(&PlayerItems_Captions[x]));
                if (x < static_cast<uint8_t>(HelmetType::Count)) {
                  if (static_cast<uint8_t>(playGameVars.player.getHelmetType()) == x) {
                    SpritesB::drawSelfMasked(xPos + width - 10,  yPos + 19 + (renderedItems * 9), Images::Inventory_Helmet_Marker, 0);
                  }
                }
                else {
                  font3x6.print(F(" x "));
                  font3x6.print(qty);
                }
                font3x6.print(F("\n"));
              }
              renderedItems++;
            }

          }

          if (renderedItems > 0) SpritesB::drawSelfMasked(xPos + 4, yPos + 23 + (playGameVars.inventory.cursorIndex * 9), Images::Inventory_Marker, 0);
          if (playGameVars.inventory.topIndex > 0) SpritesB::drawSelfMasked(90, yPos + 14, Images::Arrow_Up_Small, 0);
          if (renderedItems > 5) SpritesB::drawSelfMasked(90, yPos + height - 5, Images::Arrow_Down_Small, 0);


        }
        break;

      case InventoryMode::Statistics:

        font3x6.print(F("Statistics"));
        font3x6.setCursor(xPos + 8, yPos + 15);
        font3x6.print(F("Health :\nSkill :\nDefence :\nGold :\nDungeons :"));
        font3x6.setCursor(xPos + 54, yPos + 15);
        font3x6.println(playGameVars.player.getHP());
        font3x6.println(playGameVars.player.getSP());
        font3x6.println(playGameVars.player.getDEFOverall());
        font3x6.println(playGameVars.player.getGP());
        font3x6.println(playGameVars.world.dungeon);

        break;

      case InventoryMode::Runes:

        font3x6.print(F("    Runes"));

        if (playGameVars.inventory.runeIdx == Constants::RuneNoValue) {
          playGame_NoneMessage();
        }
        else {

          playGame_RenderRunes(xPos + 5, 15, playGameVars.inventory.runeIdx);

          uint8_t count = playGameVars.player.getDistinctRuneCombinationCount();

          font3x6.setCursor(xPos + 10 + (count < 2 ? 8 : 0), yPos + 33);
          font3x6.print(readFlashStringPointer(&RuneCombination_Purchased_Captions[playGameVars.inventory.runeIdx]));
          font3x6.setCursor(xPos + 10 + (count < 2 ? 8 : 0), yPos + 42);
          font3x6.print(readFlashStringPointer(&Rune_Effect_Captions[playGameVars.inventory.runeIdx]));

          if (count > 1) {
            SpritesB::drawSelfMasked(xPos + 58, yPos + 34, Images::Arrow_Up_Small, 0);            
            SpritesB::drawSelfMasked(xPos + 58, yPos + 45, Images::Arrow_Down_Small, 0);            
          }

        }

        break;

      case InventoryMode::Enemy:

        font3x6.print(F(" Enemy Sts"));

        switch (playGameVars.viewState) {

          case ViewState::InDungeon_Entry:
          case ViewState::InDungeon_PlayersTurn:
          case ViewState::InDungeon_EnemysTurn:
            font3x6.setCursor(xPos + 7, yPos + 15);
            font3x6.print(F("Name:\nHealth :\nDefence :\n"));
            font3x6.setCursor(xPos + 43, yPos + 15);
            playGameVars.enemy.renderName(font3x6);

            font3x6.print(F("\n"));
            font3x6.println(playGameVars.enemy.getHP());
            font3x6.println(playGameVars.enemy.getDEF());
            break;

          default:
            playGame_NoneMessage();
            break;

        }

        break;

      default: break;

    }

  }

  if (playGameVars.showSaveDialogue && playGameVars.counter == 0) {

    uint8_t c;
		EEPROM.get(100, c);

    drawMessageBox(c == 'c' ? 3 : 2, 88);
    font3x6.setCursor(40, 4);

    font3x6.print(F("Save Game\nNew Game\n"));
    if (c == 'c') {
      font3x6.print(F("Restore Game"));
    }

    SpritesB::drawOverwrite(30, 5 + (playGameVars.inventory.saveGameIndex * 9), Images::Arrow_Right, 0);

  }

  if (playGameVars.message.renderRequired) {

    if (playGameVars.message.message != nullptr || playGameVars.counter == Constants::DialogeDelay_MultiPart) {

      if (playGameVars.counter == Constants::DialogeDelay_MultiPart) {

        drawMessageBox(2, 130);
        font3x6.setCursor(8, 5);
        font3x6.print(readFlashStringPointer(&Dialogue[playGameVars.message.arrayIndex + playGameVars.message.topLine]));
        font3x6.print(F("\n"));
        font3x6.print(readFlashStringPointer(&Dialogue[playGameVars.message.arrayIndex + playGameVars.message.topLine + 1]));

        if (playGameVars.message.topLine > 0) SpritesB::drawSelfMasked(116, 5, Images::Arrow_Up_Dialogue, 0);
        if (playGameVars.message.topLine + 2 < playGameVars.message.linesOverall) SpritesB::drawSelfMasked(116, 19, Images::Arrow_Down_Dialogue, 0);

      }
      else {

        drawMessageBox(playGameVars.message.message, playGameVars.message.lines, playGameVars.message.width);

      }

    }
    else {

      switch (playGameVars.viewState) {

        case ViewState::InDungeon_Entry:
        case ViewState::InDungeon_PlayersTurn:
            
          switch (playGameVars.counter) {

            case Constants::DialogueDelay_Fight_Roll:

              switch (playGameVars.matchedRuneCombination.id) {

                case static_cast<uint8_t>(RuneCombinationType_Purchased::FireBlaze) ... static_cast<uint8_t>(RuneCombinationType_Purchased::Count) - 1:
                  playGame_YouRolledMessage(RuneCombination_Purchased_Captions_Length[playGameVars.matchedRuneCombination.id]);
                  font3x6.print(F("a "));
                  font3x6.print(readFlashStringPointer(&RuneCombination_Purchased_Captions[playGameVars.matchedRuneCombination.id]));
                  font3x6.print(F("!"));
                  break;

                case RuneCombinationType_Standard::Start ... RuneCombinationType_Standard::End:
                  {
                    uint8_t index = playGameVars.matchedRuneCombination.id - RuneCombinationType_Standard::Start;
                    playGame_YouRolledMessage(RuneCombination_Standard_Captions_Length[index]);
                    font3x6.print(readFlashStringPointer(&RuneCombination_Standard_Captions[index]));
                  }
                  break;

                case Constants::RuneNoValue:
                  playGame_YouRolledMessage(88);
                  font3x6.print(F("nothing!"));
                  break;

              }
              break;

            case Constants::DialogueDelay_Fight_Damage_ThisRoll:
              drawMessageBox(1, 124);
              font3x6.print(F("You inflicted "));
              font3x6.print(playGameVars.matchedRuneCombination.dmg1);
              font3x6.print(F(" pts of damage."));
              break;

            case Constants::DialogueDelay_Fight_Damage_PrevRoll:
              drawMessageBox(1, 124);
              font3x6.print(F("Plus an extra "));              
              font3x6.print(playGameVars.matchedRuneCombination.getPrevDmg1(playGameVars.enemy.getEnemyType()));
              font3x6.print(F(" pts of damage."));
              break;

            case Constants::DialogueDelay_Fight_Health:
              drawMessageBox(1, 124);
              font3x6.print(F("You regained "));
              font3x6.print(playGameVars.matchedRuneCombination.hp);
              font3x6.print(F(" health points."));
              break;

            case Constants::DialogueDelay_Enemy_HP_Steal:
              drawMessageBox(1, 122);
              font3x6.print(F("  Aztarok stole "));
              font3x6.print(playGameVars.message.arrayIndex);
              font3x6.print(F(" hp points."));
              break;

          }

          break;

        case ViewState::InDungeon_EnemysTurn:
        
          switch (playGameVars.counter) {

            case Constants::DialogueDelay_Enemy_Roll:
            case Constants::DialogueDelay_Enemy_Damage:
              drawMessageBox(1, 130);

              playGameVars.enemy.renderName(font3x6);
              font3x6.print(F(" attacks, "));
              font3x6.print(playGameVars.dmgInflictedOnPlayer);
              font3x6.print(F(" damage pts."));
              break;

            case Constants::DialogueDelay_Enemy_Item_Steal:
              drawMessageBox(2, 122);
              font3x6.print(F("The Gelatinous Cube stole a\n   "));

              if (playGameVars.message.arrayIndex < Constants::PlayerItems_Count) {
                font3x6.print(readFlashStringPointer(&PlayerItems_Captions[playGameVars.message.arrayIndex]));
              }
              else {
                font3x6.print(readFlashStringPointer(&RuneCombination_Purchased_Captions[playGameVars.message.arrayIndex - Constants::PlayerItems_Count]));                
                font3x6.print(F(" rune"));
              }

              font3x6.print(F(" from you!"));
              break;

            default: break;

          }

          break;

        case ViewState::InDungeon_EnemyDead:

          if (playGameVars.gameOver) {
            
            drawMessageBox(2, 124);
            font3x6.print(F(" You killed Astarok and freed\nthe villagers from the curse!"));

          }
          else {

            if (playGameVars.message.victoryGP > 0 && playGameVars.message.victorySP == 0) {
              drawMessageBox(1, 110);
              font3x6.print(F("You scored "));
              font3x6.print(playGameVars.message.victoryGP);
              font3x6.print(F(" gold coins."));
            }
            else if (playGameVars.message.victorySP > 0) {
              drawMessageBox(1, 110);
              font3x6.print(F("You scored "));
              font3x6.print(playGameVars.message.victorySP);
              font3x6.print(F(" skill points."));
            }

          }
          break;

        case ViewState::InDungeon_PlayerDead:
            drawMessageBox(2, 112);
            font3x6.print(F("You died! Lose half of your\n      gold and skill points!"));
            break;

        default: break;

      }

    }

    playGameVars.message.renderRequired = false;

  }

// auto x = (playGameVars.world.buildingXPos - playGameVars.player.getX());
// drawMessageBox(2, 112);
// font3x6.print(x);

  arduboy.displayWithBackground(timeOfDay);

}


void playGame_RenderTrees(int16_t xPos) {

	for (uint8_t index = 0; index < Constants::Tree_Count; ++index) {		

		int16_t x = pgm_read_word(&Data::Trees[index].offset);
		uint8_t treeIndex = pgm_read_byte(&Data::Trees[index].tree);		

    #ifdef COMPRESSED_TREES
      #ifdef TWO_TREE_TYPES
        ardBitmap.drawCompressed(x + xPos - 6, 18, reinterpret_cast<const uint8_t *>(pgm_read_ptr(&Images::Trees[treeIndex])), BLACK, MIRROR_NONE);
      #else
        ardBitmap.drawCompressed(x + xPos - 6, 18, Images::Tree, BLACK, treeIndex == 0 ? MIRROR_NONE : MIRROR_HORIZONTAL);
      #endif
    #else
    SpritesB::drawOverwrite(x + xPos - 6, 18, Images::Trees, treeIndex);
    #endif

	}
  
}

void playGame_RenderCastleInterior() {

  bool astarok = (playGameVars.enemy.getEnemyType() == EnemyType::Astarok);
  uint8_t maxX = (astarok ? 127 : 95);

  for (int16_t x = -2; x < maxX; x = x + 16) {
    SpritesB::drawOverwrite(x, 50, Images::Castle_Floor, 0);
  }

  if (!astarok) ardBitmap.drawCompressed(112, 54, Images::Castle_Stairs, WHITE, MIRROR_NONE);

  SpritesB::drawOverwrite(119, -5, Images::Chain, 0);
  SpritesB::drawOverwrite(124, 0, Images::Chain, 0);

  {
    LevelData levelData;
    const uint8_t xPos[] = { 10, 50, 74, 104, 40, 30, 13 };
    const uint8_t yPos[] = { 30, 30, 19, 29, 44, 46, 39 };

    memcpy_P(&levelData, &Levels[(playGameVars.world.dungeon - 1) * Constants::LevelData_RecordSize], Constants::LevelData_RecordSize);

    for (uint8_t x = 0; x < 8; x++) {

      if (levelData.decorations & (1 << x)) {
        SpritesB::drawSelfMasked(xPos[x], yPos[x], reinterpret_cast<const uint8_t *>(pgm_read_ptr(&Images::DungeonDecorations_Images[x])), 0);
      }

    }

  }

}

void playGame_CommonShopItems(const uint8_t * item, const uint8_t * gauge) {

  ardBitmap.drawCompressed(77, 3, item, WHITE, MIRROR_NONE);
  ardBitmap.drawCompressed(81, 34, Images::ShopKeeper_Panel, WHITE, MIRROR_NONE);
	SpritesB::drawOverwrite(81, 52, gauge, 0);
  ardBitmap.drawCompressed(5, 30, Images::RuneShop_Frame, WHITE, MIRROR_NONE);

  if (!playGameVars.inventory.show) {
    SpritesB::drawOverwrite(33, (playGameVars.highlight_UpArrow > 0 ? 0 : 1), Images::Arrow_Up, 0);
    SpritesB::drawOverwrite(33, (playGameVars.highlight_DownArrow > 0 ? 60 : 59), Images::Arrow_Down, 0);
  }

}

void playGame_CommonPrice(const uint8_t * uom, uint8_t val) {

  SpritesB::drawSelfMasked(89, 36, Images::Shop_Numbers, val);
  SpritesB::drawSelfMasked(103, 36, uom, 0);

}

void playGame_YouRolledMessage(uint8_t width) {

  drawMessageBox(1, width);
  font3x6.setCursor(64 - (width / 2) + 10, 5);
  font3x6.print(F("You rolled "));

}

void playGame_NoneMessage() {

  font3x6.setCursor(82, 26);
  font3x6.print(F("None !"));

}


void playGame_RenderTownItems(RenderPosition renderPosition) {

    for (uint8_t x = 0; x < playGameVars.world.townItems_Size; x++) {
      playGameVars.world.townItems[x].render(arduboy, ardBitmap, playGameVars.world.buildingXPos, renderPosition, playGameVars.gameOver);
    }  

}

void playGame_RenderNumber(uint8_t val) {

  uint8_t digits[4];
  extractDigits(digits, val);

  for (uint8_t j = 4; j > 0; --j) {

    SpritesB::drawErase(118 - (j*5), 55, Images::Numbers_4x5, digits[j - 1]);

  }

}


void playGame_RenderRunes(uint8_t xPos, uint8_t yPos, uint8_t runeIdx) {

  for (uint8_t x = 0; x < 5; x++) {
    uint8_t index = pgm_read_byte(&RuneCombinations[(runeIdx * Constants::RuneCombinations_RecordLength) + x]);
    ardBitmap.drawCompressed(xPos + (x * 13), yPos, Images::Rune_Frame_00, WHITE, MIRROR_NONE);
    SpritesB::drawOverwrite(xPos + (x * 13) + 3, yPos + 4, Images::Rune_Symbols, index);
  }

}


void playGame_RenderRuneHand(const uint8_t x, const uint8_t y, const uint8_t spacing) {

  for (uint8_t i = 0, z = x; i < 5; i++, z = z + spacing) {

    Rune rune = playGameVars.runes.getRune(i);
    uint8_t frame = rune.getFrame();
    uint8_t value = rune.getValue();
    bool reroll = rune.getReroll();
    bool isRotating = rune.isRotating();
    
    ardBitmap.drawCompressed(z, y, reinterpret_cast<const uint8_t *>(pgm_read_ptr(&Images::Rune_Frame[frame])), WHITE, MIRROR_NONE);
    if (!reroll && ! isRotating) SpritesB::drawOverwrite(z + 3, y + 4, Images::Rune_Symbols, value);

  }

}

void playGame_RenderShopItemOrRune(const uint8_t * name, const uint8_t * effect) {

    ardBitmap.drawCompressed(8, 33, name, WHITE, MIRROR_NONE);
    ardBitmap.drawCompressed(7, 45, effect, WHITE, MIRROR_NONE);

}