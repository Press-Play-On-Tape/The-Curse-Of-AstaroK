#pragma once

// Imported 87 messages from "messages.h"

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
constexpr uint8_t Astarok_Name_Idx = 32;
constexpr uint8_t Tombstone_Inscription_00_Idx = 33;
constexpr uint8_t Tombstone_Inscription_01_Idx = 34;
constexpr uint8_t Tombstone_Inscription_02_Idx = 35;
constexpr uint8_t Dialogue_00_Idx = 36;
constexpr uint8_t Dialogue_01_Idx = 37;
constexpr uint8_t Dialogue_02_Idx = 38;
constexpr uint8_t Dialogue_03_Idx = 39;
constexpr uint8_t Dialogue_04_Idx = 40;
constexpr uint8_t Dialogue_05_Idx = 41;
constexpr uint8_t Dialogue_06_Idx = 42;
constexpr uint8_t Dialogue_07_Idx = 43;
constexpr uint8_t Dialogue_08_Idx = 44;
constexpr uint8_t Dialogue_09_Idx = 45;
constexpr uint8_t Dialogue_10_Idx = 46;
constexpr uint8_t Dialogue_11_Idx = 47;
constexpr uint8_t Dialogue_12_Idx = 48;
constexpr uint8_t Dialogue_13_Idx = 49;
constexpr uint8_t Dialogue_14_Idx = 50;
constexpr uint8_t Dialogue_15_Idx = 51;
constexpr uint8_t Dialogue_16_Idx = 52;
constexpr uint8_t PlayerItems_Caption00_Idx = 53;
constexpr uint8_t PlayerItems_Caption01_Idx = 54;
constexpr uint8_t PlayerItems_Caption02_Idx = 55;
constexpr uint8_t PlayerItems_Caption03_Idx = 56;
constexpr uint8_t PlayerItems_Caption04_Idx = 57;
constexpr uint8_t PlayerItems_Caption05_Idx = 58;
constexpr uint8_t RuneCombination_Purchased_Caption00_Idx = 59;
constexpr uint8_t RuneCombination_Purchased_Caption01_Idx = 60;
constexpr uint8_t RuneCombination_Purchased_Caption02_Idx = 61;
constexpr uint8_t RuneCombination_Purchased_Caption03_Idx = 62;
constexpr uint8_t Rune_Effect_Caption00_Idx = 63;
constexpr uint8_t Rune_Effect_Caption01_Idx = 64;
constexpr uint8_t Rune_Effect_Caption02_Idx = 65;
constexpr uint8_t Rune_Effect_Caption03_Idx = 66;
constexpr uint8_t RuneCombination_Standard_51_Idx = 67;
constexpr uint8_t RuneCombination_Standard_52_Idx = 68;
constexpr uint8_t RuneCombination_Standard_53_Idx = 69;
constexpr uint8_t RuneCombination_Standard_54_Idx = 70;
constexpr uint8_t RuneCombination_Standard_55_Idx = 71;
constexpr uint8_t Pickup_HP_Idx = 72;
constexpr uint8_t Thank_You_Idx = 73;
constexpr uint8_t Overwrite_Confirm_Idx = 74;
constexpr uint8_t New_Game_Confirm_Idx = 75;
constexpr uint8_t Game_Restored_Idx = 76;
constexpr uint8_t Same_Helmet_Idx = 77;
constexpr uint8_t Max_Potions_Idx = 78;
constexpr uint8_t Buy_Item_Idx = 79;
constexpr uint8_t No_GP_Idx = 80;
constexpr uint8_t Same_Rune_Idx = 81;
constexpr uint8_t Buy_Rune_Idx = 82;
constexpr uint8_t No_SP_Idx = 83;
constexpr uint8_t Monster_Attack_Idx = 84;
constexpr uint8_t Throw_Again_Idx = 85;
constexpr uint8_t Game_Saved_Idx = 86;

const uint8_t keywords[] PROGMEM = {
'n','v','e','n','t','o','r','y' + 0x80
'o','f',' ','a',' ','K','i','n','d' + 0x80
'k','i','l','l' + 0x80
'H','e','a','l','t','h' + 0x80
'D','e','f','e','n','c','e' + 0x80
'G','a','m','e' + 0x80
'Y','o','u' + 0x80
'p','t','s' + 0x80
'd','a','m','a','g','e' + 0x80
'e','x','t','r','a' + 0x80
'p','o','i','n','t','s' + 0x80
'A','s','t','a','r','o','K' + 0x80
's','t','o','l','e' + 0x80
'T','h','e' + 0x80
'r','u','n','e' + 0x80
'f','r','o','m' + 0x80
'y','o','u' + 0x80
'a','n','d' + 0x80
't','h','e' + 0x80
'g','o','l','d' + 0x80
's','k','i','l','l' + 0x80
'y','o','u','r' + 0x80
'c','a','s','t' + 0x80
'B','o','r','n' + 0x80
'D','e','c' + 0x80
't','h','i','s' + 0x80
'c','a','n' + 0x80
'r','u','n','e','s' + 0x80
'f','o','r' + 0x80
's','o','m','e' + 0x80
'H','e','l','m','e','t' + 0x80
'F','i','r','e' + 0x80
'P','o','t','i','o','n' + 0x80
'D','M','G' + 0x80
'K','i','n','d' + 0x80
'g','a','m','e' + 0x80
'Y','e','s' + 0x80
's','t','a','t','e' + 0x80
'a','l','r','e','a','d','y' + 0x80
'h','a','v','e' + 0x80
'o','n','e' + 0x80
't','h','o','s','e' + 0x80
'B','u','y' + 0x80
'n','o','t' + 0x80
'e','n','o','u','g','h' + 0x80
};


