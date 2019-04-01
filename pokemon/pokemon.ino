

#include <LiquidCrystal.h>

//LiquidCrystal lcd(1,2,4,5,6,7);

#define right 0
#define down 1
#define up 2
#define left 3
#define select 4
#define none 5



int flag=0;


LiquidCrystal lcd(8,9,4,5,6,7);

int pos=0;
String msg[4]={"Attacking","Choose item","Change pokemon","Escaping"};


void setup() {
  lcd.begin(16,2);
  pinMode(10,INPUT);
  pinMode(A0,INPUT);

battlemenu(pos);
delay(500);
}

void loop() {
  int btn=project1(); //epilogi koumpiou
                      //H timi tou pos krateitai, den xanetai
  
  if(btn==select) 
  {
    lcd.clear();    
    lcd.setCursor(0,0);
    lcd.print(msg[pos]);
    delay(2000);
    pos=0;
   }
   else if (btn==right)
   {
    pos++;
   }
    else if (btn==left)   
   {
    pos--;                
   }
    else if (btn==up)
   {
    pos=pos-2;
   }
    else if (btn==down)
   {
    pos=pos+2;
   }

   
   if(pos<0)
   {
    pos=pos+4;
   }

    else if (pos>3)
    {
      pos = pos-4;
    }

battlemenu(pos); //kaleitai gia na emfanisei apotelesmata
delay(350);

}


//sunartisi project
int project1(){
  
  int key_in = analogRead(A0);
  
  if(key_in<=50){
    return right;
  }
  else if(key_in>=95 && key_in<=105){
    return up;
  }
  else if(key_in>=250 && key_in<=260){
    return down;
  }
  else if(key_in>=405 && key_in<=415){
    return left;
  }
  else if(key_in>=635 && key_in<=645){
    return select;
  }
  else{
    return none;
  }
}
  
//sunartisi battlemenu
void battlemenu(int pos)
{
lcd.clear();
lcd.setCursor(0,0);
//lcd.print(msg[pos]);
if(flag==0){
  lcd.print("FIGHT  BAG");
  lcd.setCursor(0,1);
  lcd.print("POKEMON  RUN");
  flag=!flag;}
else if(pos==0){
  lcd.print("       BAG");
  lcd.setCursor(0,1);
  lcd.print("POKEMON  RUN");
  flag=!flag; 
}
else if(pos==1){
  lcd.print("FIGHT     ");
  lcd.setCursor(0,1);
  lcd.print("POKEMON  RUN");
  flag=!flag; 
}
else if(pos==2){
  lcd.print("FIGHT  BAG");
  lcd.setCursor(0,1);
  lcd.print("         RUN");
  flag=!flag; 
}
else if(pos==3){
  lcd.print("FIGHT  BAG");
  lcd.setCursor(0,1);
  lcd.print("POKEMON    ");
  flag=!flag; 
}
}





  
