#pragma once

#include "Enums.h"

#define _DEBUG
#define _CHANGE_ENEMY

// 68 Bytes
#define COMPRESSED_TREES

// 70 bytes
#define _TWO_TREE_TYPES


const uint8_t PROGMEM Levels[] = {
  // EnemyType,                                     DEF,  HP,   MinAttack, MaxAttack, MinSP,  MaxSP,  MinGP, MaxGP, Items
  static_cast<uint8_t>(EnemyType::Skeleton),        0,    25,   0,         11,        4,      6,      3,     9,     static_cast<uint8_t>(DungeonDecorations::Pumpkin) | static_cast<uint8_t>(DungeonDecorations::BricksRHS1) | static_cast<uint8_t>(DungeonDecorations::BricksRHS2) | static_cast<uint8_t>(DungeonDecorations::Skull),
  static_cast<uint8_t>(EnemyType::SmallWerewolf),   0,    35,   0,         14,        4,      7,      5,     11,    static_cast<uint8_t>(DungeonDecorations::BricksLHS) | static_cast<uint8_t>(DungeonDecorations::BricksMID),
  static_cast<uint8_t>(EnemyType::Skeleton),        4,    30,   0,         11,        5,      8,      5,     11,    static_cast<uint8_t>(DungeonDecorations::BricksLHS),  
  static_cast<uint8_t>(EnemyType::SmallWerewolf),   2,    40,   0,         14,        5,      9,      7,     16,    static_cast<uint8_t>(DungeonDecorations::BricksMID) | static_cast<uint8_t>(DungeonDecorations::Skull),
  static_cast<uint8_t>(EnemyType::GelatinousCube),  8,    50,   4,         18,        10,     15,     7,     16,    static_cast<uint8_t>(DungeonDecorations::Chest),
  static_cast<uint8_t>(EnemyType::Skeleton),        4,    30,   4,         11,        4,      8,      5,     11,    static_cast<uint8_t>(DungeonDecorations::Pumpkin) | static_cast<uint8_t>(DungeonDecorations::BricksRHS1) | static_cast<uint8_t>(DungeonDecorations::BricksRHS2),  
  static_cast<uint8_t>(EnemyType::SmallWerewolf),   2,    40,   4,         14,        4,      9,      5,     11,    static_cast<uint8_t>(DungeonDecorations::Pumpkin) | static_cast<uint8_t>(DungeonDecorations::Skull),
  static_cast<uint8_t>(EnemyType::Skeleton),        0,    30,   4,         11,        4,      9,      5,     8,     static_cast<uint8_t>(DungeonDecorations::BricksLHS),  
  static_cast<uint8_t>(EnemyType::SmallWerewolf),   2,    40,   4,         14,        5,      10,     7,     16,    static_cast<uint8_t>(DungeonDecorations::Pumpkin) | static_cast<uint8_t>(DungeonDecorations::BricksRHS1) | static_cast<uint8_t>(DungeonDecorations::BricksRHS2),
  static_cast<uint8_t>(EnemyType::LargeWerewolf),   10,   60,   8,         23,        10,     15,     7,     16,    static_cast<uint8_t>(DungeonDecorations::Pumpkin),    
  static_cast<uint8_t>(EnemyType::Skeleton),        0,    35,   8,         11,        5,      10,     5,     8,     static_cast<uint8_t>(DungeonDecorations::BricksMID) | static_cast<uint8_t>(DungeonDecorations::Skull), 
  static_cast<uint8_t>(EnemyType::SmallWerewolf),   2,    45,   8,         14,        5,      10,     5,     11,    static_cast<uint8_t>(DungeonDecorations::Pumpkin) | static_cast<uint8_t>(DungeonDecorations::BricksRHS1) | static_cast<uint8_t>(DungeonDecorations::BricksRHS2),
  static_cast<uint8_t>(EnemyType::Skeleton),        4,    35,   8,         11,        6,      12,     5,     11,    static_cast<uint8_t>(DungeonDecorations::Pumpkin),  
  static_cast<uint8_t>(EnemyType::SmallWerewolf),   4,    40,   8,         14,        6,      12,     7,     16,    static_cast<uint8_t>(DungeonDecorations::BricksLHS) | static_cast<uint8_t>(DungeonDecorations::BricksMID) | static_cast<uint8_t>(DungeonDecorations::BricksRHS1) | static_cast<uint8_t>(DungeonDecorations::BricksRHS2),
  static_cast<uint8_t>(EnemyType::Astarok),         12,   80,   12,        26,        0,      0,      0,     0,     static_cast<uint8_t>(DungeonDecorations::BricksMID) | static_cast<uint8_t>(DungeonDecorations::Skull),

};


