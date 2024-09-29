#include <Arduino.h>
#include <IRremote.hpp>
#define IR_RECEIVE_PIN A4
#define LED_PIN A5
#define SWITCH_PIN_1 13
#define SWITCH_PIN_2 12
#define SWITCH_PIN_3 11
#define SWITCH_PIN_4 10

uint16_t sAddress = 0x0411;
uint8_t command1 = 0xA1;
uint8_t command2 = 0xA2;
uint8_t command3 = 0xA3;
uint8_t command4 = 0xA4;

void setup() {
    Serial.begin(115200);
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    while (!Serial)
        ;

    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    IrSender.begin(3, ENABLE_LED_FEEDBACK, LED_PIN);

    pinMode(LED_PIN, OUTPUT);
    pinMode(SWITCH_PIN_1, INPUT_PULLUP);
    pinMode(SWITCH_PIN_2, INPUT_PULLUP);
    pinMode(SWITCH_PIN_3, INPUT_PULLUP);
    pinMode(SWITCH_PIN_4, INPUT_PULLUP);

    Serial.println(F("Send IR signals at pin 3"));
}

void loop() {
    if (digitalRead(SWITCH_PIN_1) == LOW) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println(F("Sending command 1"));
        IrSender.sendNEC(sAddress, command1, 0);
        digitalWrite(LED_PIN, LOW);
        delay(200);
    }

    if (digitalRead(SWITCH_PIN_2) == LOW) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println(F("Sending command 0"));
        IrSender.sendNEC(sAddress, command2, 0);
        digitalWrite(LED_PIN, LOW);
        delay(200);
    }

    if (digitalRead(SWITCH_PIN_3) == LOW) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println(F("Sending command 3"));
        IrSender.sendNEC(sAddress, command3, 0);
        digitalWrite(LED_PIN, LOW);
        delay(200);
    }

    if (digitalRead(SWITCH_PIN_4) == LOW) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println(F("Sending command 4"));
        IrSender.sendNEC(sAddress, command4, 0);
        digitalWrite(LED_PIN, LOW);
        delay(200);
    }
    if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xE51A7F00:
      digitalWrite(LED_PIN, HIGH);
        Serial.println(F("Sending command 1"));
        IrSender.sendNEC(sAddress, command1, 0);
        digitalWrite(LED_PIN, LOW);
        delay(200);
        break;
        case 0xEC137F00:
        digitalWrite(LED_PIN, HIGH);
        Serial.println(F("Sending command 0"));
        IrSender.sendNEC(sAddress, command2, 0);
        digitalWrite(LED_PIN, LOW);
        delay(200);
        break;
        case 0xE9167F00:
        digitalWrite(LED_PIN, HIGH);
        Serial.println(F("Sending command 4"));
        IrSender.sendNEC(sAddress, command4, 0);
        digitalWrite(LED_PIN, LOW);
        delay(200);
        break;
    }
    IrReceiver.resume();
  }
}
