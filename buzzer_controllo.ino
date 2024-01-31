#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX, TX

int buzzerPin = 8;
char receivedChar;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    receivedChar = bluetooth.read();
    if (receivedChar == '1') {
      digitalWrite(buzzerPin, HIGH);
      delay(9000);
      digitalWrite(buzzerPin, LOW);
      delay(500);
    }
  }
}
