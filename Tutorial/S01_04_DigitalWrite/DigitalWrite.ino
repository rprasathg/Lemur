void setup()
{
  //PIN configuration for LED - Digital Out
  pinMode(5, OUTPUT); // For triggering blue light
  pinMode(6, OUTPUT); // For triggering green light
  pinMode(7, OUTPUT); // For triggering red light

  //PIN configuration for Switch - Digital In
  pinMode(11, INPUT); // For blue switch
  pinMode(12, INPUT); // For green switch
  pinMode(13, INPUT); // For red switch
}

void loop()
{

  //Read the input from Switch
  int red_switch = digitalRead(13);
  int green_switch = digitalRead(12);
  int blue_switch = digitalRead(11);
  
  //Turn the LED ON - based on the switch selection
  if(red_switch == 1)
  {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  else if(green_switch == 1)
  {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
  else if(blue_switch == 1)
  {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
}