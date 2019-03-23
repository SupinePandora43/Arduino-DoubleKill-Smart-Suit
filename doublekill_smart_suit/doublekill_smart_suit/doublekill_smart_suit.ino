#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS1307);
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(2, DHT11);
void setup()
{
  Serial.begin(9600);
  lcd.init();
  dht.begin();
  lcd.backlight();
  delay(300);
    Serial.begin(9600);
    time.begin();
    time.settime(0,51,21,27,10,15,2);  // 0  сек, 51 мин, 21 час, 27, октября, 2015 года, вторник
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
//lcd.setCursor(0,0);
//lcd.print((String)"VLAZHNOST " + h);

lcd.setCursor(0,1);
lcd.print((String)"Temp " + t);
lcd.setCursor(0,0);
//if(millis()%1000==0){ // если прошла 1 секунда
      lcd.print(time.gettime("d-m-Y, H:i:s, D")); // выводим время
      delay(1); // приостанавливаем на 1 мс, чтоб не выводить время несколько раз за 1мс
//}
}
