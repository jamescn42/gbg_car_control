#define INVERT1 = 0
#define INVERT2 = 0

//Joystick pins
#define FORWARDS A5
#define BACK A4
#define LEFT A3
#define RIGHT A2

//set speed from 0 to 255
#define SPEED 127
#define HALFSPEED 63

//Mode selector
#define MODE 2

//Button pins
#define BFORWARDS 9
#define BBACK 8
#define BLEFT 10
#define BRIGHT 11

//motor mouts
#define MOTOR1DIREC 4
#define MOTOR2DIREC 7
#define MOTOR1PWM 5
#define MOTOR2PWM 6

int bforwards = 0, bback = 0, bleft = 0, bright = 0;

int forwards = 0, back = 0, left = 0, right = 0;
int mode = 0;

void setup() {
  pinMode(FORWARDS, INPUT);
  pinMode(BACK, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);

  pinMode(BFORWARDS, INPUT);
  pinMode(BBACK, INPUT);
  pinMode(BLEFT, INPUT);
  pinMode(BRIGHT, INPUT);

  pinMode(MODE, INPUT);

  pinMode(MOTOR1DIREC, OUTPUT);
  pinMode(MOTOR1PWM, OUTPUT);
  pinMode(MOTOR2DIREC, OUTPUT);
  pinMode(MOTOR2PWM, OUTPUT);

}

void loop() {
  mode = digitalRead(MODE);
  bforwards = 0, bback = 0, bleft = 0, bright = 0;
  forwards = 0, back = 0, left = 0, right = 0;
  
  if (mode == 0) {
    //joystick mode
    read_joystick();
    
    if (forwards) {
      digitalWrite(MOTOR1DIREC, 1);
      digitalWrite(MOTOR2DIREC, 1);
      if (left) {
        analogWrite(MOTOR1PWM, HALFSPEED);
        analogWrite(MOTOR2PWM, SPEED);
      }
      else if (right) {
        analogWrite(MOTOR1PWM, SPEED);
        analogWrite(MOTOR2PWM, HALFSPEED);
      } else {
        analogWrite(MOTOR1PWM, SPEED);
        analogWrite(MOTOR2PWM, SPEED);
      }
    }
    else if (back) {
      digitalWrite(MOTOR1DIREC, 0);
      digitalWrite(MOTOR2DIREC, 0);
      if (left) {
        analogWrite(MOTOR1PWM, HALFSPEED);
        analogWrite(MOTOR2PWM, SPEED);
      }
      else if (right) {
        analogWrite(MOTOR1PWM, SPEED);
        analogWrite(MOTOR2PWM, HALFSPEED);
      }
      else {
        analogWrite(MOTOR1PWM, SPEED);
        analogWrite(MOTOR2PWM, SPEED);
      }
    }
    else if (left) {
      digitalWrite(MOTOR1DIREC, 1);
      digitalWrite(MOTOR2DIREC, 0);
      analogWrite(MOTOR1PWM, HALFSPEED);
      analogWrite(MOTOR2PWM, HALFSPEED);
    }
    else if (right) {
      digitalWrite(MOTOR1DIREC, 0);
      digitalWrite(MOTOR2DIREC, 1);
      analogWrite(MOTOR1PWM, HALFSPEED);
      analogWrite(MOTOR2PWM, HALFSPEED);
    }
    else {
      analogWrite(MOTOR1PWM, 0);
      analogWrite(MOTOR2PWM, 0);
      digitalWrite(MOTOR1DIREC, 0);
      digitalWrite(MOTOR2DIREC, 0);
    }

  }
  else {
    read_buttons();
    
    if (bforwards) {
      digitalWrite(MOTOR1DIREC, 1);
      digitalWrite(MOTOR2DIREC, 1);
      if (bleft) {
        analogWrite(MOTOR1PWM, HALFSPEED);
        analogWrite(MOTOR2PWM, SPEED);
      }
      else if (bright) {
        analogWrite(MOTOR1PWM, SPEED);
        analogWrite(MOTOR2PWM, HALFSPEED);
      } else {
        analogWrite(MOTOR1PWM, SPEED);
        analogWrite(MOTOR2PWM, SPEED);
      }
    }
    else if (bback) {
      digitalWrite(MOTOR1DIREC, 0);
      digitalWrite(MOTOR2DIREC, 0);
      if (bleft) {
        analogWrite(MOTOR1PWM, HALFSPEED);
        analogWrite(MOTOR2PWM, SPEED);
      }
      else if (bright) {
        analogWrite(MOTOR1PWM, SPEED);
        analogWrite(MOTOR2PWM, HALFSPEED);
      }
      else {
        analogWrite(MOTOR1PWM, SPEED);
        analogWrite(MOTOR2PWM, SPEED);
      }
    }
    else if (bleft) {
      digitalWrite(MOTOR1DIREC, 0);
      digitalWrite(MOTOR2DIREC, 1);
      analogWrite(MOTOR1PWM, HALFSPEED);
      analogWrite(MOTOR2PWM, HALFSPEED);
    }
    else if (bright) {
      digitalWrite(MOTOR1DIREC, 1);
      digitalWrite(MOTOR2DIREC, 0);
      analogWrite(MOTOR1PWM, HALFSPEED);
      analogWrite(MOTOR2PWM, HALFSPEED);
    }
    else {
      analogWrite(MOTOR1PWM, 0);
      analogWrite(MOTOR2PWM, 0);
      digitalWrite(MOTOR1DIREC, 0);
      digitalWrite(MOTOR2DIREC, 0);
      Serial.println("off");
    }
  }
}

void read_buttons() {

  bforwards = digitalRead(BFORWARDS);
  bback = digitalRead(BBACK);
  bleft = digitalRead(BLEFT);
  bright = digitalRead(BRIGHT);
}

void read_joystick() {
  forwards = digitalRead(FORWARDS);
  back = digitalRead(BACK);
  left = digitalRead(LEFT);
  right = digitalRead(RIGHT);
}
