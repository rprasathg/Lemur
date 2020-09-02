void setup()
{
	//PIN configuration
	pinMode(5, OUTPUT); // For PWM led output

	//Set baud rate and begin Serial port
	Serial.begin(9600);
}

void loop()
{

	// Potentiometer variable, updated by Analog read from PIN A0.
	int pot_value = analogRead(A0);

	//Led variable, Brightness of LED is determined by Potentiometer variable. 
	int led_value = map(pot_value, 0, 1023, 0, 255);

	//Write the LED variable into PIN 5(PWM led output)
	analogWrite(5, led_value);
  	delay(1);
}