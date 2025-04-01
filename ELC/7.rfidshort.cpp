#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

MFRC522 rfid(10, 9);
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);
String tag[] = {"A247531C", "B48A&C19"};

void setup()
{
    lcd.begin(16, 2);
    lcd.print("Class Entry");
    delay(1000);
    lcd.clear();
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop()
{
    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
        return;

    String tagRead = getTagString();
    bool authorized = (tag[0] == tagRead || tag[1] == tagRead);

    Serial.print("tag ID: ");
    Serial.println(tagRead);
    Serial.println(authorized ? "Access Granted" : "Access Denied");

    lcd.clear();
    lcd.print(authorized ? "Access Granted" : "Access Denied");

    digitalWrite(authorized ? 3 : 4, HIGH);
    delay(1500);
    digitalWrite(authorized ? 3 : 4, LOW);

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
}

String getTagString()
{
    String tag = "";
    for (byte i = 0; i < rfid.uid.size; i++)
    {
        tag += (rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX);
    }
    tag = tag.toUpperCase();
    return tag;
}