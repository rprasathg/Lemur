bool run = true;
int interrupt_pin_rising = 2, interrupt_pin_falling = 3;

void setup()
{

  attachInterrupt(digitalPinToInterrupt(interrupt_pin_rising), motion_detected, RISING);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin_falling), motion_reset, FALLING);
  Serial.begin(9600);
}

void loop()
{
  if(run)
  {
    analogWrite(A0, 150);
  }
  else
  {
    analogWrite(A0, 0);
  }
}

void motion_detected()
{
  Serial.println("motion detected");
  run = false;
}

void motion_reset()
{
  Serial.println("motion reset");
  run = true;
}
