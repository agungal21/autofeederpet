/*
 * TimeAlarmExample.pde
 *
 * This example calls alarm functions at 8:30 am and at 5:45 pm (17:45)
 * and simulates turning lights on at night and off in the morning
 * A weekly timer is set for Saturdays at 8:30:30
 *
 * A timer is called every 15 seconds
 * Another timer is called once only after 10 seconds
 *
 * At startup the time is set to Jan 1 2011  8:29 am
 */
 
#include <Time.h>
#include <TimeAlarms.h>
#include <Servo.h> 

// membuat nama objek servo untuk pengontrolan servo 
Servo myservo;          

void setup()
{
  Serial.begin(9600);
  setTime(15,13,0,20,4,19); // set time to Saturday 8:29:00am Jan 1 2011
  // create the alarms 
  Alarm.alarmRepeat(15,14,0, MorningAlarm);  // 8:30am every day
  Alarm.alarmRepeat(15,15,0,EveningAlarm);  // 5:45pm every day 
  Alarm.alarmRepeat(dowSaturday,8,30,30,WeeklyAlarm);  // 8:30:30 every Saturday 

 
  Alarm.timerRepeat(15, Repeats);            // timer for every 15 seconds    
  Alarm.timerOnce(10, OnceOnly);             // called once after 10 seconds 

 // objek servo diletakan pada pin 9 
 myservo.attach(9); 
}

void  loop(){  
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
}

// functions to be called when an alarm triggers:
void MorningAlarm(){
  Serial.println("Alarm: - turn lights off");   
  // pada posisi 1 derajat
  // memberitahu servo untuk pergi ke posisi  180 derajat
  myservo.write(180);
  // tunggu 15ms untuk pencapaian  posisi servo    
  delay(1000);
  myservo.write(90);
  // tunggu 15ms untuk pencapaian  posisi servo    
  delay(15); 
}

void EveningAlarm(){
  Serial.println("Alarm: - turn lights on");
  // pada posisi 1 derajat
  // memberitahu servo untuk pergi ke posisi  180 derajat
  myservo.write(180);
  // tunggu 15ms untuk pencapaian  posisi servo    
  delay(1000);
  myservo.write(90);
  // tunggu 15ms untuk pencapaian  posisi servo    
  delay(15);
            
}

void WeeklyAlarm(){
  Serial.println("Alarm: - its Monday Morning");      
}

void ExplicitAlarm(){
  Serial.println("Alarm: - this triggers only at the given date and time");       
}

void Repeats(){
  Serial.println("15 second timer");         
}

void OnceOnly(){
  Serial.println("This timer only triggers once");  
}

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println(); 
}

void printDigits(int digits)
{
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
