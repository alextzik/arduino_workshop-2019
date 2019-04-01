#include <Servo.h>


int number_out[3]={0,0,0};
String text_out="";
int prev_num[3]={0,0,0};
String prev_text="";
int sign[3]={1,1,1};
int count=0;
int angle_0=0;
int angle_1=0;
int angle_2=0;



Servo myservo0,myservo1,myservo2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo0.attach(8);
  myservo1.attach(9);
  myservo2.attach(10);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  if (readSerial()){
    Serial.println("A command was written");
    //execute();
    angles_of_motion(prev_num[0],prev_num[1],prev_num[2]);
  }
  

}

bool readSerial(){
  if (Serial.available()){
    char char_in=Serial.read();
    if(char_in=='\n'){
      //Ignore
    }
    else if((char_in>='0'&& char_in<='9') || char_in=='-'){
      read_Num(char_in);
    }
    else if(char_in=='/'){
      count++;
    }
    else if(char_in=';'){
      set_Command();
      return true;
    }
    else {
      read_Text(char_in);
    }
  }
  return false;
}

void read_Num(char a){
  if(a=='-'){
    sign[count]=-1;
  }
  else{
  number_out[count]=number_out[count]*10+(a-'0');
  }
}

void read_Text(char a){
  text_out=text_out+a;
}

void set_Command(){
  prev_text=text_out;
  text_out="";
  for (int i=0; i<3;i++){
    prev_num[i]=number_out[i]*sign[i];
    number_out[i]=0;
    sign[i]=1;
  }
  count=0;
}
