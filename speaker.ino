#include "mega2560_pinout.h"
#include <SD.h>
#include <TMRpcm.h>

#define SD_ChipSelectPin MICRO_SD_CS_PIN
#define speakrPin DP05

TMRpcm audio;
void setup() {
  int i = 0;
  Serial.begin(9600);
  pinMode(speakrPin, OUTPUT);

  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD card not found");
    return;
  }

  audio.speakerPin = speakrPin;

  File root = SD.open("/");

  Serial.println("Playable audio files found on SD card:");

  while (i == 0) {
    File entry = root.openNextFile();

    if (!entry) {
      break;
    }

    if (String(entry.name()).endsWith(".WAV")) {
      Serial.println("Playing audio: " + String(entry.name()));
      audio.play(entry.name());
      Serial.println(entry.name());
      i = 1;
    }
  }
}
  void loop() {
  }
