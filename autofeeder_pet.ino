#include<Servo.h>
Servo servo_test;

void setup() 
{
  servo_test.attach(5);   // attach the signal pin of servo to pin 5 of arduino
  pinMode(5, OUTPUT);
}

void loop() {
  // At 5 AM:
  servo_test.write(80);  //Rotate servo by 80 degree and open the lid
  delay(60000);          //Keep @ angle of 80 degree: food keeps falling for one minute
  servo_test.write(0);   // Close the lid by rotating servo 
  delay(25200000UL);     //Open the lid again after 7 hours
  //At 12 PM:
 servo_test.write(80);   //Rotate servo by 80 degree and open the lid 
  delay(60000);          //Food keeps falling for one minute
  servo_test.write(0);   // Close the lid by rotating servo 
  delay(21600000UL);     //Open the lid again after 7 hours
 // At 6 PM:
  servo_test.write(80);   //Rotate servo by 80 degree and open the lid 
  delay(60000);          //Food keeps falling for one minute
  servo_test.write(0);   // Close the lid by rotating servo 
  delay(39600000UL);     //Open the lid again after 10 hours i.e. At 7 AM
   }

  
