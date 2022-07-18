



#include<Servo.h>

Servo joint_1;
Servo joint_2;
Servo joint_3;
Servo grepper;
void movarm(float XL,float YL,char dd);
void setup(){
  joint_1.attach(3);//منفذ السيرفو المفصل الاول
  joint_2.attach(5);//منفذ السيرفو المفصل الثاني
  joint_3.attach(10);//منفذ السيرفو المفصل الثالث
  //grepper.attach(11); لانحتاجه الان

  joint_1.write(90);
  joint_2.write(90);
  joint_3.write(90);//نجعل زوايا السيرفو 90 درجه لكي نوازنها مع الذراع كما في الصوره 1
  int L1=12
  int L2=12//(مثلا 12)اطوال الذراع
  }

void loop(){
    
    }
void movarm(float XL,float YL,char dd){//XL=X,YL=Y القيم التي يدخلها المستخدم 
      double R=pow(XL,2)+pow(YL,2);
      float Beta=atan(YL/XL);
      double Gama=acos(((L1*L1)-(L2*L2)+LA)/(2*sqrt(LA)*L1));
      double Angle2=acos(((L1*L1)-(L2*L2)-LA)/(2*L1*L2));
      Angle2=180*Angle2/3.14;//تحويلها الى الى وحدة الدرجه لان خرج دالة الجتا يكون بالراديان والسيرفو يتعامل مع وحدة الدرجه
      //Angle2=زاوية السيرفو الثاني
      double Angle1=Gama+Beta;//زاوية اول سيرفو
      double LS=L2*sin(Angle1);
      double LC=L2*cos(Angle1);
      double Angle3=180*atan((YL-LS)/(XL-LC))/3.142;//   في زاوية ثابتة كما في الفديوend effectorلكي تجعل 
      if (dd=='H'){
        Angle3=90-Angle3;
        }
      if (dd=='V'){
        Angle3=-Angle3;
        }
       Angle1=180*Angle1/3.142;
      int Joint_1=(int)Angle1;
      int Joint_2=(int)Angle2;
      int Joint_3=(int)Angle3;
         joint_1.write(Joint_1);
         joint_2.write(Joint_2);
         joint_3.write(Joint_3);
          }

void armtake(){
  float ya=12;
  float xa=12;
  movarm(xa,ya,'H');
  delay(500);
  while(xa!=15){
    movarm(xa,ya,'H');
    delay(200);
    xa++;
    }
    delay(500);
  grepper.write(100);delay(1000);
  while(ya!=-3){
    movarm(xa,ya,'H');
    delay(200);
    ya--;
    }
     delay(500); 
  while(xa!=20){
    movarm(xa,ya,'H');
    delay(200);
    xa++;
    }
  grepper.write(170);delay(500); 
  while(ya!=15){
    movarm(xa,ya,'H');
    delay(200);
    ya++;
    }
  delay(100);
  }
