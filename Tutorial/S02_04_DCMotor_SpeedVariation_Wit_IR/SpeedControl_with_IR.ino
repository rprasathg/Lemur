#include <IRremote.h>
int x =0;
int RECV_PIN = 11;
//IR Library stuff
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  // analog read pin to read IR input
  pinMode(11,INPUT);
  // initialize digital out pins needed for 7 segment display
  pinMode(13,OUTPUT); //A
  pinMode(12,OUTPUT); //B
  pinMode(10,OUTPUT); //G
  pinMode(9,OUTPUT); //C
  pinMode(8,OUTPUT); //D
  pinMode(7,OUTPUT); //E
  pinMode(6,OUTPUT); //F
  
  irrecv.enableIRIn(); 
}

void loop() {
  if (x<10)
  { 
        // Diaplaying "0" in 7-segment display
        digitalWrite(7,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
        digitalWrite(12,LOW);
        digitalWrite(10,HIGH);
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
        x++;
  }
  
    if (irrecv.decode(&results)) 
    {//irrecv.decode(&results) returns true if anything is recieved, and stores info in varible results
    unsigned int value = results.value; //Get the value of results as an unsigned int, so we can use switch case
            
      switch (value) {
      case 2295: 
        // mode 1 - motor speed
      	analogWrite(5,50);
        // Diaplaying "1" in 7-segment display
        digitalWrite(8,HIGH);
        digitalWrite(7,HIGH);
        digitalWrite(13,HIGH);
        digitalWrite(10,HIGH);
        digitalWrite(6,HIGH);
        digitalWrite(12,LOW);
        digitalWrite(9,LOW);
      	break;
      
      case 34935:
        // mode 2 - motor speed
        analogWrite(5,100);
        // Diaplaying "2" in 7-segment display
        digitalWrite(9,HIGH);
        digitalWrite(6,HIGH);
        digitalWrite(8,LOW);
        digitalWrite(7,LOW);
        digitalWrite(13,LOW);
        digitalWrite(12,LOW);
        digitalWrite(10,LOW);
      	break;
      
      case 18615:
        // mode 3 - motor speed
        analogWrite(5,250);
        // Diaplaying "3" in 7-segment display
        digitalWrite(7,HIGH);
        digitalWrite(6,HIGH);
        digitalWrite(13,LOW);
        digitalWrite(12,LOW);
        digitalWrite(10,LOW);
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
      	break;
      
      case 255:
        // switching off dc motor
        analogWrite(5,0);
        // Diaplaying "0" in 7-segment display
        digitalWrite(7,LOW);
        digitalWrite(6,LOW);
        digitalWrite(13,LOW);
        digitalWrite(12,LOW);
        digitalWrite(10,HIGH);
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
        //delay (500);
    }
     
    irrecv.resume(); // Receive the next value
  }
  

}
