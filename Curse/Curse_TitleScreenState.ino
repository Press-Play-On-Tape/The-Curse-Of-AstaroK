#include "src/utils/Arduboy2Ext.h"


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void titleScreen_Activate() {

	memset(&titleScreenVars, 0, 2);

	#ifdef SOUNDS_ENABLED
	sound.tones(Sounds::testSound);
	#endif

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void titleScreen_Update() {

  auto justPressed = arduboy.justPressedButtons();
  auto pressed = arduboy.pressedButtons();


	// Handle sound counter ..
	
	if (titleScreenVars.soundCounter > 0) titleScreenVars.soundCounter--;


	// Restart ?

	if (pressed & DOWN_BUTTON) {

		if (titleScreenVars.restart < UPLOAD_DELAY) {
			titleScreenVars.restart++;
		}
		else {
			arduboy.exitToBootloader();
		}

	}
	else {
		titleScreenVars.restart = 0;
	}


	// Update counter ..

	#ifndef SPLASH_SCREEN
	if (titleScreenVars.counter < 140) titleScreenVars.counter++;
	#else
	if (titleScreenVars.counter < 32) titleScreenVars.counter++;
	#endif


	// Handle other input ..

	#ifndef SPLASH_SCREEN
	if (justPressed & A_BUTTON) {
		if (titleScreenVars.counter <= 70) {
			titleScreenVars.counter = 71;
		}
		else {
			gameState = GameStateType::PlayGame_Activate; 
		}
	}
	#else
	if (justPressed & A_BUTTON) {
		gameState = GameStateType::PlayGame_Activate; 
	}
	#endif


	// Toggle sound ..

	if ((pressed & B_BUTTON) && (justPressed & UP_BUTTON || justPressed & DOWN_BUTTON)) {
		titleScreenVars.soundIndex = titleScreen_ToggleSoundSettings();
		titleScreenVars.soundCounter = 40;
	}

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void titleScreen_Render() {

	#ifndef SPLASH_SCREEN

	switch (titleScreenVars.counter) {

		case 0 ... 70:
			font3x6.setCursor(32, 21);
			font3x6.print("Press Play On Tape");
			font3x6.setCursor(49, 33);
			font3x6.print("presents");
			break;

		case 71 ... 140:
			ardBitmap.drawCompressed(0, 6, Images::TitleScreen, WHITE, MIRROR_NONE);
			if (titleScreenVars.counter == 140) ardBitmap.drawCompressed(48, 53, Images::TitleScreen_PressA, WHITE, MIRROR_NONE);
			break;

	}

	#else

		ardBitmap.drawCompressed(0, 6, Images::TitleScreen, WHITE, MIRROR_NONE);
		if (titleScreenVars.counter == 32) ardBitmap.drawCompressed(48, 53, Images::TitleScreen_PressA, WHITE, MIRROR_NONE);
		
	#endif

	if (titleScreenVars.soundCounter > 0) { SpritesB::drawOverwrite(120, 56, Images::Sounds, titleScreenVars.soundIndex); }
	arduboy.display(true);
	
} 


/* ----------------------------------------------------------------------------
 *  Toggle the sound setting and commit to the EEPROM.
 */
uint8_t titleScreen_ToggleSoundSettings() {

	uint8_t index = 0;

  if (arduboy.audio.enabled()) {
  
    arduboy.audio.off(); 
		index = 0;
  
  }
  else {
  
    arduboy.audio.on(); 
		index = 1;
  
  }

  arduboy.audio.saveOnOff();

	return index;
    
}