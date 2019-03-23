#include <LiquidCrystal_I2C.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 20,4);//0x3F, 16, 2
DHT dht(2, DHT11);
void setup()
{
  Serial.begin(9600);
  lcd.init();//20,4);
  dht.begin();
  //lcd.backlight();

  
}

void loop()
{
delay(2000);
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(h) || isnan(t)) {
Serial.println("Не удается считать показания");
return;
}
Serial.print((String)"VLAZHNOST " + h);
Serial.print((String)", Temperature " + t+"\n");
lcd.setCursor(1,1);
//lcd.print((String)"VLAZHNOST " + h);
lcd.print("Hello world");
//lcd.setCursor(1,2);
//lcd.print((String)"Temp " + t);
}
