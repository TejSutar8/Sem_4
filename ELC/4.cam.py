import RPi.GPIO as gpio
import picamera
import time
gpio.setmode(gpio.BCM)
gpio.setwarnings(False)

led=21
button=20

HIGH=1
LOW=0

gpio.setup(led, gpio.OUT)
gpio.setup(button, gpio.IN)
gpio.output(led , 0)

data=""

def capture_image():
    data= time.strftime("%d_%b_%Y\%H:%M:%S")
    camera.start_preview()
    time.sleep(5)
    
    camera.capture('/home/pi/VIIT/Camera_PIR/%s.jpg'%data)
    camera.stop_preview()
    time.sleep(2)

camera = picamera.PiCamera()
camera.rotation=180
camera.awb_mode= 'auto'
camera.brightness=55

time.sleep(2)
while 1:
    gpio.output(led, 1)
    if gpio.input(button)==0:
        gpio.output(led, 0)
        time.sleep(0.5)
        capture_image()
    time.sleep(0.5)
