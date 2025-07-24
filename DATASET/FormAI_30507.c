//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 30
#define MAX_ROADS 4

int main(void) {
    int cars[MAX_CARS];
    int roads[MAX_ROADS];
    int i, j, count = 0;
    srand(time(NULL));

    // Initialize cars with random speeds from 50 to 120 km/h
    for(i=0; i<MAX_CARS; i++) {
        cars[i] = rand() % 71 + 50;
    }

    // Initialize roads with random lengths from 5 to 50 km
    for(i=0; i<MAX_ROADS; i++) {
        roads[i] = rand() % 46 + 5;
    }

    // Simulate traffic flow for each road
    for(i=0; i<MAX_ROADS; i++) {
        int time = 0;
        int distance = 0;
        int car_count = 0;
        int max_speed = 0;
        int min_speed = 121;

        // Calculate time for each car to travel the road
        for(j=0; j<MAX_CARS; j++) {
            time = roads[i] / cars[j] * 60;
            if(time > 0 && time <= 180) {
                car_count++;
                distance += roads[i];
                if(cars[j] > max_speed) {
                    max_speed = cars[j];
                }
                if(cars[j] < min_speed) {
                    min_speed = cars[j];
                }
            }
        }

        // Print summary for each road
        printf("Road %d:\n", i+1);
        printf("Distance: %d km\n", roads[i]);
        printf("Cars: %d\n", car_count);
        printf("Maximum speed: %d km/h\n", max_speed);
        printf("Minimum speed: %d km/h\n", min_speed);
        printf("Average speed: %.2f km/h\n", (float)distance / car_count / (float)time * 60.0);
        printf("\n");

        count++;
    }

    // Print summary for all roads
    printf("Total roads: %d\n", count);
    printf("\n");

    return 0;
}