#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  pinMode(13,OUTPUT);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  //Serial.print("Ping: ");
  //Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  float d1;
  d1=sonar.ping_cm();
  Serial.println(d1);
  //Serial.println("cm");
  delay(1000);
  float d2;
  d2=sonar.ping_cm();
 // Serial.print("Speed is:");
  //Serial.println(d1);
  Serial.println(d2);
  float d3=d2-d1;
 //  Serial.print("Speed is:");
  if(d3<=0)
   { digitalWrite(13,HIGH); 
    Serial.print("Speed is:");
    Serial.print(abs(d3));
    Serial.println("m/s");
    }
  else
    {Serial.println("Going Away");
    digitalWrite(13,LOW);
    
   }
 // Serial.println("m/s");
  delay(2000);}
  
