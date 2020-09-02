int pin_motor_a_forward = 5, pin_motor_a_reverse = 3;
int pin_motor_b_forward = 6, pin_motor_b_reverse = 11;
int full_speed = 255, zero_speed = 0;

void setup()
{
  pinMode(pin_motor_a_forward, OUTPUT);
  pinMode(pin_motor_a_reverse, OUTPUT);
  pinMode(pin_motor_b_forward, OUTPUT);
  pinMode(pin_motor_b_reverse, OUTPUT);
}

void loop()
{
  // forward 
  analogWrite(pin_motor_a_forward, full_speed);
  analogWrite(pin_motor_a_reverse, zero_speed);
  analogWrite(pin_motor_b_forward, full_speed);
  analogWrite(pin_motor_b_reverse, zero_speed);
  delay(3000);
  
  // reverse
  analogWrite(pin_motor_a_forward, zero_speed);
  analogWrite(pin_motor_a_reverse, full_speed);
  analogWrite(pin_motor_b_forward, zero_speed);
  analogWrite(pin_motor_b_reverse, full_speed);
  delay(3000);
  
  // brake
  analogWrite(pin_motor_a_forward, full_speed);
  analogWrite(pin_motor_a_reverse, full_speed);
  analogWrite(pin_motor_b_forward, full_speed);
  analogWrite(pin_motor_b_reverse, full_speed); 
  delay(3000);
 }
