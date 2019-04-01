

int bright=0;
int fade=1;


void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(8,LOW);
}

void loop()
{
  analogWrite(9, bright);

  bright= bright+ fade;
  if (bright<=0 || bright >= 100) //AN to bright einai <=0 h >=100 mpainei mesa. An oxi to bright auxanetai
  {                               //An bei mesa to bright meiwnetai mexris otou xana bei kai xana auxanetai.
   fade=-fade; 
    }
    delay(10);

  }
