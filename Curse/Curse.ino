#include "src/utils/Arduboy2Ext.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x6.h"
#include "src/images/Images.h"
#include "src/utils/Utils.h"
#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "src/utils/Structs.h"
#include "src/utils/FadeEffects.h"
#include "src/utils/FlashStringHelper.h"
#include "src/ardBitmap/ArdBitmap.h"
#include <ArduboyTones.h>

#ifndef DEBUG
ARDUBOY_NO_USB
#endif

// 542 bytes
#define SPLASH_SCREEN

FadeInEffect fadeInEffect;
Arduboy2Ext arduboy;
ArdBitmap<WIDTH, HEIGHT> ardBitmap;
Font3x6 font3x6;
ArduboyTones sound(arduboy.audio.enabled);

#ifdef SPLASH_SCREEN
GameStateType gameState = GameStateType::SplashScreen_Activate; 
#else
GameStateType gameState = GameStateType::TitleScreen_Activate; 
#endif

SplashScreenStateVars splashScreenVars;
TitleScreenStateVars titleScreenVars;
PlayGameStateVars playGameVars;
GameOverStateVars gameOverVars;

const uint16_t testSound[] PROGMEM = {
  NOTE_C4,50, NOTE_D4,50, NOTE_E4,50, 
  NOTE_C4,50, NOTE_D4,50, NOTE_E4,50, 
  NOTE_C4,50, NOTE_D4,50, NOTE_E4,50, 
  TONES_END
};

void setup() {

	arduboy.boot();
	arduboy.setFrameRate(40);
	arduboy.audio.begin();

}

void loop() {

	if (!arduboy.nextFrame()) return;
	arduboy.pollButtons();

	switch (gameState) {

		#ifdef SPLASH_SCREEN

			case GameStateType::SplashScreen_Activate:
				splashScreen_Activate();
				gameState = GameStateType::SplashScreen;
				[[fallthrough]];

			case GameStateType::SplashScreen:
				splashScreen_Update();
				splashScreen_Render();
				break;

		#endif

		case GameStateType::TitleScreen_Activate:
			titleScreen_Activate();
			gameState = GameStateType::TitleScreen;
			[[fallthrough]];

		case GameStateType::TitleScreen:
			titleScreen_Update();
			titleScreen_Render();
			break;

		case GameStateType::PlayGame_Activate:
			playGame_Activate();
			gameState = GameStateType::PlayGame;
			[[fallthrough]];

		case GameStateType::PlayGame:
			playGame_Update();
			playGame_Render();
			break;

		default: break;

	}

}
