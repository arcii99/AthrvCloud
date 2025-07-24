//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 60

typedef struct{
    int speed, location, distanceToNext;
} car;

car createCar(){
    car newCar;
    newCar.speed = rand() % (MAX_SPEED + 1);
    newCar.location = 0;
    newCar.distanceToNext = rand() % 201 + 50;
    return newCar;
}

int main(){
    srand(time(0));
    car cars[MAX_CARS];
    int numCars = rand() % MAX_CARS + 1;

    // Create cars on the road
    for(int i = 0; i < numCars; i++){
        cars[i] = createCar();
    }

    printf("Number of cars on the road: %d\n", numCars);
    printf("Cars on the road:\n");

    // Show initial state of each car
    for(int i = 0; i < numCars; i++){
        printf("Car %d -> Speed: %d m/s, Distance to next car: %d meters\n", i+1, cars[i].speed, cars[i].distanceToNext);
    }

    // Run simulation for 10 seconds
    for(int time = 0; time < 10; time++){
        printf("\nTime: %d seconds\n", time+1);
        // Move each car based on their speed
        for(int i = 0; i < numCars; i++){
            cars[i].location += cars[i].speed;
        }

        // Check if each car is going too close to the next car
        for(int i = 0; i < numCars-1; i++){
            int distanceToNext = cars[i].distanceToNext - (cars[i+1].location - cars[i].location);
            if(distanceToNext < 0){
                printf("Car %d is too close to car %d, distance: %d meters\n", i+1, i+2, -distanceToNext);
                cars[i].speed--;
                cars[i+1].speed = (cars[i+1].speed + 1) % (MAX_SPEED + 1);
            }
        }

        // Randomly change the speed of each car
        for(int i = 0; i < numCars; i++){
            if(rand() % 2 == 0){
                cars[i].speed = (cars[i].speed + 1) % (MAX_SPEED + 1);
            }else{
                cars[i].speed = (cars[i].speed - 1) < 0 ? 0 : cars[i].speed - 1;
            }
        }

        // Show the state of each car after the simulation run
        for(int i = 0; i < numCars; i++){
            printf("Car %d -> Speed: %d m/s, Distance to next car: %d meters\n", i+1, cars[i].speed, cars[i].distanceToNext);
        }
    }

    return 0;
}