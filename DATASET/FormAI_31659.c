//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int numCars = 10; // number of cars on the road
    int roadLength = 1000; // length of the road in meters
    int speedLimit = 80; // speed limit in km/h
    int timeStep = 1; // in seconds
    float acceleration = 2.5; // in m/s^2
    float deceleration = 5; // in m/s^2
    float carLength = 5; // in meters
    float carDistance[numCars];
    float carSpeed[numCars];
    srand(time(NULL)); // seed the random number generator

    // initialize car distances and speeds randomly
    for(int i = 0; i < numCars; i++) {
        carDistance[i] = (float)rand() / RAND_MAX * roadLength;
        carSpeed[i] = (float)rand() / RAND_MAX * speedLimit / 3.6;
    }

    // simulate the traffic flow
    for(int t = 0; t < 3600; t += timeStep) { // simulate for 1 hour
        for(int i = 0; i < numCars; i++) {
            // calculate the distance to the next car
            float nextCarDist = roadLength; // assume no cars in front
            for(int j = 0; j < numCars; j++) {
                if(i != j) { // ignore the current car
                    float dist = carDistance[j] - carDistance[i];
                    if(dist > 0 && dist < nextCarDist) {
                        nextCarDist = dist;
                    }
                }
            }
            // calculate the new speed and distance of the car
            float newSpeed;
            if(nextCarDist < 2 * carLength) { // too close to the next car
                newSpeed = fmax(0, carSpeed[i] - deceleration * timeStep);
            } else if(carDistance[i] + carSpeed[i] * timeStep + 0.5 * acceleration * pow(timeStep, 2) > nextCarDist) { // need to slow down
                newSpeed = fmax(0, carSpeed[i] - deceleration * timeStep);
            } else if(carSpeed[i] < speedLimit / 3.6) { // can accelerate
                newSpeed = fmin((carSpeed[i] + acceleration * timeStep), speedLimit / 3.6);
            } else { // maintain current speed
                newSpeed = carSpeed[i];
            }
            carSpeed[i] = newSpeed;
            carDistance[i] += carSpeed[i] * timeStep;
            if(carDistance[i] >= roadLength) { // car goes off the road
                carDistance[i] = 0;
            }
        }
        // print out the current state of the road
        printf("%d:\t", t);
        for(int i = 0; i < roadLength; i += 10) {
            char symbol = '-';
            for(int j = 0; j < numCars; j++) {
                if(carDistance[j] >= i && carDistance[j] < i + 10) {
                    symbol = 'X';
                }
            }
            printf("%c", symbol);
        }
        printf("\n");
    }

    return 0; // end of program
}