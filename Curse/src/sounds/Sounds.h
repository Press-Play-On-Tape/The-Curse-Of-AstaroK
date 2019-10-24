#include <ArduboyTones.h>

namespace Sounds {

  const uint16_t testSound[] PROGMEM = {
    NOTE_C4,50, NOTE_D4,50, NOTE_E4,50, 
    NOTE_C4,50, NOTE_D4,50, NOTE_E4,50, 
    NOTE_C4,50, NOTE_D4,50, NOTE_E4,50, 
    TONES_END
  };

  const uint16_t sound1[] PROGMEM = {
    NOTE_FS5, 2, NOTE_F6, 6, NOTE_GS6, 8, NOTE_F6, 4,
    TONES_END
  };

  const uint16_t sound2[] PROGMEM = {
    NOTE_F2,22, NOTE_F2,22, NOTE_F2,22,
    TONES_END
  };

  const uint16_t sound3[] PROGMEM = {
    NOTE_F3,22, NOTE_F3,22, NOTE_F3,22,
    TONES_END
  };

  const uint16_t sound4[] PROGMEM = {
    NOTE_F3,3, NOTE_D4,4, NOTE_A4,4, NOTE_E3,1, 
    TONES_END
  };

  const uint16_t sound5[] PROGMEM = {
    NOTE_A3,9, NOTE_D3,10, NOTE_C3,6, NOTE_F3,10, 
    TONES_END
  };

}
