#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Servo base_servo;
Servo shoulder_servo;
Servo elbow_servo;
Servo gripper_servo;

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup() {

  Serial.begin(115200);

  base_servo.attach(8);
  shoulder_servo.attach(11);
  elbow_servo.attach(9);
  gripper_servo.attach(10);

  base_servo.write(90);
  shoulder_servo.write(90);
  elbow_servo.write(10);
  gripper_servo.write(0);

  if (!accel.begin()) {
    Serial.println("ADXL345 not detected");
    while (1);
  }

  accel.setRange(ADXL345_RANGE_16_G);
}

void loop() {

  // ==============================
  // RECEIVE SERVO COMMAND
  // ==============================
  if (Serial.available()) {

    int base = Serial.parseInt();
    int shoulder = Serial.parseInt();
    int elbow = Serial.parseInt();
    int gripper = Serial.parseInt();

    elbow = constrain(elbow, 90, 180);
    gripper = constrain(gripper, 0, 100);

    base_servo.write(base);
    shoulder_servo.write(shoulder);
    elbow_servo.write(elbow);
    gripper_servo.write(100 - gripper);
  }

  // ==============================
  // READ ADXL345
  // ==============================
  sensors_event_t event;
  accel.getEvent(&event);

  float ax = event.acceleration.x;
  float ay = event.acceleration.y;
  float az = event.acceleration.z;

  // ==============================
  // SEND ACCELERATION
  // ==============================
  Serial.print(ax);
  Serial.print(",");
  Serial.print(ay);
  Serial.print(",");
  Serial.println(az);

  // ==============================
  // SEND CURRENT SERVO ANGLES
  // ==============================
  Serial.print("ANG:");
  Serial.print(base_servo.read());
  Serial.print(",");
  Serial.print(shoulder_servo.read());
  Serial.print(",");
  Serial.print(elbow_servo.read());
  Serial.print(",");
  Serial.println(gripper_servo.read());

  delay(5);
}