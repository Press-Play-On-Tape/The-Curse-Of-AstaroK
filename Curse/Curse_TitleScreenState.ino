#include "src/utils/Arduboy2Ext.h"


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void titleScreen_Activate() {

	memset(&titleScreenVars, 0, 2);

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void titleScreen_Update() {

  auto justPressed = arduboy.justPressedButtons();
  auto pressed = arduboy.pressedButtons();


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

	arduboy.display(true);
	
} 
