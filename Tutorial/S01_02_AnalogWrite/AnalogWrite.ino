void setup()
{
  pinMode(5, OUTPUT); // For PWM led output
  Serial.begin(9600);
}

void loop()
{
  int pot_value = analogRead(A0);
  int led_value = map(pot_value, 0, 1023, 0, 255);
  analogWrite(5, led_value);
  delay(1);
}