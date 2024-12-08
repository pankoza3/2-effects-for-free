import tkinter as tk
from tkinter import messagebox
import time
from win32gui import *
from win32con import *
from win32api import *
import random

root = tk.Tk()
root.withdraw()  

response = messagebox.askquestion("malware name by your name"), "Do you want to run this malware?", icon='warning')

if response == 'yes':
 
    response_2 = messagebox.askquestion("malware name by your name"), "Are you sure? ", icon='warning')



hdc = GetDC(0)
effect_duration = 20 


def rainbow_effect():
     
    start_time = time.time()
    while time.time() - start_time < effect_duration:
      
        brush = CreateSolidBrush(RGB(random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)))
        SelectObject(hdc, brush)
        time.sleep(0.02)  
        PatBlt(hdc, 0, 0, 1920, 1080, PATINVERT)
        DeleteObject(brush)
    pygame.mixer.music.stop()



def move_screen_down():
  
    start_time = time.time()

    while time.time() - start_time < effect_duration:
        
        BitBlt(hdc, 0, 5, 1920, 1080, hdc, 0, 0, SRCCOPY)
        time.sleep(0.02)  





rainbow_effect()  
move_screen_down()  

ReleaseDC(0, hdc)