const uint8_t PROGMEM RuneCombinations[] = {
                                        // 1,2,3,4,5, SP (cost), DMG1, DMG2, DMG3, HP
  1, 1, 7, 4, 4, 30, 20, 5, 5, 0,       // Fire Blaze
  2, 2, 4, 4, 4, 25, 0, 0, 0, 20,       // Healing Wind
  1, 1, 5, 3, 3, 35, 35, 0, 0, 0,       // Rising Star
  6, 6, 6, 6, 6, 30, 20, 2, 2, 0,       // Venom Mist
};

const uint8_t PROGMEM multiPart_ArrayIndex[3] = { 0, 5, 10 };
const uint8_t PROGMEM multiPart_LinesOverall[3] = { 5, 5, 7 };

constexpr const static uint8_t UPLOAD_DELAY = 16;

namespace Constants {

  constexpr uint8_t LevelData_RecordSize = 10;
  constexpr uint8_t RuneNoValue = 255;
  constexpr uint8_t RuneCombinations_Count = 4;

  constexpr uint8_t Player_Width = 13;
  constexpr uint8_t Player_Stairs = 108;
  constexpr uint8_t Player_CentrePos = 60;
  constexpr uint8_t Player_Ground_Level = 37;
  constexpr uint8_t PlayerItems_Count = static_cast<uint8_t>(HelmetType::Count) + static_cast<uint8_t>(PotionType::Count); // How many Helmets and potions are there?
  constexpr uint8_t PlayerPotions_InvMax = 5; // How many potions can we carry?

  constexpr int16_t Town_RightPos = -175;
  constexpr uint8_t HP_Index = 0;


  // Rune combination record structure and scores ..

  constexpr int8_t RuneCombinations_RecordLength = 10;
  constexpr int8_t RuneCombinations_Price = 5;
  constexpr int8_t RuneCombinations_DMG_1 = 6;
  constexpr int8_t RuneCombinations_DMG_2 = 7;
  constexpr int8_t RuneCombinations_DMG_3 = 8;
  constexpr int8_t RuneCombinations_HP = 9;

  constexpr uint8_t RuneCombination_FiveOfAKind_Score = 45;
  constexpr uint8_t RuneCombination_FourOfAKind_Score = 30;
  constexpr uint8_t RuneCombination_FullHouse_Score = 25;
  constexpr uint8_t RuneCombination_ThreeOfAKind_Score = 20;
  constexpr uint8_t RuneCombination_TwoPair_Score = 10;

  constexpr uint8_t DialogueDelay = 100;
  constexpr uint8_t DialogueDelay_Fight_Roll = DialogueDelay + 1;
  constexpr uint8_t DialogueDelay_Fight_Damage_ThisRoll = DialogueDelay_Fight_Roll + 1;
  constexpr uint8_t DialogueDelay_Fight_Damage_PrevRoll = DialogueDelay_Fight_Damage_ThisRoll + 1;
  constexpr uint8_t DialogueDelay_Fight_Damage_Apply = DialogueDelay_Fight_Damage_PrevRoll + 1;
  constexpr uint8_t DialogueDelay_Fight_Health = DialogueDelay_Fight_Damage_Apply + 1;
  constexpr uint8_t DialogueDelay_Enemy_HP_Steal = DialogueDelay_Fight_Health + 1;
  constexpr uint8_t DialogueDelay_Enemy_Roll = DialogueDelay_Enemy_HP_Steal + 1;
  constexpr uint8_t DialogueDelay_Enemy_Damage = DialogueDelay_Enemy_Roll + 1;
  constexpr uint8_t DialogueDelay_Enemy_Damage_Apply = DialogueDelay_Enemy_Damage + 1;
  constexpr uint8_t DialogueDelay_Enemy_Item_Steal = DialogueDelay_Enemy_Damage_Apply + 1;
  constexpr uint8_t DialogueDelay_End_Of_Roll_Start = DialogueDelay_Enemy_Item_Steal + 1;
  constexpr uint8_t DialogueDelay_End_Of_Roll_End = DialogueDelay_End_Of_Roll_Start + 60;
  constexpr uint8_t Player_Dead_Init = 1;
  constexpr uint8_t Player_Dead_End = 2;

