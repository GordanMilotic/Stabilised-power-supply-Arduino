

#include <LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int DHTPIN = 2; 
int DHTTYPE = DHT22;  
DHT dht(DHTPIN, DHTTYPE);
float temp;
int fan = 9;

void setup(){
  lcd.init();
  lcd.backlight();
  dht.begin();
  Serial.begin(9600);
  analogWrite(fan, 255);
}

void loop(){
  temp = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  if(temp > 30) {
    lcd.print("Fan: ON ");
  } else {
    lcd.print("Fan: OFF");
  }
 
  if(temp > 30) {
      analogWrite(fan, 255);
    } else {
      analogWrite(fan, 0);
    }
}
