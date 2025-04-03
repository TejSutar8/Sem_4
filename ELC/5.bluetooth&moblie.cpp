#define GREEN 4
#define RED 3
#define BUZ 2

char switchstate;

void setup()
{
  serial.begin(9600);
  pinMode(GREEN,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(BUZ,OUTPUT);
}

void loop()
{
  if (serial.aviable() > 0) 
  {
    delay(50);
    switchstate = serial.read();
    while (serial.aviable() > 0)
    {
      serial.read();
    }

    digitalWrite(GREEN,LOW);
    digitalWrite(RED,LOW);
    digitalWrite(BUZ,LOW);

    if(switchstate == 'g')
    {
      digitalwrite(GREEN,HIGH);
    }
    else if (switchstate == 'r')
    {
      digitalwrite(RED,HIGH);
    }
    else if (switchstate == 'b')
    {
      digitalwrite(BUZ,HIGH);
      delay(1000);
      digitalwrite(BUZ,LOW):
    }    
  }
  
}