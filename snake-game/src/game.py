from random import randint
from time import sleep
import pygame
import serial


WIDTH = 800
HEIGHT = 800

block_size = 10

arduino_serial_data = serial.Serial("/dev/ttyUSB0", 9600, timeout = 5)
screen = pygame.display.set_mode((HEIGHT, WIDTH))


class Apple:
    def __init__(self):
        self.spawn()


    def draw(self):
        rect = pygame.Rect(self.x, self.y, block_size, block_size)
        pygame.draw.rect(screen, (200, 50, 50), rect)


    def spawn(self):
        self.x = randint(10, WIDTH / 10) * 10 - 10
        self.y = randint(10, HEIGHT / 10) * 10 - 10


class Snake:
    def __init__(self, size, color):
        self.x = []
        self.y = []
        self.size = size
        self.color = color
        self.dx = 0
        self.dy = 0

        for i in range(self.size):
            self.x.append(400)
            self.y.append(400)


    def draw(self):
        for i in range(self.size):
            rect = pygame.Rect(self.x[i], self.y[i], block_size, block_size)
            pygame.draw.rect(screen, self.color, rect)


    def move(self):
        direction = 0
        movement = get_serial_data()

        if movement[0] < 250 and self.dx == 0:
            self.dx = -1 # West
            self.dy = 0
        if movement[0] > 750 and self.dx == 0:
            self.dx = 1 # East
            self.dy = 0
        if movement[1] < 250 and self.dy == 0:
            self.dy = -1 # North
            self.dx = 0
        if movement[1] > 750 and self.dy == 0:
            self.dy = 1 # South
            self.dx = 0

        self.x.insert(0, self.x[0] + block_size * self.dx)
        self.y.insert(0, self.y[0] + block_size * self.dy)
        self.x.pop()
        self.y.pop()

        if self.x[0] > HEIGHT:
            self.x[0] = 0
        elif self.x[0] < 0:
            self.x[0] = WIDTH
            dx = -1
        if self.y[0] > WIDTH:
            self.y[0] = 0
        elif self.y[0] < 0:
            self.y[0] = HEIGHT
            dy = -1


    def grow(self):
        self.size += 1
        self.x.insert(0, self.x[0] + block_size * self.dx)
        self.y.insert(0, self.y[0] + block_size * self.dy)


def get_serial_data():
    while arduino_serial_data.in_waiting < 0:
        pass

    data = arduino_serial_data.readline().decode("utf-8")
    dataArray = data.split()
    serial_data = [int(i) for i in dataArray]

    return serial_data


def scene_draw():
    screen.fill((10, 10, 10))

def main():
    pygame.init()
    clock = pygame.time.Clock()
    running = True
    action_time = 0

    snake = Snake(5, (50, 200, 50))
    apple = Apple()


    while running:
        time = clock.tick()
        action_time += time

        print(get_serial_data())

        if apple.x == snake.x[0] and apple.y == snake.y[0]:
            snake.grow()
            apple.spawn()

        if action_time > 100:
            if get_serial_data()[2] == 0:
                apple.spawn()
            snake.move()
            action_time = 0

        scene_draw()
        apple.draw()
        snake.draw()
        pygame.display.flip()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

if __name__ == "__main__":
    main()
