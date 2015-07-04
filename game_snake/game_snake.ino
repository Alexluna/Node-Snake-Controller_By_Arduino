 // BLUETOOTH MODO ESCLAVO
 
#include <SoftwareSerial.h>

const int up_button = 12;     //  up -> 1
const int down_button = 11;     //   +down ->2
//const int left_button = 10;     //   +LEFT ->3
//const int right_button = 9;     //   +RIGHT ->4
const int ledPin =  13;       // the number of the LED pin
 
 
int num_send = 0;

SoftwareSerial blue(2, 3 );
// blue is the instance for use that device
 
// TX , RX in blue ports - RX bluetooth port to pin X in arduino
// since 3 is the port 3 in arduino , we'll send data through this port

int pot=0;

void setup(){
  blue.begin(9600);
   Serial.begin(9600);
  blue.println("Conectado");
  

    // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);  
  
  // initialize the pushbutton pin as an input:
  pinMode(up_button, INPUT); 
  pinMode(down_button, INPUT); 
  /*
    pinMode(left_button, INPUT); 
  pinMode(right_button, INPUT); 
  */
  
}
void loop(){

  move_snake();
}

  //********************************************************************
 //********************************************************************
 

 
void move_snake(){ 
    
   num_send = 0;
 
   // READ PUSHBUTTON
   int u_button = digitalRead(up_button);
   int d_button = digitalRead(down_button);
   // int l_button = digitalRead(down_button);
   //  int r_button = digitalRead(down_button);
   
   // ARRIBA (UP)
   if(  u_button == HIGH ){
     // is the same state ** means its the first time executing **
     delay(200);
     num_send = 1;
     blue.println( num_send );
     Serial.println(num_send);
   } 
   
   
      // DOWN (abajo)
   if(  d_button  == HIGH ){
     // is the same state ** means its the first time executing **
     num_send = 2;
       delay(200);
     blue.println( num_send );
     Serial.println(num_send);
   }
   
   
     /* 
      // LEFT  (abajo)
   if(  l_button  == HIGH ){
     // is the same state ** means its the first time executing **
     num_send = 3;
       delay(200);
     blue.println( num_send );
     Serial.println(num_send);
   }
   
   
         // RIGHT  (abajo)
   if(  r_button  == HIGH ){
     // is the same state ** means its the first time executing **
     num_send = 4;
       delay(200);
     blue.println( num_send );
     Serial.println(num_send);
   }
   */
}

