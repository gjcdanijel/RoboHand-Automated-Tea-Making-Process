#include <Servo.h>

// Struct to group servo data
struct ServoMotor {
  Servo servo;
  int pin;
  int currentPosition = 0; // Initial position
};

// Define all servos
ServoMotor servos[] = {
    {Servo(), D3}, // Servo 1: GORE/DOLJE
    {Servo(), D4}, // Servo 2: ISPRAVLJANJE
    {Servo(), D5}, // Servo 3: HVAT
    {Servo(), D6}  // Servo 4: ROTACIJA
};

// Variables for movement logic
int gr = 0;  // grip
int dw = 80; // how much up
int up = 0;
int fr;      // how much is it far
int pl = 0;  // pull

void setup() {
  Serial.begin(115200);
  Serial.println("Pocetak");

  // Attach all servo pins
  for (int i = 0; i < 4; i++) {
    servos[i].servo.attach(servos[i].pin);
  }
}

void loop() {
  // Simulate the tea-making process
  getFrom(75);
  delay(4000); // Tea is brewing
  throwAt(60);
  // Getting sugar
  getFrom(45);
  throwAt(180);
  // Geting spoon
  getFrom(0);
  stir();
  throwAt(0);
  delay(4000);
}

void smoothMoveServo(ServoMotor &servoMotor, int targetPos, int stepDelay = 5) {
  if (servoMotor.currentPosition < targetPos) {
    for (int pos = servoMotor.currentPosition; pos <= targetPos; pos++) {
      servoMotor.servo.write(pos);
      delay(stepDelay);
    }
  } else {
    for (int pos = servoMotor.currentPosition; pos >= targetPos; pos--) {
      servoMotor.servo.write(pos);
      delay(stepDelay);
    }
  }
  servoMotor.currentPosition = targetPos;
}

void setServoPositions(int sp1, int sp2, int sp3, int sp4) {
  int targetPositions[] = {sp1, sp2, sp3, sp4};

  for (int i = 0; i < 4; i++) {
    smoothMoveServo(servos[i], targetPositions[i]);
  }

  // Print updated positions
  Serial.println("Servo positions updated:");
  for (int i = 0; i < 4; i++) {
    Serial.print("Servo"); Serial.print(i + 1); Serial.print(": ");
    Serial.println(servos[i].currentPosition);
  }
  Serial.println("=================================");
}

void getFrom(int pos) {
  fr = pos;
  Serial.println("Get from " + String(pos));
  int sp1[] = {up, up, up, dw, dw, up, up, up};
  int sp2[] = {pl, pl, pl, 30, 30, pl, pl, pl};
  int sp3[] = {gr, gr, 60, 60, gr, gr, gr, gr};
  int sp4[] = {180, fr, fr, fr, fr, fr, 180, 180};

  for (int i = 0; i < 8; i++) {
    setServoPositions(sp1[i], sp2[i], sp3[i], sp4[i]);
    delay(1500);
  }
}

void throwAt(int pos) {
  fr = pos;
  Serial.println("Throw at " + String(pos));
  int sp1[] = {up, up, up, up};
  int sp2[] = {pl, pl, pl, pl};
  int sp3[] = {gr, gr, 60, gr};
  int sp4[] = {180, fr, fr, 180};

  for (int i = 0; i < 4; i++) {
    setServoPositions(sp1[i], sp2[i], sp3[i], sp4[i]);
    delay(1500);
  }
}

void stir() {
  dw = 50;
  fr = 180;
  int sp1[] = {up, dw, dw, dw, dw, dw, dw, up};
  int sp2[] = {pl, pl, 30, pl, 30, pl, 30, pl};
  int sp3[] = {gr, gr, gr, gr, gr, gr, gr, gr};
  int sp4[] = {fr, 160, fr, 160, fr, 160, fr, fr};

  for (int i = 0; i < 8; i++) {
    setServoPositions(sp1[i], sp2[i], sp3[i], sp4[i]);
    delay(500);
  }
  delay(1000);
  dw = 80;
}
