#pragma once

// Imported 71 messages from "messages.h"

constexpr uint8_t Inventory_Title_Idx = 0;
constexpr uint8_t Inventory_Quantity_Idx = 1;
constexpr uint8_t Statistics_Title_Idx = 2;
constexpr uint8_t Statistics_Health_Idx = 3;
constexpr uint8_t Runes_Title_Idx = 4;
constexpr uint8_t Enemy_Title_Idx = 5;
constexpr uint8_t Enemy_Stats_Idx = 6;
constexpr uint8_t Save_Game_Option_Idx = 7;
constexpr uint8_t Restore_Game_Option_Idx = 8;
constexpr uint8_t Purchased_A_Idx = 9;
constexpr uint8_t Cast_Nothing_Idx = 10;
constexpr uint8_t You_Inflicted_Idx = 11;
constexpr uint8_t Points_Damage_Idx = 12;
constexpr uint8_t Plus_Extra_Idx = 13;
constexpr uint8_t You_Regained_Idx = 14;
constexpr uint8_t Health_Points_Idx = 15;
constexpr uint8_t Aztarok_Stole_Idx = 16;
constexpr uint8_t Hp_Points_Idx = 17;
constexpr uint8_t Attacks_Idx = 18;
constexpr uint8_t Damage_Points_Idx = 19;
constexpr uint8_t Gelly_Theft_Idx = 20;
constexpr uint8_t Rune_Idx = 21;
constexpr uint8_t From_You_Idx = 22;
constexpr uint8_t You_Win_Idx = 23;
constexpr uint8_t You_Scored_Idx = 24;
constexpr uint8_t Gold_Coins_Idx = 25;
constexpr uint8_t Skill_Points_Idx = 26;
constexpr uint8_t You_Lost_Idx = 27;
constexpr uint8_t GP_Idx = 28;
constexpr uint8_t SP_Idx = 29;
constexpr uint8_t You_Cast_Idx = 30;
constexpr uint8_t None_Idx = 31;
constexpr uint8_t Press_Play_Idx = 32;
constexpr uint8_t Presents_Idx = 33;
constexpr uint8_t Astarok_Name_Idx = 34;
constexpr uint8_t Dialogue_00_Idx = 35;
constexpr uint8_t Dialogue_01_Idx = 36;
constexpr uint8_t Dialogue_02_Idx = 37;
constexpr uint8_t Dialogue_03_Idx = 38;
constexpr uint8_t Dialogue_04_Idx = 39;
constexpr uint8_t Dialogue_05_Idx = 40;
constexpr uint8_t Dialogue_06_Idx = 41;
constexpr uint8_t Dialogue_07_Idx = 42;
constexpr uint8_t Dialogue_08_Idx = 43;
constexpr uint8_t Dialogue_09_Idx = 44;
constexpr uint8_t Dialogue_10_Idx = 45;
constexpr uint8_t Dialogue_11_Idx = 46;
constexpr uint8_t Dialogue_12_Idx = 47;
constexpr uint8_t Dialogue_13_Idx = 48;
constexpr uint8_t Dialogue_14_Idx = 49;
constexpr uint8_t Dialogue_15_Idx = 50;
constexpr uint8_t Dialogue_16_Idx = 51;
constexpr uint8_t PlayerItems_Caption00_Idx = 52;
constexpr uint8_t PlayerItems_Caption01_Idx = 53;
constexpr uint8_t PlayerItems_Caption02_Idx = 54;
constexpr uint8_t PlayerItems_Caption03_Idx = 55;
constexpr uint8_t PlayerItems_Caption04_Idx = 56;
constexpr uint8_t PlayerItems_Caption05_Idx = 57;
constexpr uint8_t RuneCombination_Purchased_Caption00_Idx = 58;
constexpr uint8_t RuneCombination_Purchased_Caption01_Idx = 59;
constexpr uint8_t RuneCombination_Purchased_Caption02_Idx = 60;
constexpr uint8_t RuneCombination_Purchased_Caption03_Idx = 61;
constexpr uint8_t Rune_Effect_Caption00_Idx = 62;
constexpr uint8_t Rune_Effect_Caption01_Idx = 63;
constexpr uint8_t Rune_Effect_Caption02_Idx = 64;
constexpr uint8_t Rune_Effect_Caption03_Idx = 65;
constexpr uint8_t RuneCombination_Standard_51_Idx = 66;
constexpr uint8_t RuneCombination_Standard_52_Idx = 67;
constexpr uint8_t RuneCombination_Standard_53_Idx = 68;
constexpr uint8_t RuneCombination_Standard_54_Idx = 69;
constexpr uint8_t RuneCombination_Standard_55_Idx = 70;

