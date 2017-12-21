/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int treb[] = {NOTE_00, NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3};
int melody[] = {3, 4, 2, 3, 4, 2, 0, 3, 4, 2, 1, 4, 3};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
float noteDurations[] = {
  .125, .125, .5, .375, .125, .5, .375, .125, .125, .25, .5, .25, .5
};

void setup() {
  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 13; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 * noteDurations[thisNote];
    tone(9, treb[melody[thisNote]], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(9);
  }

}

void loop() {
  // no need to repeat the melody.
}
