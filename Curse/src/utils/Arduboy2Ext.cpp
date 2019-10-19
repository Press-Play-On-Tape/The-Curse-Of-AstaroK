#include "Arduboy2Ext.h"
#include "Enums.h"

Arduboy2Ext::Arduboy2Ext() : Arduboy2Base() { }

uint8_t Arduboy2Ext::justPressedButtons() const {

  return (~previousButtonState & currentButtonState);

}

uint8_t Arduboy2Ext::pressedButtons() const {

  return currentButtonState;

}

void Arduboy2Ext::clearButtonState() {

  currentButtonState = previousButtonState = 0;

}


void Arduboy2Ext::resetFrameCount() {

  frameCount = 0;

}

uint16_t Arduboy2Ext::getFrameCount() const {

  return frameCount;

}

uint8_t Arduboy2Ext::getFrameCount(uint8_t mod) const {

  return frameCount % mod;

}

bool Arduboy2Ext::getFrameCountHalf(uint8_t mod) const {

	return getFrameCount(mod) > (mod / 2);

}

bool Arduboy2Ext::isFrameCount(uint8_t mod) const {

  return (frameCount % mod) == 0;

}

bool Arduboy2Ext::isFrameCount(uint8_t mod, uint8_t val) const {

  return (frameCount % mod) == val;

}


void Arduboy2Ext::displayWithBackground(TimeOfDay timeOfDay) {

  display(true);

  if (timeOfDay == TimeOfDay::Day) {

      // memset(sBuffer, 0xff, 1024);
      for(size_t index = 0; index < 1024; ++index) sBuffer[index] = 0xFF;
      
  }

}


/* ----------------------------------------------------------------------------
 *  Draw a horizontal dotted line. 
 */
void Arduboy2Ext::drawHorizontalDottedLine(uint8_t x1, uint8_t x2, uint8_t y, uint8_t colour) {

	uint8_t diff = (x2 - x1);

	for (uint8_t x = 0; x <= diff; x += 2) {

		drawPixel(x1 + x, y, colour);

  }

}


/* ----------------------------------------------------------------------------
 *  Draw a vertical dotted line. 
 */
void Arduboy2Ext::drawVerticalDottedLine(uint8_t y1, uint8_t y2, uint8_t x, uint8_t colour) {

	uint8_t diff = (y2 - y1);

	for (uint8_t y = 0; y <= diff; y += 2) {

		drawPixel(x, y1 + y, colour);

  }
  
}


uint16_t rnd = 0xACE1;


uint8_t Arduboy2Ext::randomLFSR(uint8_t min, uint8_t max) {
  //see https://en.wikipedia.org/wiki/Linear-feedback_shift_register
  rnd ^= TCNT0; // add some extra timing randomness
  (rnd & 1) ? rnd = (rnd >> 1) ^ 0xB400 : rnd >> 1;
 return rnd % (max - min) + min;
}