#include <LiquidCrystal.h>

#define right=0
#define down=1
#define up=2
#define left=3
#define select=4
#define none=5

LiquidCrystal lcd(1,2,4,5,6,7);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(A0,INPUT);

}

void loop() {
  Serial.println(analogRead(A0));
  print(project1());
  delay(50);
}

int project1(){
  int key_in = analogRead(A0);
  if(key_in<=50){
    return right
  }
  else if(key_in>=95 &&key_in<=105){
    return up
  }
  else if(key_in>=250 &&key_in<=260){
    return down
  }
  else if(key_in>=405 &&key_in<=415){
    return left
  }
  else if(key_in>=635 &&key_in<=645){
    return select
  }
  else{
    return none
  }
  
  
  
}
