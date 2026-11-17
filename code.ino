
#include <SoftwareSerial.h>

// HC-05 Bluetooth
SoftwareSerial BT(2, 3); // RX, TX

// Motor Driver 1 - Front motors
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

// Motor Driver 2 - Rear motors
#define IN5 8
#define IN6 9
#define IN7 10
#define IN8 11

void setup() {
  BT.begin(9600);
  Serial.begin(9600);

  for (int pin = 4; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
  }

  stopCar();
}

void loop() {
  if (BT.available()) {
    char command = BT.read();

    switch (command) {
      case 'F':
        forward();
        break;

      case 'B':
        backward();
        break;

      case 'L':
        left();
        break;

      case 'R':
        right();
        break;

      case 'S':
        stopCar();
        break;
    }
  }
}

// Move forward
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}

// Move backward
void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
}

// Turn left
void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}

// Turn right
void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
}

// Stop all motors
void stopCar() {
  for (int pin = 4; pin <= 11; pin++) {
    digitalWrite(pin, LOW);
  }
}
