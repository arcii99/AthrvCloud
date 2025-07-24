//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANE_LENGTH 20
#define TRAFFIC_LIGHT_INTERVAL 10

typedef struct {
    int speed;
    int pos;
    int hasMoved;
} Car;

int main() {
    srand(time(0));
    
    // Initialize cars on the road
    Car lane[LANE_LENGTH];
    for (int i = 0; i < LANE_LENGTH; i++) {
        lane[i].speed = (rand() % 5) + 1;
        lane[i].pos = i;
        lane[i].hasMoved = 0;
    }
    
    // Initialize traffic light
    int trafficLightPos = LANE_LENGTH / 2;
    int trafficLightTimer = TRAFFIC_LIGHT_INTERVAL;
    int isGreen = 0;
    int carCountBeforeTrafficLight = 0;
    int carCountAfterTrafficLight = 0;
    
    printf("Initial state:\n");
    for (int i = 0; i < LANE_LENGTH; i++) {
        printf("%d ", lane[i].speed);
    }
    printf("\n\n");
    
    // Begin simulation
    int time = 0;
    while (time < 100) {
        // Move cars
        for (int i = 0; i < LANE_LENGTH; i++) {
            if (!lane[i].hasMoved) {
                int newPos = (lane[i].pos + lane[i].speed) % LANE_LENGTH;
                if (newPos < i) {
                    carCountBeforeTrafficLight--;
                } else if (newPos > i) {
                    carCountAfterTrafficLight--;
                }
                lane[i].pos = newPos;
                lane[i].hasMoved = 1;
            }
        }
        
        // Process traffic light
        trafficLightTimer--;
        if (trafficLightTimer == 0) {
            if (isGreen) {
                isGreen = 0;
                trafficLightTimer = TRAFFIC_LIGHT_INTERVAL + carCountAfterTrafficLight;
                carCountBeforeTrafficLight = 0;
            } else {
                isGreen = 1;
                trafficLightTimer = TRAFFIC_LIGHT_INTERVAL + carCountBeforeTrafficLight;
                carCountAfterTrafficLight = 0;
            }
        }
        
        // Count cars before and after traffic light
        carCountBeforeTrafficLight = 0;
        carCountAfterTrafficLight = 0;
        for (int i = 0; i < LANE_LENGTH; i++) {
            if (lane[i].pos < trafficLightPos) {
                carCountBeforeTrafficLight++;
            } else if (lane[i].pos > trafficLightPos) {
                carCountAfterTrafficLight++;
            }
            lane[i].hasMoved = 0;
        }
        
        // Print current state
        printf("Time %d: ", time);
        for (int i = 0; i < LANE_LENGTH; i++) {
            if (i == trafficLightPos) {
                if (isGreen) {
                    printf("G ");
                } else {
                    printf("R ");
                }
                continue;
            }
            if (lane[i].pos < trafficLightPos) {
                printf("< ");
            } else if (lane[i].pos > trafficLightPos) {
                printf("> ");
            } else {
                printf("+ ");
            }
        }
        printf("\n\n");
        
        // Increment time
        time++;
    }
    
    return 0;
}