#include <Arduino.h>
#include <Wire.h>
#include <LittleFS.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <AP33772.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define SCREEN_ADDRESS 0x3C

#define SWITCH_PIN 12
#define RESET_PIN 21
#define CONTROL_PIN 11
#define COUNT_FILE "/counter.txt"
#define ROTATION_FILE "/rotation.txt"

void initDisplay();
void saveCountToFile();
void saveRotationToFile();
void updateDisplay();
void resetCount();


int counter = 249990;
int rotation = 0;
bool countReset = false;
unsigned long lastWrite = 0;

AP33772 usbpd;

enum resetBtnState {
  NO_PRESS = 0,
  SHORT_PRESS,
  LONG_PRESS
};

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire1);

bool button_was_pressed() {
  static bool last_state = HIGH;
  bool current_state = digitalRead(SWITCH_PIN);

  if (!current_state && last_state) {
    delay(10);
    current_state = digitalRead(SWITCH_PIN);
    if (!current_state) {
      last_state = current_state;
      return true;
    }
  }
  last_state = current_state;
  return false;
}

// Only returns true if the button is pressed for under 1 second
resetBtnState checkButton() {
  static bool lastState = HIGH;
  static unsigned long pressTime = 0;
  //static unsigned long debounceTime = 0; //No delay debounce

  bool currentState = digitalRead(RESET_PIN);

  // Check if pressed
  if (currentState != lastState) {
    if (currentState == LOW) {

      pressTime = millis();
    } else {
        unsigned long pressDuration = millis() - pressTime;
        lastState = currentState;

        if (pressDuration >= 1000) {
          return LONG_PRESS;
        } else {
          return SHORT_PRESS;
      }
    }
  }

  lastState = currentState;
  return NO_PRESS;
}


void setup() {
  // Setup debug output
  Serial2.setTX(24);
  Serial2.setRX(25);
  Serial2.begin(115200);

  // Setup SSD1306 output
  Wire1.setSDA(6);
  Wire1.setSCL(7);
  Wire1.begin();

  // Setup USB-C PD interface output
  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire.begin();
  
  // Delay is necessary for processor to acquire PDOs
  delay(1000);

  initDisplay();

  // Negotiate 27W (9V 3A) from PD charger
  usbpd.begin();
  usbpd.setVoltage(9000);
  usbpd.setMaxCurrent(3000);

  Serial2.println("Setting up");

  // Setup GPIO roles
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(RESET_PIN, INPUT_PULLUP);
  pinMode(CONTROL_PIN, OUTPUT_12MA);
  
  digitalWrite(CONTROL_PIN, HIGH);

  Serial2.println("motor on, setup complete");

  // Initialise LittleFS, look for file & set counter value. If file not found, create file and set count value to 0.
  if (!LittleFS.begin()) {
    Serial2.println("LittleFS failed to start up");
  }

  File countFile = LittleFS.open(COUNT_FILE, "r");
  if (countFile) {
    counter = countFile.parseInt();
    countFile.close();
  } else {
    Serial2.println("Failed to read value from file, set to default value of 0");
    counter = 0;
    saveCountToFile();
  }

  File rotationFile = LittleFS.open(ROTATION_FILE, "r");
  if (rotationFile) {
    rotation = rotationFile.parseInt();
    rotationFile.close();
  } else {
    rotation = 1;
    saveRotationToFile();
  }

  updateDisplay();
}

void loop() {

  // Increment value of counter as switch is pressed. Save value of count every 10 seconds.
  if (button_was_pressed()) {
    counter++;
    if(millis() - lastWrite > 10000) {
      saveCountToFile();
      lastWrite = millis();
    }
    updateDisplay();
  }
  
  resetBtnState buttonState = checkButton();

  if (counter >= 250000) {
    digitalWrite(CONTROL_PIN, LOW);
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(28,0);
    display.print(F("ROTATE"));
    display.setCursor(16,18);
    display.print(F("SWITCHES"));
    display.setTextSize(1);
    display.setCursor(52,36);
    display.print(F("THEN"));
    display.setCursor(49,46);
    display.print(F("RESET"));
    display.display();
    if (buttonState == resetBtnState::SHORT_PRESS) {
      rotation++;
      if (rotation <= 4) {
        digitalWrite(CONTROL_PIN, HIGH);
        saveRotationToFile();
      } else {
        rotation = 1;
        saveRotationToFile();
      }
    }
  }


  // Multifunction reset/power button
  switch (buttonState) {
    case LONG_PRESS: {

      int controlState = digitalRead(CONTROL_PIN);

      if (controlState == LOW) {
        digitalWrite(CONTROL_PIN, HIGH);
      } else {
        digitalWrite(CONTROL_PIN, LOW);
      }
      break;
    }
    case SHORT_PRESS:
      resetCount();
  }
}

void initDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)){
    Serial2.println("SSD1306 allocation failed");
  }
  // Clear buffer
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(F("Actuations"));
  display.setCursor(0,10);
  display.setTextSize(2);
  display.println(counter);
  display.setCursor(0,28);
  display.setTextSize(1);
  display.print(F("Rotation"));
  display.setCursor(0,38);
  display.println(rotation);
  display.display();
}

void saveCountToFile() {
  File countFile = LittleFS.open(COUNT_FILE, "w");
  if (countFile) {
    countFile.print(counter);
    countFile.close();
    Serial2.println("Saved Count Value to File");
  } else {
    Serial2.println("Failed to Save Count to File");
  }
}

void saveRotationToFile() {
  File rotationFile = LittleFS.open(ROTATION_FILE, "w");
  if (rotationFile) {
    rotationFile.print(rotation);
    rotationFile.close();
  } else {
    Serial2.println("Failed to save rotation to file");
  }
}

void resetCount() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(F("RESET ACTUATIONS"));
  display.display();
  delay(1000);

  Serial2.println("Actuations set to null");
  //Overwrite saved value
  counter = 0;
  saveCountToFile();
  updateDisplay();
}

