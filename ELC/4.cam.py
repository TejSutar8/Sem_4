import RPi.GPIO as GPIO
import picamera
import time

camera = picamera.PiCamera()
camera.capture('/home/pi/Desktop/image.jpg')
time.sleep(1)
camera.start_recording('/home/pi/Desktop/video.h264')
time.sleep(2)
camera.stop_recording()
camera.close()
