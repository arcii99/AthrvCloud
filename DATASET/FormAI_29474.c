//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
// C Traffic Flow Simulation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 100
#define MAX_SPEED 5
#define TRAFFIC_DENSITY 0.2

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    
    // Initialize the road with empty cells
    int road[ROAD_LENGTH];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = -1;
    }
    
    // Populate the road with cars
    for (int i = 0; i < ROAD_LENGTH * TRAFFIC_DENSITY; i++) {
        int position = rand() % ROAD_LENGTH;
        while (road[position] != -1) {
            position = rand() % ROAD_LENGTH;
        }
        road[position] = rand() % MAX_SPEED;
    }
    
    // Simulate the traffic flow
    int time = 0;
    while (time < 1000) {
        // Print the current state of the road
        printf("Time: %d\n", time);
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (road[i] == -1) {
                printf("-");
            } else {
                printf("%d", road[i]);
            }
        }
        printf("\n");
        
        // Move each car forward based on its speed
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (road[i] != -1) {
                int speed = road[i];
                for (int j = 0; j < speed; j++) {
                    int next_position = (i + j + 1) % ROAD_LENGTH;
                    if (road[next_position] != -1) {
                        break; // Car in front, can't move
                    }
                    road[next_position] = road[i];
                    road[i] = -1;
                    i = next_position;
                }
            }
        }
        
        // Randomly slow down cars
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (road[i] > 0) {
                if (rand() % 5 == 0) {
                    road[i]--;
                }
            }
        }
        
        time++;
    }
    
    return 0;
}