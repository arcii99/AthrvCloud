//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 5
#define MAX_TIME 100

typedef struct car {
    int position;
    int speed;
} Car;

Car cars[MAX_CARS];
int num_cars = 0;

void move_cars() {
    for (int i = 0; i < num_cars; i++) {
        cars[i].position += cars[i].speed;
        if (cars[i].position >= MAX_TIME) {
            cars[i].position = MAX_TIME - 1;
            cars[i].speed = 0;
        }
    }
}

void accelerate_cars() {
    for (int i = 0; i < num_cars; i++) {
        if (cars[i].speed < MAX_SPEED) {
            cars[i].speed++;
        }
    }
}

void decelerate_cars() {
    for (int i = 0; i < num_cars; i++) {
        for (int j = i + 1; j < num_cars; j++) {
            int distance = cars[j].position - cars[i].position;
            if (distance <= cars[i].speed) {
                cars[i].speed = distance - 1;
                if (cars[i].speed < 0) {
                    cars[i].speed = 0;
                }
            }
        }
    }
}

void print_cars() {
    char road[MAX_TIME];
    for (int i = 0; i < MAX_TIME; i++) {
        road[i] = '-';
    }
    for (int i = 0; i < num_cars; i++) {
        road[cars[i].position] = 'X';
    }
    printf("%s\n", road);
}

int main() {
    srand(time(NULL));
    num_cars = rand() % MAX_CARS;
    for (int i = 0; i < num_cars; i++) {
        cars[i].position = rand() % MAX_TIME;
        cars[i].speed = rand() % MAX_SPEED;
    }
    for (int i = 0; i < MAX_TIME; i++) {
        printf("time %d:\n", i);
        print_cars();
        decelerate_cars();
        move_cars();
        accelerate_cars();
    }
    return 0;
}