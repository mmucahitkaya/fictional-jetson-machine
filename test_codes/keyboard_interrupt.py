import jetson.inference
import jetson.utils
import keyboard
import os
from datetime import datetime

cam = jetson.utils.gstCamera(640,480,'/dev/video0')
disp = jetson.utils.glDisplay()
font = jetson.utils.cudaFont()


while disp.IsOpen():
    frame, width, height = cam.CaptureRGBA()
    dt = str(datetime.now()) 
    disp.RenderOnce(frame, width, height)

    if keyboard.is_pressed('q'):
        filename = 'detected_' + dt + '.jpg'
        print('hi')
        jetson.utils.saveImageRGBA(filename,frame,width,height)
