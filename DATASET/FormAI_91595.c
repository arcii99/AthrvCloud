//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TOTAL_CARS 200           // Total number of cars in simulation
#define TOTAL_ROADS 5            // Total number of roads in simulation
#define MAX_SPEED 60             // Max speed limit for cars in km/hr
#define MIN_SPEED 30             // Min speed limit for cars in km/hr
#define CAR_LENGTH 4             // Length of car in meters

struct Car {
    int position;               // Current position of car in meters
    int speed;                  // Current speed of car in km/hr
    int road_num;               // Road number on which car is driving
};

typedef struct Car car;

void initiate_cars(car cars[]);
void initiate_roads(int roads[], int size);
void move_cars(car cars[], int roads[], int time);
int check_collision(car cars[], int size, int time);
void print_cars(car cars[], int size);

int main() {
    srand(time(0));
    car cars[TOTAL_CARS];
    int roads[TOTAL_ROADS];
    int time = 0;
    initiate_cars(cars);
    initiate_roads(roads, TOTAL_ROADS);

    while(!check_collision(cars, TOTAL_CARS, time)) {
        printf("Simulation time: %d seconds\n", time);
        move_cars(cars, roads, time);
        print_cars(cars, TOTAL_CARS);
        time++;
    }

    printf("\n\nCRASH OCCURRED AT TIME %d!\n", time);

    return 0;
}

void initiate_cars(car cars[]) {
    int i;
    for(i = 0; i < TOTAL_CARS; i++) {
        cars[i].position = rand() % 100;
        cars[i].speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
        cars[i].road_num = rand() % TOTAL_ROADS;
    }
}

void initiate_roads(int roads[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        roads[i] = rand() % 1000;
    }
}

void move_cars(car cars[], int roads[], int time) {
    int i;
    for(i = 0; i < TOTAL_CARS; i++) {
        int road_length = roads[cars[i].road_num];
        if(cars[i].position >= road_length) {
            cars[i].position = 0;
        } else {
            cars[i].position = cars[i].position + (cars[i].speed * 1000 * (time - 1) / 3600);
        }
    }
}

int check_collision(car cars[], int size, int time) {
    int i, flag = 0;
    for(i = 0; i < size; i++) {
        if(cars[i].position >= cars[i+1].position - CAR_LENGTH && cars[i].speed >= cars[i+1].speed) {
            flag = 1;
            break;
        }
    }
    return flag;
}

void print_cars(car cars[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("Car %d on road %d is at position %d with speed %d km/hr\n", i+1, cars[i].road_num+1, cars[i].position, cars[i].speed);
    }
}