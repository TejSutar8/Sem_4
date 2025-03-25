#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9

#define LCD_D4 A0
#define LCD_D5 A1
#define LCD_D6 A2
#define LCD_D7 A3

#define LCD_EN A4
#define LCD_RS A5

#define OK_LED 3
#define ERROR_BUZ 4

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
// 924ECA1C -RFID card
// 89E387A3 -RFID card

boolean My_Card = false;

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;
int My_RFID_Tag[4] = {0X92, 0X69, 0X32, 0X1C};
byte nuidPICC[4];
String lastSent;

void setup()
{

    pinMode(OK_LED, OUTPUT);
    pinMode(ERROR_BUZ, OUTPUT);

    digitalWrite(OK_LED, LOW);
    digitalWrite(ERROR_BUZ, LOW);

    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("--FCT India--");
    delay(1000);

    Serial.setTimeout(30);
    Serial.begin(9600);
    SPI.begin();     // Init SPI bus
    rfid.PCD_Init(); // Init MFRC522
}

void loop()
{
    lcd.clear();
    lcd.print("Put Your ID-Card ");
    My_Card = true;

    if (!rfid.PICC_IsNewCardPresent())
        return;

    if (!rfid.PICC_ReadCardSerial())
        return;

    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

    if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
        piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
        piccType != MFRC522::PICC_TYPE_MIFARE_4K)
    {
        return;
    }
    printHex(rfid.uid.uidByte, rfid.uid.size); // display card number on serial monitor
    Serial.println();
    delay(500);

    for (int i = 0; i < 4; i++)
    {
        if (My_RFID_Tag[i] != rfid.uid.uidByte[i])
        {
            My_Card = false;
            break;
        }
    }
    Serial.println();

    if (My_Card)
    {
        Serial.println("\nWelcome To Class Room ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Welcome to Class");
        lcd.setCursor(0, 1);
        lcd.print("Access Granted");
        delay(1000); // Turn on the Green LED as an indication of permission is given to access the class room.
        digitalWrite(ERROR_BUZ, LOW);
        digitalWrite(OK_LED, HIGH);
        delay(10000);
        digitalWrite(OK_LED, LOW);
    }
    else
    {
        Serial.println("\n Don't enter in the Class Room");
        lcd.clear();
        lcd.print("Card NOT FOUND!");
        lcd.setCursor(0, 1);
        lcd.print("Access Denied");
        delay(1500);
        digitalWrite(OK_LED, LOW);
        digitalWrite(ERROR_BUZ, HIGH);
        delay(1500);
        digitalWrite(ERROR_BUZ, LOW);
    }
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
}

void printHex(byte *buffer, byte bufferSize)
{
    lastSent = "";
    for (byte i = 0; i < bufferSize; i++)
    {
        byte n1 = (buffer[i] >> 4) & 0x0F;
        byte n2 = buffer[i] & 0x0F;
        lastSent += n1 < 10 ? '0' + n1 : 'A' + (n1 - 10);
        lastSent += n2 < 10 ? '0' + n2 : 'A' + (n2 - 10);
        Serial.print(buffer[i] < 0x10 ? "0" : "");
        Serial.print(buffer[i], HEX);
    }
}
