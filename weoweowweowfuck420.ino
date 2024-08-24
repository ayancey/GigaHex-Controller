# Last saved on GigaHex PC 2024-07-01 00:30:00
#       Uploaded to github 2024-08-24 16:04:00

#include <ArduinoOSCWiFi.h>
#include "AiEsp32RotaryEncoder.h"

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


OscWiFiClient client;



#define ROTARY_ENCODER_A_PIN 15
#define ROTARY_ENCODER_B_PIN 13
#define ROTARY_ENCODER_BUTTON_PIN -1
#define ROTARY_ENCODER_VCC_PIN -1
#define ROTARY_ENCODER_STEPS 4

//instead of changing here, rather change numbers above
AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN, ROTARY_ENCODER_STEPS);


void rotary_loop()
{
    //dont print anything unless value changed
    if (rotaryEncoder.encoderChanged())
    {
            Serial.print("Value: ");
            int rotval = rotaryEncoder.readEncoder();
            float z = (float)rotval / 100.0;
            Serial.println(z);
            client.send("10.69.1.165", 8010, "/surfaces/Quad-1/FX/Color_Controls/Hue", z);
    }
}

void IRAM_ATTR readEncoderISR()
{
    rotaryEncoder.readEncoder_ISR();
}


void setup() {
  // put your setup code here, to run once:
    WiFi.begin("RustyNutz", "microsausage");
      Serial.begin(115200);
  Serial.println("Starting BLE work!");
    pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  pinMode(BUTTON_6, INPUT_PULLUP);
    rotaryEncoder.begin();
    rotaryEncoder.setup(readEncoderISR);
    rotaryEncoder.setBoundaries(0, 100, false);
    rotaryEncoder.disableAcceleration();
    //WiFi.config(ip, gateway, subnet);
}




void loop() {
  // put your main code here, to run repeatedly:

    int buttonState1 = digitalRead(BUTTON_1);
    int buttonState2 = digitalRead(BUTTON_2);
    int buttonState3 = digitalRead(BUTTON_3);
    int buttonState4 = digitalRead(BUTTON_4);
    int buttonState5 = digitalRead(BUTTON_5);
    int buttonState6 = digitalRead(BUTTON_6);

    if (buttonState1 != lastButtonState1) {
      if (buttonState1 == LOW) {
        client.send("10.69.1.165", 6420, "/button/h1", 1);
        Serial.println("key1 down");
      } else {
        client.send("10.69.1.165", 6420, "/button/h1", 0);
        Serial.println("key1 up");
      }
      lastButtonState1 = buttonState1;
    }

    if (buttonState2 != lastButtonState2) {
      if (buttonState2 == LOW) {
        client.send("10.69.1.165", 6420, "/button/h2", 1);
        Serial.println("key2 down");
      } else {
        client.send("10.69.1.165", 6420, "/button/h2", 0);
        Serial.println("key2 up");
      }
      lastButtonState2 = buttonState2;
    }

    if (buttonState3 != lastButtonState3) {
      if (buttonState3 == LOW) {
        client.send("10.69.1.165", 6420, "/button/h3", 1);
        Serial.println("key3 down");
      } else {
        client.send("10.69.1.165", 6420, "/button/h3", 0);
        Serial.println("key3 up");
      }
      lastButtonState3 = buttonState3;
    }

    if (buttonState4 != lastButtonState4) {
      if (buttonState4 == LOW) {
        client.send("10.69.1.165", 6420, "/button/h4", 1);
        Serial.println("key4 down");
      } else {
        client.send("10.69.1.165", 6420, "/button/h4", 0);
        Serial.println("key4 up");
      }
      lastButtonState4 = buttonState4;
    }

    if (buttonState5 != lastButtonState5) {
      if (buttonState5 == LOW) {
        client.send("10.69.1.165", 6420, "/button/h5", 1);
        Serial.println("key5 down");
      } else {
        client.send("10.69.1.165", 6420, "/button/h5", 0);
        Serial.println("key5 up");
      }
      lastButtonState5 = buttonState5;
    }

    if (buttonState6 != lastButtonState6) {
      if (buttonState6 == LOW) {
        client.send("10.69.1.165", 6420, "/button/h6", 1);
        Serial.println("key6 down");
      } else {
        client.send("10.69.1.165", 6420, "/button/h6", 0);
        Serial.println("key6 up");
      }
      lastButtonState6 = buttonState6;
    }

    rotary_loop();
    delay(30);
  
}
