//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct Car {
    int x;
    int y;
    int speed;
    char direction;
} Car;

void moveForward(Car* car);
void turnLeft(Car* car);
void turnRight(Car* car);

int main() {
    srand(time(NULL));
    Car car = {0, 0, 0, 'N'};
    char commands[NUM_COMMANDS][MAX_COMMAND_LENGTH] = {
        "move forward",
        "turn left",
        "turn right",
        "move forward",
        "turn left",
        "move forward",
        "turn right",
        "move forward",
        "move forward",
        "turn left"
    };
    printf("Starting simulation...\n");
    printf("Initial position: x=%d, y=%d, speed=%d, direction=%c\n", car.x, car.y, car.speed, car.direction);
    for (int i = 0; i < NUM_COMMANDS; i++) {
        printf("Executing command: %s\n", commands[i]);
        if (strcmp(commands[i], "move forward") == 0) {
            moveForward(&car);
        } else if (strcmp(commands[i], "turn left") == 0) {
            turnLeft(&car);
        } else if (strcmp(commands[i], "turn right") == 0) {
            turnRight(&car);
        } else {
            printf("Invalid command: %s\n", commands[i]);
        }
        printf("New position: x=%d, y=%d, speed=%d, direction=%c\n", car.x, car.y, car.speed, car.direction);
    }
    printf("Simulation complete.\n");

    return 0;
}

void moveForward(Car* car) {
    int distance = rand() % 10 + 1;
    if (car->direction == 'N') {
        car->y += distance;
    } else if (car->direction == 'S') {
        car->y -= distance;
    } else if (car->direction == 'E') {
        car->x += distance;
    } else if (car->direction == 'W') {
        car->x -= distance;
    }
    car->speed = distance;
}

void turnLeft(Car* car) {
    if (car->direction == 'N') {
        car->direction = 'W';
    } else if (car->direction == 'W') {
        car->direction = 'S';
    } else if (car->direction == 'S') {
        car->direction = 'E';
    } else if (car->direction == 'E') {
        car->direction = 'N';
    }
}

void turnRight(Car* car) {
    if (car->direction == 'N') {
        car->direction = 'E';
    } else if (car->direction == 'E') {
        car->direction = 'S';
    } else if (car->direction == 'S') {
        car->direction = 'W';
    } else if (car->direction == 'W') {
        car->direction = 'N';
    }
}