#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;

int pos1;
int pos2;
int pos3;
int x1;
int y1;
int y2;
int sw;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(6,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

x1 = analogRead(A0);
y1 = analogRead(A1);
y2 = analogRead(A2);
sw = digitalRead(6);



if (x1>600){
  pos1 = s1.read();
  if(pos1<180){
    pos1+=1;
    s1.write(pos1);
    delay(10);
  }
}

if (x1<400){
  pos1 = s1.read();
  if(pos1>0){
    pos1-=1;
    s1.write(pos1);
    delay(10);
  }
}


if (y1>600){
  pos2 = s2.read();
  if(pos2<180){
    pos2+=1;
    s2.write(pos2);
    delay(12);
  }
}

if (y1<400){
  pos2 = s2.read();
  if(pos2>0){
    pos2-=1;
    s2.write(pos2);
    delay(12);
  }
}


if (y2>600){
  pos3 = s3.read();
  if(pos3<180){
    pos3+=1;
    s3.write(pos3);
    delay(12);
  }
}

if (y2<400){
  pos3 = s3.read();
  if(pos3>0){
    pos3-=1;
    s3.write(pos3);
    delay(12);
  }
}


if (sw == 0){
  s4.write(0);
}

if (sw == 1){
  s4.write(180);
}

}
