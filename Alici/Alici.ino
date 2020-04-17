#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(9,10); 
int data[2];
const int Motor1_Ileri = 4;//Sağ Motor
const int Motor1_Geri = 2;
const int Motor1_PWM = 3;

const int Motor2_Ileri = 7;//Sol Motor
const int Motor2_Geri = 8;
const int Motor2_PWM = 5; 
void setup()   
{
   pinMode(Motor1_Ileri,OUTPUT);
  pinMode(Motor1_Geri,OUTPUT);
  pinMode(Motor1_PWM,OUTPUT);
  pinMode(Motor2_Ileri,OUTPUT);
  pinMode(Motor2_Geri,OUTPUT);
  pinMode(Motor2_PWM,OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}


void loop() {
  if ( radio.available() ) //Eğer sinyal algılarsan...
  {
    int Y= data[1];
    int X = data[0];
    Serial.print("X=  ");
    Serial.print(data[0]);
    Serial.print("  Y=  ");
    Serial.println(data[1]);
    radio.read( data, sizeof(data) ); 
 //   if(x<=25 && x>=-25) {
   //  digitalWrite(Motor1_Ileri,LOW);
   // digitalWrite(Motor1_Geri,LOW);
   // analogWrite(Motor1_PWM,0);
   // digitalWrite(Motor2_Ileri,LOW);
   // digitalWrite(Motor2_Geri,LOW);
   // analogWrite(Motor2_PWM,0);
   // }
     if(X >= 0 && X <= 90)//İLERİ
     {
     digitalWrite(Motor1_Ileri,HIGH);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,HIGH);
    analogWrite(Motor2_PWM,255);
    }
    if(X >= -90 && X <= 0) //GERİ
    {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,HIGH);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,HIGH);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,255);
    }
    if(Y >= 0 && Y <= 180)//sag 
    {
    digitalWrite(Motor1_Ileri,HIGH);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,255);
    }
   if(Y >= -180 && Y <= 0) //SOL
   {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,HIGH);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,255);
    }
   
  }
}
