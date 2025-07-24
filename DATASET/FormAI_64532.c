//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TOTAL_CARS 50            //Number of cars on the road at once
#define MAX_SPEED 60             //Maximum speed (in km/h) of each car
#define MAX_DISTANCE 10000       //Maximum distance between cars (in meters)
#define CAR_LENGTH 4             //Length (in meters) of each car
#define ROAD_LENGTH 4000         //Length (in meters) of the road
#define TIME_INTERVAL 2          //Interval (in seconds) at which speed of each car is updated

// A structure to represent a car
struct Car {
    int speed;           // Current speed (in km/h) of the car
    int distance;        // Current distance (in meters) of the car from the start of the road
};

// Function to generate a random speed for each car between 0 and the maximum speed
int generateRandomSpeed() {
    return rand() % (MAX_SPEED + 1);
}

// Function to initialize the position and speed of each car
void initializeTraffic(struct Car traffic[]) {
    int i;
    for (i = 0; i < TOTAL_CARS; i++) {
        traffic[i].speed = generateRandomSpeed();
        traffic[i].distance = i * (MAX_DISTANCE / TOTAL_CARS);
    }
}

// Function to update the speed and position of each car based on the car in front of it
void updateTraffic(struct Car traffic[]) {
    int i;
    for (i = 0; i < TOTAL_CARS; i++) {
        if (i != TOTAL_CARS - 1) {        //If not last car on the road
            int distanceToNextCar = traffic[i + 1].distance - traffic[i].distance;
            int timeToNextCar = distanceToNextCar / traffic[i].speed;
            int requiredDistanceToStop = (traffic[i].speed * 3.6) * timeToNextCar;    //Calculating required distance to stop in meters
            if (distanceToNextCar < requiredDistanceToStop) {                          //If required distance to stop is more than the distance from the next car
                traffic[i].speed = traffic[i + 1].speed;                                //Set speed to the speed of the car in front of it
            }
            else if (traffic[i].speed < MAX_SPEED) {                                    //If current speed is less than maximum speed
                traffic[i].speed++;                                                    //Increase speed by 1 km/h
            }
        }
        traffic[i].distance += (traffic[i].speed * 1000 / 3600) * TIME_INTERVAL;       //Update distance based on current speed
    }
}

// Function to print the current state of the traffic
void printTraffic(struct Car traffic[]) {
    int i, j;
    for (i = 0; i < TOTAL_CARS; i++) {
        for (j = 0; j < traffic[i].distance / (ROAD_LENGTH / 50); j++) {      //Printing spaces to represent the distance between cars
            printf(" ");
        }
        printf("C%d", i);                                                      //Printing the car number
    }
    printf("\n");
}

int main() {
    srand(time(NULL));                   //Seed for generating random numbers
    struct Car traffic[TOTAL_CARS];       // Initializing the array of cars
    int i;
    initializeTraffic(traffic);           //Initializing the position and speed of each car
    for (i = 0; i < ROAD_LENGTH / (MAX_SPEED * 1000 / 3600); i++) {     //Simulation runs for the time required to cover the entire road at the maximum speed
        printTraffic(traffic);                                          //Printing the current state of the traffic
        updateTraffic(traffic);                                         //Updating the position and speed of each car
    }
    return 0;
}