const uint8_t messages[] PROGMEM = {
' ','I','n','v','e','n','t','o','r','y' + 0x80,
' ','x',' ' + 0x80,
'S','t','a','t','i','s','t','i','c','s' + 0x80,
'H','e','a','l','t','h',' ',':','\n','S','k','i','l','l',' ',':','\n','D','e','f','e','n','c','e',' ',':','\n','G','o','l','d',' ',':','\n','D','u','n','g','e','o','n','s',' ',':' + 0x80,
' ',' ',' ',' ','R','u','n','e','s' + 0x80,
' ','E','n','e','m','y',' ','S','t','s' + 0x80,
'N','a','m','e',':','\n','H','e','a','l','t','h',' ',':','\n','D','e','f','e','n','c','e',' ',':','\n' + 0x80,
'S','a','v','e',' ','G','a','m','e','\n','N','e','w',' ','G','a','m','e','\n' + 0x80,
'R','e','s','t','o','r','e',' ','G','a','m','e' + 0x80,
'a',' ' + 0x80,
'n','o','t','h','i','n','g','!' + 0x80,
'Y','o','u',' ','i','n','f','l','i','c','t','e','d',' ' + 0x80,
' ','p','t','s',' ','o','f',' ','d','a','m','a','g','e','.' + 0x80,
'P','l','u','s',' ','a','n',' ','e','x','t','r','a',' ' + 0x80,
'Y','o','u',' ','r','e','g','a','i','n','e','d',' ' + 0x80,
' ','h','e','a','l','t','h',' ','p','o','i','n','t','s','.' + 0x80,
' ',' ','A','z','t','a','r','o','k',' ','s','t','o','l','e',' ' + 0x80,
' ','h','p',' ','p','o','i','n','t','s','.' + 0x80,
' ','a','t','t','a','c','k','s',',',' ' + 0x80,
' ','d','a','m','a','g','e',' ','p','t','s','.' + 0x80,
'T','h','e',' ','G','e','l','a','t','i','n','o','u','s',' ','C','u','b','e',' ','s','t','o','l','e',' ','a','\n',' ',' ',' ' + 0x80,
' ','r','u','n','e' + 0x80,
' ','f','r','o','m',' ','y','o','u','!' + 0x80,
' ','Y','o','u',' ','k','i','l','l','e','d',' ','A','s','t','a','r','o','k',' ','a','n','d',' ','f','r','e','e','d','\n','t','h','e',' ','v','i','l','l','a','g','e','r','s',' ','f','r','o','m',' ','t','h','e',' ','c','u','r','s','e','!' + 0x80,
'Y','o','u',' ','s','c','o','r','e','d',' ' + 0x80,
' ','g','o','l','d',' ','c','o','i','n','s','.' + 0x80,
' ','s','k','i','l','l',' ','p','o','i','n','t','s','.' + 0x80,
'Y','o','u',' ','d','i','e','d','!',' ','L','o','s','e',' ','h','a','l','f',' ','o','f',' ','y','o','u','r','\n',' ',' ',' ',' ',' ',' ','g','o','l','d',' ','a','n','d',' ','s','k','i','l','l',' ','p','o','i','n','t','s','!' + 0x80,
'G','P' + 0x80,
'S','P' + 0x80,
'Y','o','u',' ','c','a','s','t',' ' + 0x80,
'N','o','n','e',' ','!' + 0x80,
'P','r','e','s','s',' ','P','l','a','y',' ','O','n',' ','T','a','p','e' + 0x80,
'p','r','e','s','e','n','t','s' + 0x80,
'A','S','T','A','R','O','K' + 0x80,
'W','e','l','c','o','m','e',' ','t','r','a','v','e','l','l','e','r',' ','t','o',' ','t','h','e',' ','t','o','w','n' + 0x80,
'o','f',' ','G','r','i','f','o','r','d','.',' ','T','h','e',' ','e','v','i','l',' ','A','s','t','a','r','o','K' + 0x80,
'h','a','s',' ','t','u','r','n','e','d',' ','u','s',' ','a','l','l',' ','i','n','t','o',' ','p','u','m','p','k','i','n' + 0x80,
'p','e','o','p','l','e','.',' ','P','l','e','a','s','e',' ','h','e','l','p',' ','u','s',' ','d','e','f','e','a','t' + 0x80,
't','h','i','s',' ','c','r','a','z','y',' ','w','i','z','a','r','d','!' + 0x80,
'B','e',' ','s','u','r','e',' ','t','o',' ','e','q','u','i','p',' ','y','o','u','r','s','e','l','f' + 0x80,
'p','r','o','p','e','r','l','y','.',' ','Y','o','u',' ','c','a','n',' ','p','r','e','s','s',' ','"','$','%',' ','t','o' + 0x80,
'a','c','c','e','s','s',' ','y','o','u','r',' ','i','n','v','e','n','t','o','r','y',' ','a','n','d',' ','t','o' + 0x80,
'v','i','e','w',' ','i','n','f','o','r','m','a','t','i','o','n',' ','a','b','o','u','t',' ','y','o','u',' ','o','r' + 0x80,
'y','o','u','r',' ','e','n','e','m','i','e','s','.' + 0x80,
'I','n',' ','c','o','m','b','a','t',',',' ','c','a','s','t',' ','r','u','n','e','s',' ','t','o',' ','s','c','o','r','e' + 0x80,
'\'','p','o','k','e','r','\'',' ','h','a','n','d','s','.',' ','P','r','e','s','s','i','n','g',' ','"','#','%',' ','w','i','l','l' + 0x80,
'c','a','s','t',' ','t','h','e',' ','r','u','n','e','s',' ','-',' ','j','u','m','p',' ','a','n','d' + 0x80,
't','o','u','c','h',' ','r','u','n','e','s',' ','t','o',' ','s','e','l','e','c','t',' ','t','h','e','m' + 0x80,
'f','o','r',' ','r','e','c','a','s','t','i','n','g','.',' ','N','o','r','m','a','l','l','y',' ','y','o','u' + 0x80,
'c','a','n',' ','c','a','s','t',' ','3',' ','t','i','m','e','s',',',' ','b','u','t',' ','s','o','m','e' + 0x80,
'i','t','e','m','s',' ','m','i','g','h','t',' ','g','i','v','e',' ','y','o','u',' ','e','x','t','r','a','.' + 0x80,
'C','r','y','s','t','a','l',' ','H','e','l','m','e','t' + 0x80,
'H','i','g','h',' ','H','e','l','m','e','t' + 0x80,
'R','o','u','n','d',' ','H','e','l','m','e','t' + 0x80,
'F','i','r','e',' ','P','o','t','i','o','n' + 0x80,
'H','e','a','l','t','h',' ','P','o','t','i','o','n' + 0x80,
'S','p','e','e','d',' ','P','o','t','i','o','n' + 0x80,
'F','i','r','e',' ','B','l','a','z','e' + 0x80,
'H','e','a','l','i','n','g',' ','W','i','n','d' + 0x80,
'R','i','s','i','n','g',' ','S','t','a','r' + 0x80,
'V','e','n','o','m',' ','M','i','s','t' + 0x80,
'5',' ','F','i','r','e',' ','D','M','G' + 0x80,
'H','e','a','l',' ','2','0',' ','H','P' + 0x80,
'3','5',' ','D','a','m','a','g','e' + 0x80,
'2',' ','P','.',' ','D','M','G' + 0x80,
'a',' ','F','i','v','e',' ','o','f',' ','a',' ','K','i','n','d','!' + 0x80,
'a',' ','F','o','u','r',' ','o','f',' ','a',' ','K','i','n','d','!' + 0x80,
'a',' ','T','h','r','e','e',' ','o','f',' ','a',' ','K','i','n','d','!' + 0x80,
'T','w','o',' ','P','a','i','r','s','!' + 0x80,
'a',' ','F','u','l','l',' ','H','o','u','s','e','!' + 0x80,
};
