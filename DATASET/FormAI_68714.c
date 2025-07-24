//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10 // Maximum number of roads
#define MAX_CARS 20 // Maximum number of cars per road
#define MAX_SPEED 5 // Maximum speed of cars
#define MAX_TIME 100 // Total time for simulation

int main() {

    int roads[MAX_ROADS][MAX_TIME]; // Array to store car positions
    int speeds[MAX_ROADS][MAX_CARS]; // Array to store car speeds
    
    srand(time(NULL)); // Seed for random number generator
    
    // Initialize roads and speeds with 0's
    for(int i = 0; i < MAX_ROADS; i++) {
        for(int j = 0; j < MAX_TIME; j++) {
            roads[i][j] = 0;
        }
        for(int j = 0; j < MAX_CARS; j++) {
            speeds[i][j] = 0;
        }
    }
    
    // Generate initial cars and speeds randomly
    for(int i = 0; i < MAX_ROADS; i++) {
        int num_cars = rand() % MAX_CARS + 1; // Random number of cars per road (between 1 and MAX_CARS)
        for(int j = 0; j < num_cars; j++) {
            int pos = rand() % MAX_TIME; // Random position on road (between 0 and MAX_TIME - 1)
            roads[i][pos] = 1; // Place car at position
            speeds[i][j] = rand() % MAX_SPEED + 1; // Random speed of car (between 1 and MAX_SPEED)
        }
    }
    
    // Simulation loop
    for(int t = 1; t < MAX_TIME; t++) {
        for(int i = 0; i < MAX_ROADS; i++) {
            for(int j = 0; j < MAX_CARS; j++) {
                if(roads[i][t-1] != 0 && roads[i][t] == 0 && roads[(i+1)%MAX_ROADS][t] == 0) {
                    // Car moving to next position
                    roads[i][t] = roads[i][t-1];
                    roads[i][t-1] = 0;
                }
                else if(roads[i][t-1] != 0 && speeds[i][j] != 0 && roads[(i+1)%MAX_ROADS][t] == 0) {
                    // Car accelerating
                    speeds[i][j]++;
                    if(speeds[i][j] > MAX_SPEED) {
                        speeds[i][j] = MAX_SPEED;
                    }
                }
                else if(roads[i][t-1] != 0 && speeds[i][j] != 0 && roads[(i+1)%MAX_ROADS][t] != 0) {
                    // Car decelerating
                    speeds[i][j]--;
                    if(speeds[i][j] < 0) {
                        speeds[i][j] = 0;
                    }
                }
            }
        }
    }
    
    // Print final positions of cars on roads
    printf("Final positions of cars on roads:\n");
    for(int i = 0; i < MAX_ROADS; i++) {
        for(int j = 0; j < MAX_TIME; j++) {
            printf("%d ", roads[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}