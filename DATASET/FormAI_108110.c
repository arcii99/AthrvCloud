//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: brave
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define MAX_CARS 10
#define MAX_TIME 60      // 1 hour simulation
#define MAX_SPEED 60     // maximum speed of 60 km/hour
#define MIN_DISTANCE 20  // minimum distance between two cars

struct car {
    int id;
    int speed;
    int pos;
};

void print_cars(struct car c[], int num_cars) {
    printf("Car Details:\n");
    printf("%-10s %-10s %-10s\n", "Car ID", "Speed", "Position");
    for(int i = 0; i < num_cars; i++) {
        printf("%-10d %-10dkm/h %-10dkm\n", c[i].id, c[i].speed, c[i].pos);
    }
}

void print_header() {
    printf("Time\t\t");
    for(int i = 0; i < MAX_CARS; i++) {
        printf("%d\t\t", i+1);
    }
    printf("\n");
}

int main() {
    struct car cars[MAX_CARS];
    srand(time(NULL));

    // initialize cars
    for(int i = 0; i < MAX_CARS; i++) {
        cars[i].id = i+1;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].pos = (i == 0) ? 0 : cars[i-1].pos + rand() % MIN_DISTANCE + MIN_DISTANCE;
    }

    // print initial car locations
    print_cars(cars, MAX_CARS);

    // simulate traffic flow for 1 hour
    for(int t = 0; t < MAX_TIME; t++) {
        print_header();
        printf("%d\t\t", t+1);
        for(int i = 0; i < MAX_CARS; i++) {
            cars[i].pos += cars[i].speed;
            printf("%dkm\t\t", cars[i].pos);
        }
        printf("\n");
    }

    return 0;
}