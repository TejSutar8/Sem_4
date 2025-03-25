void setup()
{
    serial.begin(9600);
}

void loop()
{
    float TempLM35, pot;
    char sign = 223;
    TempLM35 = analogRead(A0);
    delay(100);
    pot = analogRead(A1);
    serial.print(TempLM35 * 0.48828125);
    serial.print(sign);
    serial.ptint("C ");
    serial.print(pot * 0.48828125 / 100);
    serial.print("V\n");
    serial.print(1000);
}