//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

struct Car {
    int pos; // Position of the car on the road
    int speed; // Current speed of the car
};

void simulateTraffic(int roadLength, int numberOfCars) {
    struct Car cars[numberOfCars];
    
    // Initialize the cars with random positions and speeds
    for(int i = 0; i < numberOfCars; i++) {
        cars[i].pos = rand() % roadLength;
        cars[i].speed = rand() % 5 + 1;
    }
    
    // Simulate the traffic
    int time = 0;
    while(time < 100) {
        for(int i = 0; i < numberOfCars; i++) {
            // Accelarate if there is no car in front or modify the speed accordingly
            int frontCarPos = roadLength;
            for(int j = 0; j < numberOfCars; j++) {
                if(j != i) {
                    if(cars[j].pos > cars[i].pos && cars[j].pos < frontCarPos)
                        frontCarPos = cars[j].pos;
                }
            }
            if(frontCarPos - cars[i].pos > cars[i].speed)
                cars[i].speed++;
            else if(frontCarPos - cars[i].pos <= cars[i].speed)
                cars[i].speed--;
            
            // Move the car based on speed
            cars[i].pos += cars[i].speed;
            if(cars[i].pos >= roadLength)
                cars[i].pos = 0;
        }
        
        // Display the road with cars
        printf("Time: %d\n", time);
        for(int i = 0; i < roadLength; i++) {
            int carIndex = -1;
            for(int j = 0; j < numberOfCars; j++) {
                if(cars[j].pos == i)
                    carIndex = j;
            }
            if(carIndex == -1)
                printf("-");
            else
                printf("#");
        }
        printf("\n\n");
        
        // Wait for some time
        clock_t start_time = clock();
        while (clock() < start_time + 500);
        
        // Increase the time
        time++;
    }
}

int main() {
    srand(time(NULL));
    simulateTraffic(50, 10);
    return 0;
}