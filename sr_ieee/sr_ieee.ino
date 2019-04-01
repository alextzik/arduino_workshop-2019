#include <NewPing.h>

//define TRIGGER 10
//define ECHO 13
//define MAX_DIS 200

NewPing sonar(12,13, 200);
unsigned long previousTime=0;
unsigned long currentTime=0;

int new_reading=0;
int new_trust=0;

int current_reading=0;
bool current_trust=0;

int last_reading=0;
bool last_trust=0;

int second_last_reading=0;
bool second_last_trust=0;



void setup()
{
  Serial.begin(9600);
  //pinMode(TRIGGER,OUTPUT);
  //pinMode(ECHO,OUTPUT);
  
}

void loop()
{
  getReading();
  int dist = getDistance();
}


void getReading()
{
  
  currentTime=millis();
  if((currentTime-previousTime) >50)
  {
    previousTime=currentTime;
    new_reading=sonar.ping_cm();
    Serial.print("edw");
    Serial.println(new_reading);
    new_trust=0;
    applyFilters();
    Serial.println(getDistance());
  }
}



int getDistance()
{
  int sum;
  int counter=0;
  if (current_trust == 1)
  {
    sum+= current_reading;
    counter++;
  }

if (last_trust == 1)
  {
    sum+= last_reading;
    counter++;
  }

  if (second_last_trust == 1)
  {
    sum+= second_last_reading;
    counter++;
  }
  

  int avg=sum/counter;
  return avg;
}

void rotateValues()
{
  second_last_reading = last_reading;
  second_last_trust  = last_trust;
  last_reading   = current_reading;
  last_trust   = current_trust;
  current_reading= new_reading;
}


void changeTrustFactor()
{
if ( current_trust==0 && last_trust==0 && second_last_trust==0 )
    {
      current_trust = 1;
      last_trust = 1;
      second_last_trust=1;
    }
  
}
