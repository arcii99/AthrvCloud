//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 5

typedef struct {
    int id;
    int speed;
    int position;
} Car;

void initialize(Car cars[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].position = i * 10;
    }
}

void display(Car cars[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Car # %d | Speed: %d | Position: %d\n", cars[i].id, cars[i].speed, cars[i].position);
    }
}

void update(Car cars[], int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cars[i].position += cars[i].speed;
        } else {
            int distance = cars[i].position - cars[i-1].position;
            if (distance > 10) {
                cars[i].position -= (distance - 10);
            } else {
                cars[i].position += cars[i].speed;
            }
        }
    }
}

int main() {
    Car cars[MAX_CARS];
    int n_cars = 5; // the number of cars in the simulation
    initialize(cars, n_cars);

    printf("Initial state:\n");
    display(cars, n_cars);
    printf("\n");

    int time = 1;
    while (time <= 10) {
        printf("Time %d:\n", time);
        update(cars, n_cars);
        display(cars, n_cars);
        printf("\n");
        time++;
    }

    return 0;
}