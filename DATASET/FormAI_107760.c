//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SPEED 60 // km/h
#define MAX_SIMULATION_TIME 60 // minutes
#define MAX_CAR_LENGTH 4 // meters
#define MIN_CAR_DIST 5 // meters

// This struct represents a car
struct car {
    int speed; // km/h
    int length; // meters
    int position; // meters
};

// This function initializes a car with random speed and length
void init_car(struct car *c) {
    c->speed = rand() % MAX_SPEED + 1;
    c->length = MAX_CAR_LENGTH;
    c->position = 0;
}

int main() {
    srand(time(NULL));
    int simulation_time = 0;
    struct car cars[10]; // A fixed number of cars for simplicity
    
    // Initialize cars
    for (int i = 0; i < 10; i++) {
        init_car(&cars[i]);
    }
    
    while (simulation_time < MAX_SIMULATION_TIME) {
        // Print current time
        printf("\n%d minutes:\n", simulation_time);
        
        // Move each car according to its speed
        for (int i = 0; i < 10; i++) {
            int distance = (cars[(i+1)%10].position - cars[i].position) - cars[i].length - MIN_CAR_DIST;
            if (distance < 0) {
                cars[i].speed = cars[(i+1)%10].speed;
            }
            cars[i].position += cars[i].speed / 60;
            printf("Car %d: speed = %d km/h, position = %d meters\n", i+1, cars[i].speed, cars[i].position);
        }
        
        simulation_time++;
    }
    
    return 0;
}