



int keypad(){
  
  int key_in = analogRead(A0);
  
  if(key_in<=50){
    return btnRIGHT;
  }
  else if(key_in>=95 && key_in<=105){
    return btnUP;
  }
  else if(key_in>=250 && key_in<=260){
    return btnDOWN;
  }
  else if(key_in>=405 && key_in<=415){
    return btnLEFT;
  }
  else if(key_in>=635 && key_in<=645){
    return btnSELECT;
  }
  else{
    return btnNONE;
  }
}
