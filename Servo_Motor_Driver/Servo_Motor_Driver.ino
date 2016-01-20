/* Sweep
Modified by: Chung Zheng
A modified version of the sweep script by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo vServo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
Servo hServo; 
 
int vPos = 30;    // variable to store the vertical servo position 
int hPos = 30;    // variable to store the horizontal servo position
void setup() 
{ 
  vServo.attach(9);   // attaches the servo on pin 9 to the servo object 
  hServo.attach(6);
  
  pinMode(8,OUTPUT);   // Power for the control pad
  digitalWrite(8,HIGH);
  
                       // Sets the 4 input pins for the controls
  pinMode(13,INPUT);   // Up Button Pin
  pinMode(12,INPUT);   // Down Button Pin
  pinMode(11,INPUT);   // Left Button Pin
  pinMode(10,INPUT);   // Right Button Pin
  vServo.write(vPos);
  hServo.write(hPos);
} 
 
void loop() 
{ 
  if ((digitalRead(13) == LOW) && vPos < 180)
  {
    vPos = vPos + 1;                 // Move Up the attached arm
    delay(30);                       // waits 15ms for the servo to reach the position 
  }
    if ((digitalRead(12) == LOW) && vPos > 13)
  {
    vPos = vPos - 1;                 // Move Down the attached arm
    delay(30);                       // waits 15ms for the servo to reach the position 
  }
    if ((digitalRead(11) == LOW) && hPos < 180)
  {
    hPos = hPos + 1;                 // Move Left the attached arm
    delay(30);                       // waits 15ms for the servo to reach the position 
  }
    if ((digitalRead(10) == LOW) && hPos > 13)
  {
    hPos = hPos - 1;                 // Move Right the attached arm
    delay(30);                       // waits 15ms for the servo to reach the position 
  }
  vServo.write(vPos);
  hServo.write(hPos);
} 
