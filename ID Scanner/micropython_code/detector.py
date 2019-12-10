import sensor,image,lcd
import KPU as kpu
from fpioa_manager import *
import os, Maix, lcd, image
from Maix import FPIOA, GPIO
from machine import UART
import time
import syslog
fpioa = FPIOA()

uart = UART(1, 9600)
uart.init(9600, bits=8, parity=None, stop=1)


#enable_pin = 23
#out_pin = 22
#fpioa.set_function( enable_pin, FPIOA.GPIO6 )
#fpioa.set_function( out_pin, FPIOA.GPIO5 )
#enable_gpio = GPIO(GPIO.GPIO6, GPIO.OUT)
#out_gpio = GPIO(GPIO.GPIO5, GPIO.OUT)


print("INITIALIZATION")
lcd.init(freq=15000000)
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.set_windowing((224, 224))
sensor.set_vflip(1)
sensor.run(1)
print("SENSOR RUN")

classes = ["racoon"]
#task = kpu.load(0x300000)
task = kpu.load('/sd/model.kmodel')
print("LOAD MODEL")
anchor = (0.57273, 0.677385, 1.87446, 2.06253, 3.33843, 5.47434, 7.88282, 3.52778, 9.77052, 9.16828)
a = kpu.init_yolo2(task, 0.3, 0.3, 5, anchor)
print("INIALIZE KPU")
detected = False
#out_gpio.value(0)
#enable_gpio.value(0)
while(True):
    img = sensor.snapshot()
    #print("SNAPSHOT")
    #.rotation_corr(z_rotation=90.0)
    #a = img.pix_to_ai()
    code = kpu.run_yolo2(task, img)
    if code:
        for i in code:
            a=img.draw_rectangle(i.rect(),color = (0, 255, 0))
            a = img.draw_string(i.x(),i.y(), classes[i.classid()], color=(255,0,0), scale=3)
        a = lcd.display(img)
        #out_gpio.value(1)
        #enable_gpio.value(1)
        detected = True

        uart.write('1')
        a = lcd.draw_string(50, 50, "Detected", lcd.BLACK, lcd.WHITE)
        break
        #print("YES CODE")
    else:
        a = lcd.display(img)

        #print("NO CODE")

a = kpu.deinit(task)
