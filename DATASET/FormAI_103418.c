//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20
#define MAX_SPEED 60
#define NUM_LANES 3
#define TRAFFIC_LIGHT_DISTANCE 500 // in meters
#define GREEN_LIGHT_DURATION 30 // in seconds

typedef struct Car {
    int speed;
    int lane;
    int position;
} Car;

void generateTraffic(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].lane = rand() % NUM_LANES + 1;
        cars[i].position = (i + 1) * 50;
    }
}

void displayTraffic(Car cars[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car %d: Lane %d, Speed %dkm/h, Position %dm\n", i+1, cars[i].lane, cars[i].speed, cars[i].position);
    }
}

void simulateTraffic(Car cars[], int duration) {
    int time = 0;
    int trafficLight = GREEN_LIGHT_DURATION;
    
    while (time < duration) {
        // Update car positions
        for (int i = 0; i < MAX_CARS; i++) {
            // Update position based on speed
            cars[i].position += cars[i].speed;
            
            // Check if car has reached end of road
            if (cars[i].position >= TRAFFIC_LIGHT_DISTANCE) {
                cars[i].position = TRAFFIC_LIGHT_DISTANCE;
                cars[i].speed = 0;
            }
            
            // Check if car needs to change lanes
            int change = rand() % 100 + 1;
            if (change <= 5) { // 5% chance of changing lanes
                if (cars[i].lane == 1) {
                    cars[i].lane = 2;
                } else if (cars[i].lane == NUM_LANES) {
                    cars[i].lane = NUM_LANES - 1;
                } else {
                    int direction = rand() % 2; // 0 for left, 1 for right
                    if (direction == 0) {
                        cars[i].lane = cars[i].lane - 1;
                    } else {
                        cars[i].lane = cars[i].lane + 1;
                    }
                }
            }
        }
        
        // Check traffic light status
        if (trafficLight > 0) {
            trafficLight--;
        } else {
            trafficLight = GREEN_LIGHT_DURATION; // reset traffic light countdown
        }
        
        // Display current traffic
        printf("Time: %ds\n", time);
        displayTraffic(cars);
        printf("\n");
        
        // Wait for 1 second to simulate real-time traffic flow
        sleep(1);
        time++;
    }
}

int main() {
    srand(time(NULL));
    
    Car cars[MAX_CARS];
    generateTraffic(cars);
    
    printf("Initial Traffic Flow:\n\n");
    displayTraffic(cars);
    printf("\n");
    
    simulateTraffic(cars, 60); // simulate for 1 minute
    
    return 0;
}