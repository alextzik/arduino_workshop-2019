//ακριβεια μετρησεων


#include <NewPing.h>

//#define TRIGGER 10
//#define ECHO 13
#define MAX_DIS 200

NewPing sonar(12,13, MAX_DIS);

int count=0;
float dist[3]={0,0,0};
float comp[3]={0,0,0};
float mean;
unsigned long current_time=0;
unsigned long last_time=0;

void setup() {
  Serial.begin (9600);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  last_time=millis();
}

void loop() {
 
 current_time=millis();

 if (current_time-last_time >= 50)
 {
      if(count<3)
      {
      last_time=millis();
      dist[count]=sonar.ping_cm();
      float k=dist[count];
      k=sonar.ping_cm();
      Serial.println(k);
      count++;
      delay(25);
      }
    
      else if(count==3)
      {
      mean=(dist[0]+dist[1]+dist[2])/3;
//Serial.print("lathos");
//Serial.println(mean);
      
    
      if(abs(dist[0]-mean)<10 && abs(dist[1]-mean)<10 && abs(dist[2]-mean)<10)
      {
        {
        Serial.print("h timi einai:");
        //Serial.println(mean);}
        }
       
        
         
    
      count=0;
      }
 }

 }
}
