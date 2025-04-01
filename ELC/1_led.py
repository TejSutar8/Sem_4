import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

LED1=14
LED2=15

GPIO.setup(LED1,GPIO.OUT)
GPIO.setup(LED2,GPIO.OUT)
time.sleep(1)

GPIO.OUT(LED1,True)
GPIO.OUT(LED2,False)
time.sleep(1)

GPIO.OUT(LED1,False)
GPIO.OUT(LED2,True)
time.sleep(1)

GPIO.cleanup()