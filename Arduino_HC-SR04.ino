//This library must first be added to the Arduino IDE
#include <NewPing.h>

#define PIN_ECHO 4 //In the example this is the yellow wire
#define PIN_TRIG 5 //In the example this is the green wire
#define MAX_DIST 200 //This is in CM. The max is generally around 500

//this is where the global object for connecting and sensing from the ultrasonic unit is created
NewPing sensor(PIN_TRIG, PIN_ECHO, MAX_DIST);

void setup() 
{
  //This is so that the serial monitor will be fed data
  Serial.begin(9600);
}

void loop()
{
  delay(50);//Much shorter than this and there is a risk pings will overlap
  int time_taken=sensor.ping(); //This is the time in microseconds
  Serial.println(time_taken/US_ROUNDTRIP_CM); //US_ROUNDTRIP_CM is the time it takes for sound to go 2CM 
  //It is 2CM because sound needs to go out and back thus the round trip time reflects twice the time required for the distance measured
}

