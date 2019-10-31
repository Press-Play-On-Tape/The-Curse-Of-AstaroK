#include <Arduino.h>
#include <Sprites.h>
#include <Print.h>
#include "Font3x6.h"

#define FONT3X6_WIDTH 3
#define FONT3X6_HEIGHT 6

#define CHAR_SPACE 32
#define CHAR_EXCLAMATION 33
#define CHAR_QUOTE 39
#define CHAR_PERIOD 46
#define CHAR_DASH 45
#define CHAR_PLUS 43
#define CHAR_QUESTION 63
#define CHAR_COLON 58
#define CHAR_AT 64
#define CHAR_COMMA 44
#define CHAR_LETTER_A 65
#define CHAR_LETTER_Z 90
#define CHAR_LETTER_A_LOWER 97
#define CHAR_LETTER_Z_LOWER 122
#define CHAR_NUMBER_0 48
#define CHAR_NUMBER_9 57

#define FONT_EXCLAMATION_INDEX 62
#define FONT_PERIOD_INDEX 63
#define FONT_DASH_INDEX 64
#define FONT_PLUS_INDEX 65
#define FONT_QUESTION_INDEX 66
#define FONT_COLON_INDEX 67
#define FONT_AT_INDEX 68
#define FONT_COMMA_INDEX 69
#define FONT_QUOTE_INDEX 70
#define FONT_NUMBER_INDEX 52

const uint8_t PROGMEM font_images[] = {
  3, 8,
  0x00, 0x00, 0x00,  // SPACE
  0x00, 0x2F, 0x00,  // !
  
  0x00, 0x3c, 0x7e,  // " button (
  0xc3, 0xf5, 0xc3,  // # button A
  0x81, 0xb5, 0xcb,  // $ button B
  0x7e, 0x3c, 0x00,  // % button )
  
  0x00, 0x00, 0x00,  // &
  
  0x03, 0x00, 0x00,  // '
  
  0x00, 0x00, 0x00,  // (
  0x00, 0x00, 0x00,  // )
  0x00, 0x00, 0x00,  // *
  
  0x08, 0x1C, 0x08,  // +
  0x40, 0x20, 0x00,  // ,
  0x08, 0x08, 0x08,  // -
  0x00, 0x20, 0x00,  // .
  0x00, 0x00, 0x00,  // /

  0x3f, 0x21, 0x3f,  // 0
  0x22, 0x3f, 0x20, 
  0x33, 0x29, 0x27, 
  0x23, 0x29, 0x37, 
  0x1e, 0x11, 0x3f, 
  0x37, 0x25, 0x3d, 
  0x3f, 0x25, 0x3d, 
  0x39, 0x05, 0x03, 
  0x3f, 0x25, 0x3f, 
  0x07, 0x05, 0x3f,  // 9

  0x14, 0x00, 0x00,  // :
  
  0x00, 0x00, 0x00,  // ;
  0x00, 0x00, 0x00,  // <
  0x00, 0x00, 0x00,  // =
  0x00, 0x00, 0x00,  // >
  
  0x02, 0x29, 0x06,  // ?
  0x20, 0x00, 0x20,  // @
  0x3c, 0x0b, 0x3c,  // A
  0x3f, 0x25, 0x3b,
  0x3f, 0x21, 0x33,
  0x3f, 0x21, 0x3e,
  0x3f, 0x25, 0x21,
  0x3f, 0x05, 0x01,
  0x3f, 0x21, 0x3b,
  0x3f, 0x04, 0x3f,
  0x3f, 0x00, 0x00,  //I
  0x30, 0x20, 0x3f,
  0x3f, 0x04, 0x3b,
  0x3f, 0x20, 0x00,  //l
  0x3f, 0x0e, 0x3f,
  0x3f, 0x02, 0x3f,
  0x3f, 0x21, 0x3f,
  0x3f, 0x09, 0x0f,
  0x1f, 0x11, 0x3f,
  0x3f, 0x05, 0x3b,
  0x37, 0x2d, 0x3b,
  0x01, 0x3f, 0x01,
  0x3f, 0x20, 0x3f,
  0x0f, 0x30, 0x0f,
  0x3f, 0x18, 0x3f,
  0x33, 0x0c, 0x33,
  0x03, 0x3c, 0x03,
  0x31, 0x2d, 0x23,  // Z

  //0x00, 0x00, 0x00,  // [
  //0x00, 0x00, 0x00,  // 
  //0x00, 0x00, 0x00,  // ]
  //0x00, 0x00, 0x00,  // ^
  //
  //0x00, 0x00, 0x00,  // _
  //0x00, 0x00, 0x00,  // `

  0x18, 0x24, 0x3C, // a
  0x3E, 0x24, 0x18,
  0x3C, 0x24, 0x24,
  0x18, 0x24, 0x3E,
  0x18, 0x34, 0x28,
  0x08, 0x3E, 0x0A,
  0x5C, 0x54, 0x3C,
  0x3E, 0x04, 0x38,
  0x3A, 0x00, 0x00,  //i
  0x40, 0x3A, 0x00,
  0x3E, 0x08, 0x34,
  0x02, 0x3E, 0x00,  //l
  0x3C, 0x08, 0x3C,
  0x3C, 0x04, 0x3C,
  0x3C, 0x24, 0x3C,
  0x7C, 0x24, 0x18,
  0x18, 0x24, 0x7C,
  0x3C, 0x04, 0x0C,
  0x28, 0x24, 0x14,
  0x04, 0x1E, 0x24,
  0x3C, 0x20, 0x3C,
  0x1C, 0x20, 0x1C,
  0x3C, 0x10, 0x3C,
  0x34, 0x08, 0x34,
  0x5C, 0x50, 0x3C,
  0x34, 0x24, 0x2C,  // z

};

