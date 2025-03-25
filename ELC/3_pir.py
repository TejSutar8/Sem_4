import PRi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwargnings(False)

PIR_input = 21
BUZZ = 20

GPIO.setup(PIR_input,GPIO.IN)
GPIO.setup(BUZZ,GPIO.OUT)
GPIO.output(BUZZ,GPIO.LOW)

while True:
    if(GPIO.input(PIR_input)):
        GPIO.output(BUZZ,GPIO.HIGH)
    else:
        GPIO.output(BUZZ,GPIO.LOW)