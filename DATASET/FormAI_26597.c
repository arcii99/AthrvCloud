//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SPEED 50
#define ACCELERATION 10
#define BRAKING 5

typedef struct {
    char* name;
    int speed;
    bool isMoving;
} Car;

void accelerate(Car* car) {
    if (car->isMoving) {
        if (car->speed + ACCELERATION <= MAX_SPEED) {
            car->speed += ACCELERATION;
        } else {
            car->speed = MAX_SPEED;
        }
    }
}

void brake(Car* car) {
    if (car->isMoving) {
        if (car->speed - BRAKING >= 0) {
            car->speed -= BRAKING;
        } else {
            car->speed = 0;
            car->isMoving = false;
        }
    }
}

void stop(Car* car) {
    car->isMoving = false;
    car->speed = 0;
}

void start(Car* car) {
    car->isMoving = true;
}

void printStatus(Car* car) {
    printf("%s, speed %d km/h, ", car->name, car->speed);
    if (car->isMoving) {
        printf("moving\n");
    } else {
        printf("stopped\n");
    }
}

int main() {
    Car myCar = {.name = "Red Car", .isMoving = false, .speed = 0};

    start(&myCar);
    accelerate(&myCar);
    printStatus(&myCar);

    accelerate(&myCar);
    accelerate(&myCar);
    accelerate(&myCar);
    brake(&myCar);
    printStatus(&myCar);

    brake(&myCar);
    brake(&myCar);
    stop(&myCar);
    printStatus(&myCar);

    return 0;
}