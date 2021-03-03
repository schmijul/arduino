#include <Servo.h>

Servo ser_1;
Servo ser_2;
Servo ser_3;
boolean dir=true;





void setup(){
  
  ser_1.attach(11);
  ser_2.attach(9);
  ser_3.attach(7);
  
    ser_1.write(0);
    ser_2.write(0);
    ser_3.write(0);
 
  
  }


void loop(){

  
    delay(3000);
    move_ser(dir,1,90);
    move_ser(dir,2,40);
    move_ser(dir,3,80);
    
    delay(3000);
    move_ser(false,3,80);
    move_ser(false,2,40);
    move_ser(false,1,90);
    
  }



void move_ser(boolean dir, int ser, int angle){

    int pos_ser;
  
  if(dir==true && pos_ser !=80){

    
  for (pos_ser=0; pos_ser <=angle; pos_ser +=1){
     

    if (ser==1){
    ser_1.write(pos_ser);}
    
    if (ser==2){
      ser_2.write(pos_ser);}
    
    if (ser==3){
      ser_3.write(pos_ser);}
  
  delay(30);
    
  
    }
  dir=false;
    
    }

 
  else{

  for (pos_ser =angle;pos_ser >=0; pos_ser  -=1){
    
          if (ser==1){
          ser_1.write(pos_ser);}
    
          if (ser==2){
          ser_2.write(pos_ser);}
    
          if (ser==3){
          ser_3.write(pos_ser);}

          delay(30);
    

    
  dir=true;}
 
  }}
