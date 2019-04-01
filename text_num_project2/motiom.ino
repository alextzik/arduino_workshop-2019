//#include <Math.h>
double a=60;
double b=63;

void angles_of_motion(int x,int y, int z){
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  
  
  
  
  long aa=abs(a);
  long bb=abs(b);
  
  float c=sqrt(x*x+y*y+z*z);
  long cc=abs(c);
  Serial.println(c);
  double A=acos((-sq(aa)+sq(bb)+sq(cc))/(double)(2*c*b));
  Serial.println(A);
  float B=acos((a*a-b*b+c*c)/(2*a*c));
  float C=acos((a*a+b*b-c*c)/(2*a*b));
  float D=atan(z/sqrt(x*x+y*y));
  A=A*180/3.14;
  B=B*180/3.14;
  C=C*180/3.14;
  D=D*180/3.14;
  angle_2=(int)(-90+C);
  angle_1=(int)(90+A+D);//
  angle_0=(int)(90+atan(y/x));
  Serial.println(angle_0);
  Serial.println(angle_1);
  Serial.println(angle_2);
  if ((angle_0>=0 && angle_0<=180) && (angle_1>=0 && angle_1<=180) && (angle_2>=0 && angle_2<=180)){
    myservo0.write(angle_0);
    myservo1.write(angle_1);
    myservo2.write(angle_2);
  }
  angle_0=0;
  angle_1=0;
  angle_2=0;
}
