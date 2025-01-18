#include "mega2560_pinout.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define BUTTON1PIN DP02
#define BUTTON2PIN DP03
#define BUTTON3PIN DP04
#define STARTPIN DP05

#define OLED_Address 0x3C //initialize with the I2C addr 0x3C
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
#define TCAADDR 0x70
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int current_time = 0;
int begin_time = -1000;
int pcchoice = 0;
int startshit = 0; //waiting

enum class choices {undefined = -1, rock = 0, paper = 1, scissors = 2};
enum class states {playerChoise = 0, displayResult = 1};

choices choice = choices::undefined;
states currentState = states::playerChoise;

struct buttons {
  bool btn1;
  bool btn1_last;
  bool btn2;
  bool btn2_last;
  bool btn3;
  bool btn3_last;
};

buttons buttonState = {false, false, false, false, false, false};

choices converter(struct buttons buttonState) {
  if (buttonState.btn1 && !buttonState.btn2 && !buttonState.btn3) {
    return choices::rock;
  }
  if (!buttonState.btn1 && buttonState.btn2 && !buttonState.btn3) {
    return choices::paper;
  }
  if (!buttonState.btn1 && !buttonState.btn2 && buttonState.btn3) {
    return choices::scissors;
  }
  return choices::undefined;
}
void printd (String a) {
  display.setTextSize(1, 2);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println(a);
  display.display();
}

void readPins() {
  randomSeed(analogRead(0));
  buttonState.btn1 = !digitalRead(BUTTON1PIN); //add ! later
  buttonState.btn2 = !digitalRead(BUTTON2PIN);
  buttonState.btn3 = !digitalRead(BUTTON3PIN);

  if (buttonState.btn1 != buttonState.btn1_last && buttonState.btn1 == true) {
    choice = choices::rock;
    begin_time = millis();
  }
  if (buttonState.btn2 != buttonState.btn2_last && buttonState.btn2 == true) {
    choice = choices::paper;
    begin_time = millis();
  }
  if (buttonState.btn3 != buttonState.btn3_last && buttonState.btn3 == true) {
    choice = choices::scissors;
    begin_time = millis();
  }
  buttonState.btn1_last = buttonState.btn1;
  buttonState.btn2_last = buttonState.btn2;
  buttonState.btn3_last = buttonState.btn3;
}

void I2C_MUX_Channel_Select(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void setup() {
  Wire.begin();
  I2C_MUX_Channel_Select(1);
  delay(250);
  if (!display.begin(OLED_Address, true)) { // Address 0x3C default
    return;
  }
  display.display();
  display.clearDisplay();
  delay(1);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  Serial.begin(9600);
  pinMode(BUTTON1PIN, INPUT_PULLUP); //Rock
  pinMode(BUTTON2PIN, INPUT_PULLUP); //Paper
  pinMode(BUTTON3PIN, INPUT_PULLUP); //Scissors
  pinMode(STARTPIN, INPUT_PULLUP);
  printd("Press START");
}

void loop() {
  if (startshit == 0) {
    if (!digitalRead(STARTPIN) == HIGH) {
      startshit = 1;
      printd("Waiting for user choice");
    }
  }
  else {
    pcchoice = random(1, 100);
    current_time = millis() - begin_time;
    if (current_time >= 200) {
      readPins();
    }
    if (choice != choices::undefined) {
      Serial.print((int)choice);
      Serial.print(" -> ");
      Serial.println(millis());
      Serial.println(pcchoice);
    }
    if (pcchoice < 33 && choice != choices::undefined) { //rock
      if (choice == choices::paper) {
        Serial.println("The bot chose rock, You win");
        printd("The bot chose rock, You win");
      }
      else if (choice == choices::scissors) {
        Serial.println("The bot chose rock, You lost");
        printd("The bot chose rock, You lost");
      }
      else if (choice == choices::rock) {
        Serial.println("The bot chose rock, You draw");
        printd("The bot chose rock, You draw");
      }
      startshit = 0;
      choice = choices::undefined;
    }
    else if (pcchoice >= 33 && pcchoice < 66 && choice != choices::undefined) { //paper
      if (choice == choices::paper) {
        Serial.println("The bot chose paper, You draw");
        printd("The bot chose paper, You draw");
      }
      else if (choice == choices::scissors) {
        Serial.println("The bot chose paper, You win");
        printd("The bot chose paper, You win");
      }
      else if (choice == choices::rock) {
        Serial.println("The bot chose paper, You lost");
        printd("The bot chose paper, You lost");
      }
      startshit = 0;
      choice = choices::undefined;
    }
    else if (pcchoice >= 66 && choice != choices::undefined) { //scissors
      if (choice == choices::paper) {
        Serial.println("The bot chose scissors, You lost");
        printd("The bot chose scissors, You lost");
      }
      else if (choice == choices::scissors) {
        Serial.println("The bot chose scissors, You draw");
        printd("The bot chose scissors, You draw");
      }
      else if (choice == choices::rock) {
        Serial.println("The bot chose scissors, You win");
        printd("The bot chose scissors, You win");
      }
      startshit = 0;
      choice = choices::undefined;
    }
  }

}
