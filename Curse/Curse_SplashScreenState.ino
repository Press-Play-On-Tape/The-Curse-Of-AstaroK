#include "src/utils/Arduboy2Ext.h"

// ----------------------------------------------------------------------------
//  Initialise state ..
//
void splashScreen_Activate() {

  splashScreenVars.counter = 0;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void splashScreen_Update() { 

  auto justPressed = arduboy.justPressedButtons();

  if (justPressed > 0) {
      
      gameState = GameStateType::TitleScreen_Activate;

  }

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void splashScreen_Render() {


    Sprites::drawOverwrite(32, 17, Images::PPOT, 0);

    uint8_t y = 17; 
    switch (arduboy.getFrameCount(48)) {

        case 12 ... 23:
            y = 30; 
            [[fallthrough]]

        case 0 ... 11:
            Sprites::drawOverwrite(91, 25, Images::PPOT_Arrow, 0);
            break;

        case 24 ... 35:
            y = 31; 
            break;

        default: // 36 ... 47:
            y = 32; 
            break;

    }

    arduboy.drawPixel(52, y, WHITE); // Falling pixel represents the tape spooling
    if (y % 2 == 0) { // On even steps of pixel movement, update the spindle image
        Sprites::drawOverwrite(45, 28, Images::PPOT_Spindle, 0);
    }

  arduboy.display(true);

}