
#include <Servo.h>

Servo pan;  // create servo object to control a servo
Servo tilt;
int pos = 0;    // variable to store the servo position

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // put your setup code here, to run once:
  pan.attach(9); // attaches the servo on pin 9 to the servo object
  tilt.attach(8); // attaches another servo to pin 9

}

void loop() {
  // put your main code here, to run repeatedly:
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
      pan.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
  }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      pan.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
  }

      // put your main code here, to run repeatedly:
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
      tilt.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
  }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      tilt.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
  }

  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // Sensor Calibration: -4.8992x + 144.7558 (x input = inches, output = sensor output)
  distanceValue = (outputvalue-144.7558)/-4.8992 
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  // Serial.print("sensor = ");
  // Serial.print(sensorValue);
  // Serial.print("\t output = ");
  // Serial.println(outputValue);
  
  Serial.print("distance = ");
  Serial.println(distancValue)
  Serial.print("panangle = ");
  Serial.println(pan.read());
  Serial.print("tiltangle = ");
  Serial.println(tilt.read())

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(500);
}
