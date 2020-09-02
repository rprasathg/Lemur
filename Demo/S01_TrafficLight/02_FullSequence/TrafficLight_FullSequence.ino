// max - 4,294,967,295 - https://www.arduino.cc/reference/en/language/variables/data-types/unsignedlong/
unsigned long ped_timer_start = 0; 

// flags to detect if pedestrian switch is pressed
bool ped_start_task = false, ped_run_task = false; 
bool first_flag = true;
bool wait_and_on = false;

#define pedestrian_red 13
#define pedestrian_green 12

#define vehichle_red 5
#define vehichle_yellow 4
#define vehichle_green 3

void setup() 
{
  
  //PIN Configuration
  pinMode(8, INPUT);
  pinMode(pedestrian_red, OUTPUT); 
  pinMode(pedestrian_green, OUTPUT); 
  pinMode(vehichle_red, OUTPUT); 
  pinMode(vehichle_yellow, OUTPUT); 
  pinMode(vehichle_green, OUTPUT); 
}

void loop() 
{
  //Read Pedestrian Switch
  ped_start_task = digitalRead(8) == 1 ? true: false;
  
  //Flag for first run, sequence flag, minimum delay for switch
  if(ped_start_task || ped_run_task || wait_and_on)
  {
    if ( (ped_start_task) || ( wait_and_on) )
    {
      if(((millis() - ped_timer_start) >= 3000) || (first_flag))
      {
         ped_run_task = true;
         ped_timer_start = millis();
         first_flag = false;
        wait_and_on = false;
        ped_start_task = false;
       } 
       else
       {
         wait_and_on = true;
       }
    }
    else //sequence flag
    {
     if((millis() - ped_timer_start) >= 1400)
      {
        ped_run_task = false;
        ped_start_task = false;
        //ped_timer_start = 0;
      }
       else if((millis() - ped_timer_start) >= 1200)
      {
        digitalWrite(vehichle_green, LOW);
        digitalWrite(vehichle_red, LOW);
        digitalWrite(pedestrian_green, LOW);
        digitalWrite(vehichle_yellow, HIGH);
        digitalWrite(pedestrian_red, HIGH);
       }
      else if((millis() - ped_timer_start) >= 1000)
      {
        digitalWrite(vehichle_green, LOW);
        digitalWrite(vehichle_yellow, LOW);
        digitalWrite(pedestrian_green, LOW);
        digitalWrite(pedestrian_red, HIGH);
        digitalWrite(vehichle_red, HIGH);
       }
       else if((millis() - ped_timer_start) >= 500)
      {
        digitalWrite(vehichle_green, LOW);
        digitalWrite(vehichle_yellow, LOW);
        digitalWrite(pedestrian_red, LOW);
        digitalWrite(vehichle_red, HIGH);
        digitalWrite(pedestrian_green, HIGH);
       }
       else if((millis() - ped_timer_start) >= 400)
      {
        digitalWrite(vehichle_green, LOW);
        digitalWrite(vehichle_yellow, LOW);
        digitalWrite(pedestrian_red, LOW);
        digitalWrite(pedestrian_green, LOW);
        digitalWrite(vehichle_red, HIGH);
      }
      else if((millis() - ped_timer_start) >= 200 )
      {
        digitalWrite(vehichle_red, LOW);
        digitalWrite(pedestrian_green, LOW);
        digitalWrite(vehichle_green, LOW);
        digitalWrite(pedestrian_red, HIGH);
        digitalWrite(vehichle_yellow, HIGH);
      }
    
    }
  }
  else //default flow of traffic
  {
    digitalWrite(vehichle_yellow, LOW);
    digitalWrite(vehichle_red, LOW);
    digitalWrite(pedestrian_green, LOW);
    digitalWrite(pedestrian_red, HIGH);
    digitalWrite(vehichle_green, HIGH);
  } 
}

