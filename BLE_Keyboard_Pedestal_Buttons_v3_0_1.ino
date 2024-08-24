# Saved to GigaHex PC 2024-07-01 21:03:55
# Uploaded to github 2024-08-24 16:50:00
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("GigaHex", "Moth Industries", 100);

#define BUTTON_1 12
#define BUTTON_2 14
#define BUTTON_3 27
#define BUTTON_4 26
#define BUTTON_5 25
#define BUTTON_6 33

int lastButtonState1 = HIGH;
int lastButtonState2 = HIGH;
int lastButtonState3 = HIGH;
int lastButtonState4 = HIGH;
int lastButtonState5 = HIGH;
int lastButtonState6 = HIGH;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  pinMode(BUTTON_6, INPUT_PULLUP);
}

void loop() {
  if (bleKeyboard.isConnected()) {
    int buttonState1 = digitalRead(BUTTON_1);
    int buttonState2 = digitalRead(BUTTON_2);
    int buttonState3 = digitalRead(BUTTON_3);
    int buttonState4 = digitalRead(BUTTON_4);
    int buttonState5 = digitalRead(BUTTON_5);
    int buttonState6 = digitalRead(BUTTON_6);

    if (buttonState1 != lastButtonState1) {
      if (buttonState1 == LOW) {
        bleKeyboard.press(49);
        Serial.println("key1 down");
      } else {
        bleKeyboard.release(49);
        Serial.println("key1 up");
      }
      lastButtonState1 = buttonState1;
    }

    if (buttonState2 != lastButtonState2) {
      if (buttonState2 == LOW) {
        bleKeyboard.press(50);
        Serial.println("key2 down");
      } else {
        bleKeyboard.release(50);
        Serial.println("key2 up");
      }
      lastButtonState2 = buttonState2;
    }

    if (buttonState3 != lastButtonState3) {
      if (buttonState3 == LOW) {
        bleKeyboard.press(51);
        Serial.println("key3 down");
      } else {
        bleKeyboard.release(51);
        Serial.println("key3 up");
      }
      lastButtonState3 = buttonState3;
    }

    if (buttonState4 != lastButtonState4) {
      if (buttonState4 == LOW) {
        bleKeyboard.press(52);
        Serial.println("key4 down");
      } else {
        bleKeyboard.release(52);
        Serial.println("key4 up");
      }
      lastButtonState4 = buttonState4;
    }

    if (buttonState5 != lastButtonState5) {
      if (buttonState5 == LOW) {
        bleKeyboard.press(53);
        Serial.println("key5 down");
      } else {
        bleKeyboard.release(53);
        Serial.println("key5 up");
      }
      lastButtonState5 = buttonState5;
    }

    if (buttonState6 != lastButtonState6) {
      if (buttonState6 == LOW) {
        bleKeyboard.press(54);
        Serial.println("key6 down");
      } else {
        bleKeyboard.release(54);
        Serial.println("key6 up");
      }
      lastButtonState6 = buttonState6;
    }

    delay(100);
  }
}
