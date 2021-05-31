from random import randint

import pygame
import serial


HEIGHT = 800
WIDTH = 800


class Player:
    def __init__(self):
        self.x = 50
        self.y = HEIGHT // 2

    def draw(self, screen):
        pygame.draw.circle(screen, (100, 0, 100), (self.x, self.y), 25)

    def update_pos(self, serial_data):
        if serial_data.in_waiting > 0:
            self.y = int(serial_data.readline().decode()) * 25

    def death(self):
        print("You are dead")
        quit()


class Pipe:
    def __init__(self, screen):
        self.spawn()
        self.top

    def spawn(self):
        self.width = 50
        self.height = randint(250, 500)

        self.x = WIDTH
        if randint(0, 1) == 0:
            self.y = HEIGHT - self.height
            self.top = False
        else:
            self.y = 0
            self.top = True

        self.rect = pygame.Rect((self.x, self.y), (self.width, self.height))


    def update(self):
        self.x -= 10
        self.rect = pygame.Rect((self.x, self.y), (self.width, self.height))

    def draw(self, screen):
        pygame.draw.rect(screen, (200, 200, 200), self.rect)


def draw(screen, pipes, player):
    # fill the background
    screen.fill((20, 20, 20))

    # draw player
    player.draw(screen)

    # draw pipes
    for pipe in pipes:
        pipe.draw(screen)

    pygame.display.flip()


def main():
    pygame.init()

    player = Player()

    clock = pygame.time.Clock()
    last_time = 2000

    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    serial_data = serial.Serial("/dev/ttyUSB0", 9600)

    running = True

    pipes = []

    while running:
        time = clock.tick(60)
        last_time += time

        if last_time > 1500:
            pipes.append(Pipe(screen))
            last_time = 0

        for i, pipe in enumerate(pipes):
            pipe.update()
            if pipe.x < -100:
                pipes.pop(i)

            if pipe.x < player.x:
                if pipe.top and pipe.y + pipe.height > player.y:
                    player.death()
                if not pipe.top and pipe.y < player.y:
                    player.death()

        player.update_pos(serial_data)
        draw(screen, pipes, player)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False


if __name__ == "__main__":
    main()
