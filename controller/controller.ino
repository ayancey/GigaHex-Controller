// WT32-ETH01 Config
#define ETH_PHY_TYPE  ETH_PHY_LAN8720
#define ETH_PHY_ADDR  1
#define ETH_PHY_MDC   23
#define ETH_PHY_MDIO  18
#define ETH_PHY_POWER 16
#define ETH_CLK_MODE  ETH_CLOCK_GPIO0_IN

#include <ArduinoOSCETH.h>

// Ethernet stuff
const IPAddress ip(192, 168, 1, 201);
const IPAddress gateway (192, 168, 1, 1);
const IPAddress subnet (255, 255, 255, 0);

// Button pins (not accurate yet)
// #define BUTTON_1 12
// #define BUTTON_2 14
// #define BUTTON_3 27
// #define BUTTON_4 26
// #define BUTTON_5 25
// #define BUTTON_6 33

int lastButtonState1 = HIGH;
int lastButtonState2 = HIGH;
int lastButtonState3 = HIGH;
int lastButtonState4 = HIGH;
int lastButtonState5 = HIGH;
int lastButtonState6 = HIGH;

OscEtherClient client;

const char *client_ip = "192.168.1.200";
const int client_port = 16955;


void setup() {
    Serial.begin(115200);
    delay(2000);

    // Ethernet stuff
    ETH.begin();
    ETH.config(ip, gateway, subnet);

//     pinMode(BUTTON_1, INPUT_PULLUP);
//     pinMode(BUTTON_2, INPUT_PULLUP);
//     pinMode(BUTTON_3, INPUT_PULLUP);
//     pinMode(BUTTON_4, INPUT_PULLUP);
//     pinMode(BUTTON_5, INPUT_PULLUP);
//     pinMode(BUTTON_6, INPUT_PULLUP);
}

void loop() {
//     int buttonState1 = digitalRead(BUTTON_1);
//     int buttonState2 = digitalRead(BUTTON_2);
//     int buttonState3 = digitalRead(BUTTON_3);
//     int buttonState4 = digitalRead(BUTTON_4);
//     int buttonState5 = digitalRead(BUTTON_5);
//     int buttonState6 = digitalRead(BUTTON_6);
//
//     if (buttonState1 != lastButtonState1) {
//       if (buttonState1 == LOW) {
//         client.send("10.69.1.165", 6420, "/button/h1", 1);
//         Serial.println("key1 down");
//       } else {
//         client.send("10.69.1.165", 6420, "/button/h1", 0);
//         Serial.println("key1 up");
//       }
//       lastButtonState1 = buttonState1;
//     }
//
//     if (buttonState2 != lastButtonState2) {
//       if (buttonState2 == LOW) {
//         client.send("10.69.1.165", 6420, "/button/h2", 1);
//         Serial.println("key2 down");
//       } else {
//         client.send("10.69.1.165", 6420, "/button/h2", 0);
//         Serial.println("key2 up");
//       }
//       lastButtonState2 = buttonState2;
//     }
//
//     if (buttonState3 != lastButtonState3) {
//       if (buttonState3 == LOW) {
//         client.send("10.69.1.165", 6420, "/button/h3", 1);
//         Serial.println("key3 down");
//       } else {
//         client.send("10.69.1.165", 6420, "/button/h3", 0);
//         Serial.println("key3 up");
//       }
//       lastButtonState3 = buttonState3;
//     }
//
//     if (buttonState4 != lastButtonState4) {
//       if (buttonState4 == LOW) {
//         client.send("10.69.1.165", 6420, "/button/h4", 1);
//         Serial.println("key4 down");
//       } else {
//         client.send("10.69.1.165", 6420, "/button/h4", 0);
//         Serial.println("key4 up");
//       }
//       lastButtonState4 = buttonState4;
//     }
//
//     if (buttonState5 != lastButtonState5) {
//       if (buttonState5 == LOW) {
//         client.send("10.69.1.165", 6420, "/button/h5", 1);
//         Serial.println("key5 down");
//       } else {
//         client.send("10.69.1.165", 6420, "/button/h5", 0);
//         Serial.println("key5 up");
//       }
//       lastButtonState5 = buttonState5;
//     }
//
//     if (buttonState6 != lastButtonState6) {
//       if (buttonState6 == LOW) {
//         client.send("10.69.1.165", 6420, "/button/h6", 1);
//         Serial.println("key6 down");
//       } else {
//         client.send("10.69.1.165", 6420, "/button/h6", 0);
//         Serial.println("key6 up");
//       }
//       lastButtonState6 = buttonState6;
//     }
//

    client.send(client_ip, client_port, "/button/h6", 1);
    delay(500);

}
