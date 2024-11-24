#include <Arduino.h>
#include <Bluepad32.h>

GamepadPtr myGamepad = nullptr;
const int motor1f = 13;
const int motor1r = 12;
const int motor2f = 14;
const int motor2r = 27;
const int motor3f = 26;
const int motor3r = 25;
const int motor4f = 33;
const int motor4r = 32;

void onConnectedGamepad(GamepadPtr gp) {
  myGamepad = gp;
}

void onDisconnectedGamepad(GamepadPtr gp) {
  if (myGamepad == gp) {
    myGamepad = nullptr;
  }
}

void setup() {
  Serial.begin(115200);
  BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
  pinMode(motor1f, OUTPUT);
  pinMode(motor1r, OUTPUT);
  pinMode(motor2f, OUTPUT);
  pinMode(motor2r, OUTPUT);
  pinMode(motor3f, OUTPUT);
  pinMode(motor3r, OUTPUT);
  pinMode(motor4f, OUTPUT);
  pinMode(motor4r, OUTPUT);
}

  void loop() {
      BP32.update();

    if (myGamepad && myGamepad->isConnected()) {

      if (myGamepad->y() && !myGamepad->b() && !myGamepad->x()) {
          Serial.println("Frente");
          digitalWrite(motor1f, HIGH);
          digitalWrite(motor2f, HIGH);
          digitalWrite(motor3f, HIGH);
          digitalWrite(motor4f, HIGH);
      }

      if (myGamepad->a() && !myGamepad->b() && !myGamepad->x()) {
          Serial.println("Trás");
          digitalWrite(motor1r, HIGH);
          digitalWrite(motor2r, HIGH);
          digitalWrite(motor3r, HIGH);
          digitalWrite(motor4r, HIGH);
      }
      if (myGamepad->b() && !myGamepad->y() && !myGamepad->a()) {
          Serial.println("Direita");
          digitalWrite(motor1f, HIGH);
          digitalWrite(motor2r, HIGH);
          digitalWrite(motor3r, HIGH);
          digitalWrite(motor4f, HIGH);
      }
      if (myGamepad->x() && !myGamepad->y() && !myGamepad->a()) {
          Serial.println("Esquerda");
          digitalWrite(motor1r, HIGH);
          digitalWrite(motor2f, HIGH);
          digitalWrite(motor3f, HIGH);
          digitalWrite(motor4r, HIGH);
      }

      if (myGamepad->y() && myGamepad->b()) {
          Serial.println("Dir. Frente");
          digitalWrite(motor1f, HIGH);
          digitalWrite(motor4f, HIGH);
      }
      if (myGamepad->y() && myGamepad->x()) {
          Serial.println("Esq. Frente");
          digitalWrite(motor2f, HIGH);
          digitalWrite(motor3f, HIGH);
      }
      if (myGamepad->a() && myGamepad->b()) {
          Serial.println("Dir. Trás");
          digitalWrite(motor2r, HIGH);
          digitalWrite(motor3r, HIGH);
      }
      if (myGamepad->a() && myGamepad->x()) {
          Serial.println("Esq. Trás");
          digitalWrite(motor1f, HIGH);
          digitalWrite(motor4f, HIGH);
      }

      if (myGamepad->r1()) {
          Serial.println("Girando Esquerda");
          digitalWrite(motor1r, HIGH);
          digitalWrite(motor2f, HIGH);
          digitalWrite(motor3r, HIGH);
          digitalWrite(motor4f, HIGH);
      }
      if (myGamepad->l1()) {
          Serial.println("Girando Direita");
          digitalWrite(motor1f, HIGH);
          digitalWrite(motor2r, HIGH);
          digitalWrite(motor3f, HIGH);
          digitalWrite(motor4r, HIGH);
      }
      if (myGamepad->r2()) {
        Serial.println("Acelerando -VRUM VRUM");
          digitalWrite(motor1f, HIGH);
          digitalWrite(motor2f, HIGH);
          digitalWrite(motor3f, HIGH);
          digitalWrite(motor4f, HIGH);
      }
      if (myGamepad->l2()) {
        Serial.println("Dando Ré -Po Po Po");
          digitalWrite(motor1r, HIGH);
          digitalWrite(motor2r, HIGH);
          digitalWrite(motor3r, HIGH);
          digitalWrite(motor4r, HIGH);
      }



      if (!myGamepad->l2() && !myGamepad->l1() && !myGamepad->r2() && !myGamepad->r1() && !myGamepad->y() && !myGamepad->b() && !myGamepad->a() && !myGamepad->x()) {
        Serial.println("  --  ");
        digitalWrite(motor1f, LOW);
        digitalWrite(motor1r, LOW);
        digitalWrite(motor2f, LOW);
        digitalWrite(motor2r, LOW);
        digitalWrite(motor3f, LOW);
        digitalWrite(motor3r, LOW);
        digitalWrite(motor4f, LOW);
        digitalWrite(motor4r, LOW);
      }
  }
      delay(1);
}
