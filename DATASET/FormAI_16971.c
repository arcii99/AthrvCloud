//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINUTE 60

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Initialize variables
    int cars_arriving[MINUTE];
    int cars_crossing[MINUTE];
    int total_cars = 0;
    int total_wait_time = 0;
    int light = 0; // Green light is 0, red light is 1
    
    // Simulate traffic flow for 1 hour
    for (int i = 0; i < 60; i++) {
        // Calculate number of cars arriving
        int arr = rand() % 6; // Maximum of 5 cars can arrive per minute
        cars_arriving[i] = arr;
        
        // Calculate number of cars crossing
        int cross = rand() % 3; // Maximum of 2 cars can cross per minute
        cars_crossing[i] = cross;
        
        // Calculate total number of cars at intersection
        int cars_at_intersection = total_cars + arr - cross;
        if (cars_at_intersection < 0) {
            cars_at_intersection = 0; // Cannot have negative cars at intersection
        }
        
        // Calculate wait time for cars at intersection
        int wait_time = cars_at_intersection * 2; // 2 seconds per car
        total_wait_time += wait_time;
        
        // Update total cars at intersection
        total_cars = cars_at_intersection;
        
        // Update traffic light
        if (light == 0) { // Green light
            if (i % 3 == 0) { // Change light every 3 minutes
                light = 1; // Red light
            }
        } else { // Red light
            if (i % 2 == 0) { // Change light every 2 minutes
                light = 0; // Green light
            }
        }
        
        // Print current traffic flow information
        printf("Minute %d\n", i+1);
        printf("Number of cars arriving: %d\n", arr);
        printf("Number of cars crossing: %d\n", cross);
        printf("Total cars at intersection: %d\n", cars_at_intersection);
        printf("Wait time: %d seconds\n", wait_time);
        printf("Traffic light: %s\n\n", light == 0 ? "Green" : "Red");
    }
    
    // Print summary of traffic flow information
    printf("Total cars arrived: %d\n", total_cars);
    printf("Average wait time: %d seconds\n", total_wait_time / 60);
    printf("Traffic light was green %d times and red %d times.\n", 30/3, 30/2);
    
    return 0;
}