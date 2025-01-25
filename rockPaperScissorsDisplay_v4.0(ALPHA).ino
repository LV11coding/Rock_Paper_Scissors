#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define BUTTON1PIN 2
#define BUTTON2PIN 3
#define BUTTON3PIN 4
#define STARTPIN 5
#define LEDr 9
#define LEDp 8
#define LEDs 7
#define LEDstart 6

#define OLED_Address 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
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
  buttonState.btn1 = !digitalRead(BUTTON1PIN);
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
  pinMode(LEDr, OUTPUT);
  pinMode(LEDp, OUTPUT);
  pinMode(LEDs, OUTPUT);
  pinMode(LEDstart, OUTPUT);
  printd("Press START");
}

void loop() {
  if (startshit == 0) {
    if (digitalRead(STARTPIN) == LOW) {
      startshit = 1;
      digitalWrite(LEDr, LOW);
      digitalWrite(LEDs, LOW);
      digitalWrite(LEDp, LOW);
      digitalWrite(LEDstart, HIGH);
      printd("Waiting for user choice");
    } else {
      digitalWrite(LEDstart, LOW);
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
        digitalWrite(LEDp, HIGH);
        Serial.println("rock, You WIN");
        printd("rock, You WIN");
      }
      else if (choice == choices::scissors) {
        digitalWrite(LEDs, HIGH);
        Serial.println("rock, You LOST");
        printd("rock, You LOST");
      }
      else if (choice == choices::rock) {
        digitalWrite(LEDr, HIGH);
        Serial.println("rock, You DRAW");
        printd("rock, You DRAW");
      }
      startshit = 0;
      choice = choices::undefined;
    }
    else if (pcchoice >= 33 && pcchoice < 66 && choice != choices::undefined) { //paper
      if (choice == choices::paper) {
        digitalWrite(LEDp, HIGH);
        Serial.println("paper, You DRAW");
        printd("paper, You DRAW");
      }
      else if (choice == choices::scissors) {
        digitalWrite(LEDs, HIGH);
        Serial.println("paper, You WIN");
        printd("paper, You WIN");
      }
      else if (choice == choices::rock) {
        digitalWrite(LEDr, HIGH);
        Serial.println("paper, You LOST");
        printd("paper, You LOST");
      }
      startshit = 0;
      choice = choices::undefined;
    }
    else if (pcchoice >= 66 && choice != choices::undefined) { //scissors
      if (choice == choices::paper) {
        digitalWrite(LEDp, HIGH);
        Serial.println("scissors, You LOST");
        printd("scissors, You LOST");
      }
      else if (choice == choices::scissors) {
        digitalWrite(LEDs, HIGH);
        Serial.println("scissors, You DRAW");
        printd("scissors, You DRAW");
      }
      else if (choice == choices::rock) {
        digitalWrite(LEDr, HIGH);
        Serial.println("scissors, You WIN");
        printd("scissors, You WIN");
      }
      startshit = 0;
      choice = choices::undefined;
    }
  }
}
