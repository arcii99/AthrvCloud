//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ACCELERATION 5
#define BREAKING 10
#define MAX_SPEED 50
#define MAX_CARS 10

typedef struct car{
    int pos;
    int speed;
} Car;

void generateRandomPositions(Car *cars, int num_cars);
void printCars(Car *cars, int num_cars);
void simulateTrafficFlow(Car *cars, int num_cars);
void moveCars(Car *cars, int num_cars);
void accelerateCars(Car *cars, int num_cars);
void brakeCars(Car *cars, int num_cars, int distance); 

int main(){
    srand(time(0));
    Car cars[MAX_CARS];
    generateRandomPositions(cars, MAX_CARS);
    printf("Initial state of traffic flow:\n");
    printCars(cars, MAX_CARS);
    simulateTrafficFlow(cars, MAX_CARS);
    return 0;
}

void generateRandomPositions(Car *cars, int num_cars){
    int i;
    cars[0].pos = rand()%50;
    cars[0].speed = 0;
    for(i=1; i<num_cars; i++){
        cars[i].pos = cars[i-1].pos + rand()%30 + 20;
        cars[i].speed = rand()%MAX_SPEED;
    }
}

void printCars(Car *cars, int num_cars){
    int i;
    for(i=0; i<num_cars; i++){
        printf("Car %d - Position: %d, Speed: %d\n", i, cars[i].pos, cars[i].speed);
    }
}

void simulateTrafficFlow(Car *cars, int num_cars){
    int i;
    int time = 0;
    int num_collisions = 0;
    while(time<100){
        moveCars(cars, num_cars);
        accelerateCars(cars, num_cars);
        brakeCars(cars, num_cars, 10);
        printf("State of traffic flow at time %d:\n", time);
        printCars(cars, num_cars);
        for(i=0; i<num_cars-1; i++){
            if(cars[i+1].pos - cars[i].pos < 5){
                num_collisions++;
                printf("Collision between Car %d and Car %d at time %d\n", i, i+1, time);
            }
        }
        time++;
    }
    printf("Number of collisions: %d\n", num_collisions);
}

void moveCars(Car *cars, int num_cars){
    int i;
    for(i=0; i<num_cars; i++){
        cars[i].pos += cars[i].speed;
    }
}

void accelerateCars(Car *cars, int num_cars){
    int i;
    for(i=0; i<num_cars; i++){
        if(cars[i].speed<MAX_SPEED){
            cars[i].speed += ACCELERATION;
        }
    }
}

void brakeCars(Car *cars, int num_cars, int distance){
    int i;
    for(i=0; i<num_cars-1; i++){
        if(cars[i+1].pos - cars[i].pos < distance){
            int difference = cars[i+1].pos - cars[i].pos;
            if(difference>0){
                cars[i].speed -= BREAKING*difference/distance;
            }
            if(cars[i].speed<0){
                cars[i].speed = 0;
            }
            if(cars[i+1].speed>0){
                cars[i+1].speed -= BREAKING*difference/distance;
            }
            if(cars[i+1].speed<0){
                cars[i+1].speed = 0;
            }
        }
    }
}