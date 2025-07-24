//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_INTERVAL 5 // Average time in seconds for a car to appear at a road
#define MAX_ROADS 10 // Maximum number of roads in the simulation
#define SIMULATION_TIME 600 // Total simulation time in seconds
#define STAT_INTERVAL 60 // Time interval for statistical reporting in seconds

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int road_count = random_number(1, MAX_ROADS); // Generate a random number of roads
    int roads[road_count][SIMULATION_TIME / TIME_INTERVAL]; // 2D array to store traffic flow
    
    // Initialize traffic flow to 0 for all roads at all times
    for(int i = 0; i < road_count; i++) {
        for(int j = 0; j < SIMULATION_TIME / TIME_INTERVAL; j++) {
            roads[i][j] = 0;
        }
    }
    
    int time = 0; // Current time in the simulation
    
    // Simulate traffic flow for SIMULATION_TIME seconds
    while(time < SIMULATION_TIME) {
        // Generate a random number of cars for each road
        for(int i = 0; i < road_count; i++) {
            int num_cars = random_number(0, 10); // Maximum 10 cars can appear at a road
            for(int j = 0; j < num_cars; j++) {
                // Assign a random speed to each car
                int speed = random_number(10, 100); // Speed in km/h
                // Calculate the distance traveled by the car in TIME_INTERVAL seconds
                int dist_travelled = (speed * 1000 * TIME_INTERVAL) / 3600; // Distance in meters
                // Add the distance traveled by the car to the traffic flow for the corresponding road and time
                roads[i][time / TIME_INTERVAL] += dist_travelled;
            }
        }
        time += TIME_INTERVAL;
    }
    
    printf("Simulation complete!\n");
    
    // Generate statistical reports
    printf("\nTraffic flow statistics:\n");
    for(int i = 0; i < road_count; i++) {
        int total_flow = 0;
        for(int j = 0; j < SIMULATION_TIME / TIME_INTERVAL; j++) {
            total_flow += roads[i][j];
        }
        printf("Road %d: Total flow = %d meters\n", i+1, total_flow);
    }
    
    int traffic_density = 0; // Average traffic density for the simulation
    for(int i = 0; i < road_count; i++) {
        int road_density = 0;
        for(int j = 0; j < SIMULATION_TIME / TIME_INTERVAL; j++) {
            road_density += roads[i][j];
        }
        road_density = road_density / (SIMULATION_TIME / TIME_INTERVAL);
        traffic_density += road_density;
        printf("Road %d: Traffic density = %d meters/second\n", i+1, road_density);
    }
    traffic_density = traffic_density / road_count;
    printf("Average traffic density = %d meters/second\n", traffic_density);
    
    return 0;
}