Font3x6::Font3x6(uint8_t lineHeight) {

  _lineHeight = lineHeight;
  _letterSpacing = 1;

  _cursorX = _cursorY = _baseX = 0;
  _textColor = WHITE;

}

void Font3x6::print(char c)
{
  write(c);
}

void Font3x6::print(char *str)
{
  while (*str) write(*str++);
}

void Font3x6::print(const __FlashStringHelper *str)
{
  const uint8_t *p = reinterpret_cast<const uint8_t *>(str);
  while (1) {
    unsigned char c = pgm_read_byte(p++);
    if (c == 0) break;
    write(c);
  }
}

void Font3x6::printMessage(uint8_t idx)
{
  this->printMessage(idx, messages, true);
}


void Font3x6::printMessage(uint8_t idx, const uint8_t *messagesArray, bool eighty) {

  const uint8_t *p = messagesArray;
  while (idx) {
    while(1) {  
      uint8_t c = pgm_read_byte(p) ;
      ++p;
      if (eighty && c == 0x80) break;
      if (!eighty && (c & 0x80) > 0) break;
    }
    --idx;
  }
  while (1) {
    uint8_t c = pgm_read_byte(p);
    if ((eighty && c == 0x80) || (!eighty && (c & 0x80) > 0)) {
      if (!eighty) write(c & 0x7f);
      break;
    } 
    else if (c >= 0x80) {
      this->printMessage( (c & 0x7f) - 1, keywords, false);
    }
    else  {
      write(c);
    }
    ++p;
  }
}

void Font3x6::printNumber(uint8_t n)
{
  char buf[4];
  char *str = &buf[sizeof(buf) - 1];
  *str = '\0';
  do {
    char c = n % 10;
    n /= 10;
    *--str = c + '0';
  } while(n);
   print(str);
}

void Font3x6::printNumberln(uint8_t n)
{
  printNumber(n);
  print(static_cast<uint8_t>('\n'));
}

void Font3x6::write(uint8_t c) {
  c &= 0x7F;//Strip terminator bit  
  if (c == '\n')     {
    _cursorX = _baseX;
    _cursorY += _lineHeight;
  }
  else {
    printChar(c, _cursorX, _cursorY);
    if (c == ' ' || c == 'i' || c == 'I' || c == '\'') {
      _cursorX += 2;
    }
    else if ((c >= '"' && c <='%') || c == 'l' || c == 'L') {
      _cursorX += 3;
    }
    else {
      _cursorX += FONT3X6_WIDTH + _letterSpacing;
    }
  }
}

void Font3x6::printChar(const char c, const int8_t x, int8_t y) {

  int8_t idx = c - CHAR_SPACE;
  if (c >= CHAR_LETTER_A_LOWER) {
    idx -= CHAR_LETTER_A_LOWER - CHAR_LETTER_Z - 1;
  }
  ++y;
  if (_textColor == WHITE) {
    SpritesB::drawSelfMasked(x, y, font_images, idx);
  }
  else {
    SpritesB::drawErase(x, y, font_images, idx);
  }
}

void Font3x6::setCursor(const int8_t x, const int8_t y) {
  _cursorX = x;
  _baseX = x;
  _cursorY = y;
}

void Font3x6::setTextColor(const uint8_t color) {
  _textColor = color;
}

void Font3x6::setHeight(const uint8_t lineHeight) {
  _lineHeight = lineHeight;
}
