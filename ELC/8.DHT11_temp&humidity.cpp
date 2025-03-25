#include <LiquidCrystal.h>
#include <SimpleDHT.h>

int pinDHT11 = 6;
SimpleDHT11 dht11;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
}

void loop()
{
    Serial.println("=================================");
    Serial.println("DHT11 readings...");
    byte temperature = 0;
    byte humidity = 0;
    int err = SimpleDHTErrSuccess;

    if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
    {
        Serial.print("No reading , err=");
        Serial.println(err);
        delay(1000);
        return;
    }

    Serial.print("Readings: ");
    Serial.print((int)temperature);
    Serial.print(" Celcius, ");
    Serial.print((int)humidity);
    Serial.println(" %");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print((int)temperature);
    lcd.setCursor(0, 1);
    lcd.print("Humidity(%): ");
    lcd.print((int)humidity);
    delay(750);
}