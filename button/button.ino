bool buttonState=1;
bool lastButtonState = 1;
bool ledState=0;

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(2,INPUT_PULLUP); //arxikopoihsh button
  digitalWrite(8,LOW);

}

void loop() {
  buttonState = digitalRead(2); //diabazei ton palmo tou button
  
  
  if(lastButtonState==HIGH && buttonState==LOW){
    ledState = !ledState;
    analogWrite(9,80*ledState);
  }
  lastButtonState = buttonState;

}
