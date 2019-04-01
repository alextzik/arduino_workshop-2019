void Code1()
{
  if(setup_flag == 1)
  {
    Serial.println("Code1 started");
    setup_flag=0;
    delay(200);
    
  }
  else{
    lcd.clear();
    lcd.print("geiaa");
    Serial.print("ok");
    delay(1000);
    lcd.clear();
    code_flag=0;
    menu_flag=0;
   
    lcdSetup();
 }
}
