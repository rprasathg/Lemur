// max - 4,294,967,295 - https://www.arduino.cc/reference/en/language/variables/data-types/unsignedlong/
unsigned long ped_timer_start = 0; 

// flags to detect if pedestrian switch is pressed
bool ped_start_task = false, ped_run_task = false; 

#define pedestrain_switch 8

#define pedestrian_red 13
#define pedestrian_green 12

#define vehichle_red 5
#define vehichle_yellow 4
#define vehichle_green 3

void setup() 
{
  // defining the INPUT and OUTPUT pins to be used
  pinMode(pedestrain_switch, INPUT);
  
  pinMode(pedestrian_red, OUTPUT); 
  pinMode(pedestrian_green, OUTPUT); 
  
  pinMode(vehichle_red, OUTPUT); 
  pinMode(vehichle_yellow, OUTPUT); 
  pinMode(vehichle_green, OUTPUT); 
}

void loop() 
{
  // store value 1 if the pedestrian switch is pressed
  ped_start_task = digitalRead(pedestrain_switch) == 1 ? true: false;
  
  
  if(ped_start_task || ped_run_task)
  {
    if(ped_start_task)
    {
      // Read current timer value
      ped_timer_start = millis();
      // Set flag to indicate that the pedestrian switch was pressed
      ped_run_task = true;
    }
    else
    {
     if((millis() - ped_timer_start) >= 800) 
      {
       // default state : Pedestrian RED, Vehicle Traffic GREEN 
       ped_run_task = false;
        ped_start_task = false;
        ped_timer_start = 0;
      }
       else if((millis() - ped_timer_start) >= 400)
      {
        // Pedestrian GO state: Pedestrian GREEN, Vehicle Traffic RED
        digitalWrite(vehichle_green, LOW);
        digitalWrite(vehichle_yellow, LOW);
        digitalWrite(pedestrian_red, LOW);
        digitalWrite(vehichle_red, HIGH);
        digitalWrite(pedestrian_green, HIGH);
      }
      else if((millis() - ped_timer_start) >= 200 )
      {
        // Vehicle READY state: Pedestrian GREEN, Vehicle Traffic RED
        digitalWrite(vehichle_red, LOW);
        digitalWrite(pedestrian_green, LOW);
        digitalWrite(vehichle_green, LOW);
        digitalWrite(pedestrian_red, HIGH);
        digitalWrite(vehichle_yellow, HIGH);
      }
    
    }
  }
  else
  {
    // default state : Pedestrian RED, Vehicle Traffic GREEN
    digitalWrite(vehichle_yellow, LOW);
    digitalWrite(vehichle_red, LOW);
    digitalWrite(pedestrian_green, LOW);
    digitalWrite(pedestrian_red, HIGH);
    digitalWrite(vehichle_green, HIGH);
  } 
}

