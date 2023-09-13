#include "pitches.h"

int buzzerPin = 8;
boolean hasPlayed = false;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
	if (!hasPlayed) {
		playStarWars();
        hasPlayed = true;
    }
}

void playStarWars() {
	const int NUM_NOTES_STAR_WARS = 32;
	int imperialMarch[] = { G4,2,D5,2,C5,8,B4,8,A4,8,G5,2,D5,4,C5,8,B4,8,A4,8,G5,2,D5,4,C5,8,B4,8,C5,8,A4,2 };
	playTune(imperialMarch, NUM_NOTES_STAR_WARS);
}

void playTune(int melody[], int numNotes) {
    for (int i = 0; i < numNotes; i++) {
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / melody[i + 1];
        tone(buzzerPin, melody[i], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(buzzerPin);
    }
}