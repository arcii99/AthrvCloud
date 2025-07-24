//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRoad(int road[], int length) {
    for(int i=0; i<length; i++) {
        if(road[i] == 0) {
            printf("-");
        }
        else {
            printf("X");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int length = 20;
    int density = 50; // Number of cars on the road (percentage)
    int velocity = 2; // Speed of the cars (cells per second)
    int simulations = 10; // Number of times to simulate the traffic
    int road[length];
    for(int i=0; i<length; i++) {
        road[i] = 0;
    }
    for(int sim=0; sim<simulations; sim++) {
        // Assign cars to the road based on density
        for(int i=0; i<length; i++) {
            int randVal = rand() % 100;
            if(randVal < density) {
                road[i] = 1;
            }
        }
        printf("Initial: ");
        printRoad(road, length);
        int newPosition[length];
        for(int time=0; time<20; time++) { // 20 seconds of traffic
            for(int i=0; i<length; i++) {
                newPosition[i] = 0;
            }
            for(int i=0; i<length; i++) {
                if(road[i] == 1) {
                    int newPos = i + velocity;
                    if(newPos >= length) {
                        road[i] = 0; // Remove car from the road when it reaches the end
                    } 
                    else if(road[newPos] == 0) {
                        newPosition[newPos] = 1; // Move car to new position
                        road[i] = 0;
                    } 
                    else {
                        newPosition[i] = 1; // Car stays in its current position
                    }
                }
            }
            for(int i=0; i<length; i++) {
                road[i] = newPosition[i]; // Update the road
            }
            printf("Time %d: ", time+1);
            printRoad(road, length);
        }
        printf("\n");
    }
    return 0;
}