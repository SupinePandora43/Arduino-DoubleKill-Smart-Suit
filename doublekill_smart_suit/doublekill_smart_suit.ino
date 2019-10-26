#include <Adafruit_Sensor.h>
#include <math.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS1307);
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(2, DHT11);

byte customChar[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup()
{
  Serial.begin(9600);
  lcd.init();
  dht.begin();
  lcd.backlight();
  lcd.createChar(0, customChar);
  delay(300);
  Serial.begin(9600);
  time.begin();
  //time.settime(0,58,9,26,10,19,6);  // 0  сек, 51 мин, 21 час, 27, октября, 2015 года, вторник
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
  Serial.print((String)", Temperature " + t + "\n");
  //lcd.setCursor(0,0);
  //lcd.print((String)"VLAZHNOST " + h);

  lcd.setCursor(0, 1);
  lcd.print(t);
  lcd.write(0);
  lcd.print((String)"," +round(h)+(String) "%");
  lcd.setCursor(0, 0);
  //if(millis()%1000==0){ // если прошла 1 секунда
  lcd.print(time.gettime("d-m-Y,H:i:s,D")); // выводим время
  delay(1); // приостанавливаем на 1 мс, чтоб не выводить время несколько раз за 1мс
  //}
}
