#include <DS3231.h>
// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
// Init a Time-data structure
Time  t;
int led=13;

void setup()
{
  // Setup Serial connection
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  // Initialize the rtc object
  rtc.begin();
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(12, 20, 00);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(24, 1, 2022);   // Set the date to DD/MM/YYYY
}
void loop()
{
  t = rtc.getTime();   // Get data from the DS3231
  // Send date over serial connection
  Serial.print("Date: ");
  Serial.print(t.date, DEC);
  Serial.print("/");
  Serial.print(t.mon, DEC);
  Serial.print("/");
  Serial.print(t.year, DEC);
  Serial.println();

  // Send Day-of-Week and time
  Serial.print("Day of Week: ");
  Serial.print(t.dow, DEC);
  Serial.println();
  Serial.print("Time: ");
  Serial.print(t.hour, DEC);
  Serial.print(":");
  Serial.print(t.min, DEC);
  Serial.print(":");
  Serial.print(t.sec, DEC);
  Serial.println();
  Serial.println("--------------------------------");
  delay(1000); //Delay is for displaying the time in 1 second interval.
if (t.hour == 15 && t.min == 3 && t.sec == 20) 
//in other words you can insert t.dow for every Thursday?, t.date for specific date?
  {
    digitalWrite(led, HIGH);
  Serial.print("First Alaram");    
  delay(5000);
//Lets say that your component is wired to pin 99 and be switched on for 5 seconds, 
//whatever you want to do with it
}
else if (t.hour == 5 && t.min == 8 && t.sec == 53) 
//in other words you can insert t.dow for every Thursday?, t.date for specific date?
  {  

  }

else{
  digitalWrite(led, LOW);

  }

}
