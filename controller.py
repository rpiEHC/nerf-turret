import pygame, sys
import serial
import time
import re
import os

arduino_port = '/dev/' + [term for term in os.listdir('/dev/') if re.search(r'tty(ACM|USB)[0-9]+', term)][0]

ser = serial.Serial(arduino_port, 9600)

white = (255, 255, 255)
red = (255, 0, 0)

pygame.init()
pygame.display.set_caption('Keyboard Example')
size = [5, 5]
screen = pygame.display.set_mode(size)
clock = pygame.time.Clock()

# by default the key repeat is disabled
# call set_repeat() to enable it
pygame.key.set_repeat(50, 50)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        # check if key is pressed
        # if you use event.key here it will give you error at runtime
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                ser.write('L')
                time.sleep(.05)
            if event.key == pygame.K_RIGHT:
                ser.write('R')
                time.sleep(.05)
            if event.key == pygame.K_UP:
                ser.write('f')
                time.sleep(1)

            # checking if left modifier is pressed
            if pygame.key.get_mods() & pygame.KMOD_LSHIFT:
                pass

    screen.fill(white)

    pygame.display.update()
    clock.tick(20)
