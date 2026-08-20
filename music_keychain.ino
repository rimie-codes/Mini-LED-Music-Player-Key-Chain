#include <BleKeyboard.h>

BleKeyboard bleKeyboard("LED Music Keychain");

const int previousButton = 25;
const int playButton = 26;
const int nextButton = 27;

void setup() {
  pinMode(previousButton, INPUT_PULLUP);
  pinMode(playButton, INPUT_PULLUP);
  pinMode(nextButton, INPUT_PULLUP);

  bleKeyboard.begin();
}

void loop() {

  if (bleKeyboard.isConnected()) {

    if (digitalRead(previousButton) == LOW) {
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
      delay(400);
    }

    if (digitalRead(playButton) == LOW) {
      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
      delay(400);
    }

    if (digitalRead(nextButton) == LOW) {
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
      delay(400);
    }
  }
}
