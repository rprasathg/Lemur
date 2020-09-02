#include <LiquidCrystal.h>

//https://www.arduino.cc/en/Reference/LiquidCrystalConstructor
LiquidCrystal lcd(2, 3, 8, 9, 10, 11);

float old_temperature = 0, old_light = 0, light = 0, temperature = 0, voltage=0;
int value = 0, duration = 0;

void setup() 
{
  lcd.begin(16, 2);
}

void loop() 
{

  //Convert the sensor measurement to temperature
  value = analogRead(A5);
  voltage = value * 5;
  voltage = voltage / 1024;
  temperature = (voltage - 0.5) * 100; 
  
  //Read LDR input
  light = analogRead(A4);
  
  if(old_temperature != temperature || old_light != light)
  {
    lcd.clear();
  }
  
  //display the change in temperature and Light
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)0xB0);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(light);
  
  old_temperature = temperature;
  old_light = light;
}
