#include <Servo.h>

Servo serv_1;
Servo serv_2;
Servo serv_3;


int pos_serv_1=0;
int pos_serv_2=0;


boolean serv_1_up=false;
boolean serv_2_up=false;
boolean serv_3_up=false;

void move_serv_1_up();
void move_serv_2_up();
void move_serv_1_down();
void move_serv_2_down();




void setup(){
		serv_1.attach(11);
		serv_2.attach(10);
    serv_3.attach(9);

	}


void loop(){

		serv_1.write(0);
		serv_2.write(0);

		if (serv_1_up=false){
		  move_serv_1_up();
		  }

    if (serv_2_up=false){
      move_serv_2_up();
      }

    if (serv_2_up=true){
      move_serv_2_down();
      }
    if (serv_3_up=false){
      move_serv_2_up();
      }

    if (serv_3_up=true){
      move_serv_2_down();
      }
    
    if (serv_1_up=true){
      move_serv_1_down();
    }
		
		



		delay(7000);
	}



void move_serv_1_up(){

  for (pos_serv_1=0; pos_serv_1 <= 85; pos_serv_1 += 1){
      serv_1.write(pos_serv_1);
      delay(30);
      }
  delay(1000);
  serv_1_up=true;
}


void move_serv_1_down(){

  
    for (pos_serv_1 =85;pos_serv_1 >=0; pos_serv_1  -=1){
      serv_1.write(pos_serv_1);
      delay(15);
      }

  delay(1000);
  serv_1_up=false;
}

void move_serv_2_up(){

  for (pos_serv_2=0; pos_serv_2 <= 45; pos_serv_2 +=1){
      serv_2.write(pos_serv_2);
      delay(50);      
      }
     serv_2_up=true;  
  }


void move_serv_2_down(){
      
    for (pos_serv_2=45; pos_serv_2 >=0; pos_serv_2 -=1){
      serv_2.write(pos_serv_2);
      delay(30);
      }
    
      delay(1000);
      serv_2_up=false;
  
  }
void move_serv_3_up(){

  for (pos_serv_2=0; pos_serv_2 <= 45; pos_serv_2 +=1){
      serv_3.write(pos_serv_2);
      delay(50);      
      }
     serv_2_up=true;  
  }


void move_serv_3_down(){
      
    for (pos_serv_2=45; pos_serv_2 >=0; pos_serv_2 -=1){
      serv_3.write(pos_serv_2);
      delay(30);
      }
    
      delay(1000);
      serv_2_up=false;
  
  }

 
