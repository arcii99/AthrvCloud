//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int fuel = 100;
int distance = 0;
int speed = 0;

// Function prototypes
void printStatus();
void increaseSpeed();
void decreaseSpeed();

int main() {
    srand(time(NULL));

    printStatus();

    while (fuel > 0 && distance < 100) {
        int random = rand() % 10;

        if (random < 3) {
            decreaseSpeed();
        } else if (random < 6) {
            increaseSpeed();
        }

        fuel--;
        distance += speed;

        printStatus();
    }

    if (distance >= 100) {
        printf("Congratulations! You have reached your destination.");
    } else {
        printf("Oh no! You have run out of fuel before reaching your destination.");
    }

    return 0;
}

void printStatus() {
    printf("Fuel: %d\n", fuel);
    printf("Distance: %d\n", distance);
    printf("Speed: %d\n", speed);
}

void increaseSpeed() {
    if (fuel < 5) {
        printf("Not enough fuel to increase speed.\n");
    } else {
        fuel -= 5;
        speed += 10;
    }
}

void decreaseSpeed() {
    if (speed > 0) {
        speed -= 5;
    } else {
        printf("Vehicle has stopped.\n");
    }
}