const uint8_t messages[] PROGMEM = {
' ','I',129,
' ','x',' ' + 0x80,
'S','t','a','t','i','s','t','i','c','s' + 0x80,
132,' ',':','\n','S',131,' ',':','\n',133,' ',':','\n','G','o','l','d',' ',':','\n','D','u','n','g','e','o','n','s',' ',':' + 0x80,
' ',' ',' ',' ','R','u','n','e','s' + 0x80,
' ','E','n','e','m','y',' ','S','t','s' + 0x80,
'N','a','m','e',':','\n',132,' ',':','\n',133,' ',':','\n' + 0x80,
'S','a','v','e',' ',134,'\n','N','e','w',' ',134,'\n' + 0x80,
'R','e','s','t','o','r','e',' ',134,
'a',' ' + 0x80,
172,'h','i','n','g','!' + 0x80,
135,' ','i','n','f','l','i','c','t','e','d',' ' + 0x80,
' ',136,' ','o','f',' ',137,'.' + 0x80,
'P','l','u','s',' ','a','n',' ',138,' ' + 0x80,
135,' ','r','e','g','a','i','n','e','d',' ' + 0x80,
' ','h','e','a','l','t','h',' ',139,'.' + 0x80,
' ',' ',140,' ',141,' ' + 0x80,
' ','h','p',' ',139,'.' + 0x80,
' ','a','t','t','a','c','k','s',',',' ' + 0x80,
' ',137,' ',136,'.' + 0x80,
142,' ','G','e','l','a','t','i','n','o','u','s',' ','C','u','b','e',' ',141,' ','a','\n',' ',' ',' ' + 0x80,
' ',143,
' ',144,' ',145,'!' + 0x80,
' ',135,' ',131,'e','d',' ',140,' ',146,' ','f','r','e','e','d','\n',147,' ','v','i','l','l','a','g','e','r','s',' ',144,' ',147,' ','c','u','r','s','e','!' + 0x80,
135,' ','s','c','o','r','e','d',' ' + 0x80,
' ',148,' ','c','o','i','n','s','.' + 0x80,
' ','s',131,' ',139,'.' + 0x80,
135,' ','d','i','e','d','!',' ','L','o','s','e',' ','h','a','l','f',' ','o','f',' ',145,'r','\n',' ',' ',' ',' ',' ',' ',148,' ',146,' ','s',131,' ',139,'!' + 0x80,
'G','P' + 0x80,
'S','P' + 0x80,
135,' ',151,' ' + 0x80,
'N',169,' ','!' + 0x80,
'A','S','T','A','R','O','K' + 0x80,
' ',' ',' ','H','e','r','e',' ','l','i','e','s',' ','V','a','m','p','i','r','i','c','s','.','\n',' ',' ',152,' ','1','8','4','3',' ','-',' ',153,' ','1','8','8','2' + 0x80,
' ','R','e','s','t',' ','I','n',' ','P','e','a','c','e',' ','F','i','l','m','o','t','e','.','\n',' ',' ',152,' ','1','8','4','1',' ','-',' ',153,' ','1','8','7','9' + 0x80,
' ',' ',' ','P','r','e','s','s',' ','P','l','a','y',' ','O','n',' ','T','a','p','e','\n',' ',' ',' ',' ',' ','D','e','v','e','l','o','p','e','d',' ','2','0','1','9' + 0x80,
'W','e','l','c','o','m','e',' ','t','r','a','v','e','l','l','e','r',' ','t','o',' ',147,' ','t','o','w','n' + 0x80,
'o','f',' ','G','r','i',157,'d','.',' ',142,' ','e','v','i','l',' ',140,
'h','a','s',' ','t','u','r','n','e','d',' ','u','s',' ','a','l','l',' ','i','n','t','o',' ','p','u','m','p','k','i','n' + 0x80,
'p','e','o','p','l','e','.',' ','P','l','e','a','s','e',' ','h','e','l','p',' ','u','s',' ','d','e','f','e','a','t' + 0x80,
154,' ','c','r','a','z','y',' ','w','i','z','a','r','d','!' + 0x80,
'B','e',' ','s','u','r','e',' ','t','o',' ','e','q','u','i','p',' ',145,'r','s','e','l','f' + 0x80,
'p','r','o','p','e','r','l','y','.',' ',135,' ',155,' ','p','r','e','s','s',' ','"','$','%',' ','t','o' + 0x80,
'a','c','c','e','s','s',' ',145,'r',' ','i',129,' ',146,' ','t','o' + 0x80,
'v','i','e','w',' ','i','n',157,'m','a','t','i','o','n',' ','a','b','o','u','t',' ',145,' ','o','r' + 0x80,
145,'r',' ','e','n','e','m','i','e','s','.' + 0x80,
'I','n',' ','c','o','m','b','a','t',',',' ',151,' ',143,'s',' ','t','o',' ','s','c','o','r','e' + 0x80,
'\'','p','o','k','e','r','\'',' ','h',146,'s','.',' ','P','r','e','s','s','i','n','g',' ','"','#','%',' ','w','i','l','l' + 0x80,
151,' ',147,' ',143,'s',' ','-',' ','j','u','m','p',' ',146,
't','o','u','c','h',' ',143,'s',' ','t','o',' ','s','e','l','e','c','t',' ',147,'m' + 0x80,
157,' ','r','e',151,'i','n','g','.',' ','N','o','r','m','a','l','l','y',' ',145,
155,' ',151,' ','3',' ','t','i','m','e','s',',',' ','b','u','t',' ',158,
'i','t','e','m','s',' ','m','i','g','h','t',' ','g','i','v','e',' ',145,' ',138,'.' + 0x80,
'C','r','y','s','t','a','l',' ',159,
'H','i','g','h',' ',159,
'R','o','u','n','d',' ',159,
160,' ',161,
132,' ',161,
'S','p','e','e','d',' ',161,
160,' ','B','l','a','z','e' + 0x80,
'H','e','a','l','i','n','g',' ','W','i','n','d' + 0x80,
'R','i','s','i','n','g',' ','S','t','a','r' + 0x80,
'V','e','n','o','m',' ','M','i','s','t' + 0x80,
'5',' ',160,' ',162,
'H','e','a','l',' ','2','0',' ','H','P' + 0x80,
'3','5',' ','D','a','m','a','g','e' + 0x80,
'2',' ','P','.',' ',162,
'a',' ','F','i','v','e',' ',130,'!' + 0x80,
'a',' ','F','o','u','r',' ',130,'!' + 0x80,
'a',' ','T','h','r','e','e',' ',130,'!' + 0x80,
'T','w','o',' ','P','a','i','r','s','!' + 0x80,
'a',' ','F','u','l','l',' ','H','o','u','s','e','!' + 0x80,
135,' ','p','i','c','k','e','d',' ','u','p',' ',158,' ','H','P','!' + 0x80,
' ',' ',' ',' ','T','h','a','n','k',' ',145,' ',157,' ','s','a','v','i','n','g','\n',' ',' ',' ',' ',' ',' ','u','s',' ',144,' ',147,' ','C','u','r','s','e','!' + 0x80,
' ','O','v','e','r','w','r','i','t','e',' ','e','x','i','s','t','i','n','g',' ',164,'?','\n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','"','#','%',' ',165,' ',' ',' ',' ','"','$','%',' ','N','o' + 0x80,
' ',' ','S','t','a','r','t',' ','a',' ','n','e','w',' ',164,'?','\n',' ',' ',' ',' ',' ','"','#','%',' ',165,' ',' ',' ',' ','"','$','%',' ','N','o' + 0x80,
' ',' ',134,' ',166,' ','r','e','s','t','o','r','e','d','!' + 0x80,
' ',' ',' ',' ',135,' ',167,' ',168,'\n',' ',169,' ','o','f',' ',170,' ','h','e','l','m','e','t','s','!' + 0x80,
' ',' ',135,' ',167,' ',168,' ','a','s','\n','m','a','n','y',' ','o','f',' ',147,'s','e',' ','p','o','t','i','o','n','s','\n',' ',' ','a','s',' ',145,' ',155,' ','c','a','r','r','y',' ','!' + 0x80,
' ',' ',' ',171,' ',154,' ','i','t','e','m','?','\n',' ',' ',' ','"','#','%',' ',165,' ',' ',' ',' ','"','$','%',' ','N','o' + 0x80,
135,' ','d','o',' ',172,' ',168,'\n',' ',' ',' ',173,' ',148,'!' + 0x80,
' ',' ',' ',135,' ','a','r','e',' ','c','a','r','r','y','i','n','g','\n',' ',169,' ','o','f',' ',170,' ',143,'s','!' + 0x80,
' ',' ',171,' ',154,' ',143,'?','\n',' ',' ','"','#','%',' ',165,' ',' ',' ',' ','"','$','%',' ','N','o' + 0x80,
' ',135,' ','d','o',' ',172,' ',168,'\n',' ',' ',' ',' ',173,' ','S','P','!' + 0x80,
' ',' ',' ',' ',' ',' ',' ',' ','A',' ','m','o','n','s','t','e','r',' ','a','t','t','a','c','k','s',' ',145,'!' + 0x80,
'T','h','r','o','w',' ',147,' ',143,'s',' ','a','g','a','i','n','!' + 0x80,
' ',' ',134,' ',166,' ','s','a','v','e','d','!' + 0x80,
};