  constexpr uint8_t DialogeDelay_MultiPart = 200;

  constexpr uint8_t Castle_GoldPosition = 93; 
  constexpr uint8_t Castle_EntryLimit = 5;
  constexpr int8_t Castle_LeftLimit = -12;
  constexpr uint8_t Castle_RightLimit = 113;
  constexpr uint8_t Castle_RightLimit_Monster = 49;
  constexpr uint8_t Castle_RightLimit_Steps = 109;

  constexpr uint8_t HP_FlashThreshold = 8;   // At what point does the HP gauge start flashing?
  constexpr uint8_t Inventory_NoAction = 255; // How many potions can we carry?
  constexpr uint8_t Tree_Count = 5;

  constexpr int16_t Tombstone_Location_01 = -190;
  constexpr int16_t Tombstone_Location_02 = -203;
  constexpr int16_t Tombstone_Location_03 = -216;

  constexpr int16_t Tombstone_Locations[3] = { Tombstone_Location_01, Tombstone_Location_02, Tombstone_Location_03 };
  
  constexpr int16_t NPC_Location_01 = -80;
  constexpr int16_t NPC_Location_02 = -8;
  constexpr int16_t NPC_Location_03 = 240;

  constexpr int16_t NPC_Locations[3] = { NPC_Location_01, NPC_Location_02, NPC_Location_03 };

  constexpr int16_t SavingPost_Location = -110;
}

const uint8_t Tombstone_Inscription_00[] PROGMEM = "   Here lies Vampirics.\n  Born 1843 - Dec 1882";
const uint8_t Tombstone_Inscription_01[] PROGMEM = " Rest In Peace Filmote.\n  Born 1841 - Dec 1879";
const uint8_t Tombstone_Inscription_02[] PROGMEM = "   Press Play On Tape\n     Developed 2019";

const uint8_t * const Tombstone_Inscriptions[] PROGMEM = { 
  Tombstone_Inscription_00,
  Tombstone_Inscription_01,
  Tombstone_Inscription_02,
};
                                    // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3
const uint8_t RandomNames[] PROGMEM = "TARATOMAMOMENOVASOSIKAKIMUNUTUSURESETEPEPOPIPA";
const uint8_t RandomNames_Count = 23; 

const uint8_t Diagloue_00[] PROGMEM = "Welcome traveller to the town";
const uint8_t Diagloue_01[] PROGMEM = "of Griford. The evil AstaroK";
const uint8_t Diagloue_02[] PROGMEM = "has turned us all into pumpkin";
const uint8_t Diagloue_03[] PROGMEM = "people. Please help us defeat";
const uint8_t Diagloue_04[] PROGMEM = "this crazy wizard!";
const uint8_t Diagloue_05[] PROGMEM = "Be sure to equip yourself";
const uint8_t Diagloue_06[] PROGMEM = "properly. You can press \"$% to";
const uint8_t Diagloue_07[] PROGMEM = "access your inventory and to";
const uint8_t Diagloue_08[] PROGMEM = "view information about you or";
const uint8_t Diagloue_09[] PROGMEM = "your enemies.";
const uint8_t Diagloue_10[] PROGMEM = "In combat, cast runes to score";
const uint8_t Diagloue_11[] PROGMEM = "'poker' hands. Pressing \"#% will";
const uint8_t Diagloue_12[] PROGMEM = "cast the runes - jump and";
const uint8_t Diagloue_13[] PROGMEM = "touch runes to select them";
const uint8_t Diagloue_14[] PROGMEM = "for recasting. Normally you";
const uint8_t Diagloue_15[] PROGMEM = "can cast 3 times, but some";
const uint8_t Diagloue_16[] PROGMEM = "items might give you extra.";

const uint8_t * const Dialogue[] PROGMEM = { 
  Diagloue_00,
  Diagloue_01,
  Diagloue_02,
  Diagloue_03,
  Diagloue_04,
  Diagloue_05,
  Diagloue_06,
  Diagloue_07,
  Diagloue_08,
  Diagloue_09,
  Diagloue_10,
  Diagloue_11,
  Diagloue_12,
  Diagloue_13,
  Diagloue_14,
  Diagloue_15,
  Diagloue_16,
};