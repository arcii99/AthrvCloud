//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SPEED 80
#define MIN_SPEED 30
#define MAX_DISTANCE 200
#define MIN_DISTANCE 50
#define NUM_OF_CARS 10

struct Car {
    int id;
    int position;
    int speed;
};

typedef struct Car Car;

void print_car(Car car) {
    printf("Car #%d is at position %d and moving with speed %d km/h.\n", car.id, car.position, car.speed);
}

void print_cars(Car cars[], int n) {
    for(int i=0; i<n; i++) {
        print_car(cars[i]);
    }
}

void update_position(Car* car) {
    car->position += car->speed;
}

void check_collision(Car* car1, Car* car2) {
    if((car1->position - car2->position) <= 10) {
        if(car1->speed > car2->speed) {
            car1->speed = (car1->speed + car2->speed) / 2;
            printf("Collision occurred! Car #%d slowed down to %d km/h.\n", car1->id, car1->speed);
        } else if(car1->speed < car2->speed) {
            car2->speed = (car1->speed + car2->speed) / 2;
            printf("Collision occurred! Car #%d slowed down to %d km/h.\n", car2->id, car2->speed);
        } else {
            car1->speed -= 10;
            car2->speed -= 10;
            printf("Collision occurred! Both cars slowed down by 10 km/h.\n");
        }
    }
}

void drive(Car* car, Car* cars[], int n) {
    update_position(car);
    for(int i=0; i<n; i++) {
        if(car->id != cars[i]->id) {
            check_collision(car, cars[i]);
        }
    }
}

bool all_finished(Car cars[], int n) {
    for(int i=0; i<n; i++) {
        if(cars[i].position < 1000) {
            return false;
        }
    }
    return true;
}

void init_cars(Car cars[], int n) {
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        int id = i+1;
        cars[i].id = id;
        cars[i].position = rand() % (MAX_DISTANCE-MIN_DISTANCE+1) + MIN_DISTANCE;
        cars[i].speed = rand() % (MAX_SPEED-MIN_SPEED+1) + MIN_SPEED;
    }
}

int main(void) {
    Car cars[NUM_OF_CARS];
    init_cars(cars, NUM_OF_CARS);
    printf("Initial car positions:\n");
    print_cars(cars, NUM_OF_CARS);
    printf("\n");
    int time = 0;
    while(!all_finished(cars, NUM_OF_CARS)) {
        printf("Time %d:\n", time);
        for(int i=0; i<NUM_OF_CARS; i++) {
            drive(&cars[i], cars, NUM_OF_CARS);
        }
        print_cars(cars, NUM_OF_CARS);
        printf("\n");
        time++;
    }
    return 0;
}