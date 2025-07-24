//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 120 // in km/h
#define MAX_DISTANCE 20 // in km
#define NUM_CARS 10

// Function to simulate car behaviour
void simulate_traffic_flow(int *speeds, double *distances, int *lags) {
    int i, speed_difference, ideal_distance;
    double acceleration, deceleration, time_to_collision;

    for(i=1; i<NUM_CARS; i++) {
        // Calculate speed difference and ideal distance
        speed_difference = speeds[i-1] - speeds[i];
        ideal_distance = speeds[i-1] / 10;

        // Calculate time to collision
        if(speed_difference <= 0) {
            time_to_collision = -1;
        }
        else {
            time_to_collision = distances[i] / speed_difference;
        }

        // Calculate acceleration and deceleration
        if(time_to_collision == -1 || time_to_collision > 2) {
            acceleration = 2;
            deceleration = 1;
        }
        else if(time_to_collision <= 2 && time_to_collision > 0) {
            acceleration = -1 * ((speeds[i] - speeds[i-1]) / (2 * distances[i]));
            deceleration = 1.5;
        }
        else {
            acceleration = -2;
            deceleration = 2;
        }

        // Update speeds, distances and lags
        if(speeds[i] + acceleration > MAX_SPEED) {
            speeds[i] = MAX_SPEED;
        }
        else if(speeds[i] + acceleration < 0) {
            speeds[i] = 0;
        }
        else {
            speeds[i] = speeds[i] + acceleration;
        }

        if(distances[i] - speeds[i] < ideal_distance) {
            speeds[i] = speeds[i] - deceleration;
        }
        else if(distances[i] - speeds[i] > ideal_distance) {
            speeds[i] = speeds[i] + 1;
        }

        distances[i] = distances[i] - speeds[i];
        lags[i] = (distances[i] + speeds[i] / 2) / speeds[i];
    }
}

// Function to print current traffic situation
void print_traffic_situation(int *speeds, double *distances, int *lags) {
    int i;

    printf("\nCurrent Traffic Situation:\n\n");
    printf("Car\tSpeed\tDistance\tLag\n");
    printf("------------------------------------------------\n");

    for(i=0; i<NUM_CARS; i++) {
        printf("%d\t%d\t%.2lf\t\t%d\n", i+1, speeds[i], distances[i], lags[i]);
    }

    printf("\n");
}

int main() {
    int i, time_elapsed;
    int speeds[NUM_CARS] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    double distances[NUM_CARS] = {MAX_DISTANCE, MAX_DISTANCE-2, MAX_DISTANCE-4, MAX_DISTANCE-6, MAX_DISTANCE-8, MAX_DISTANCE-10, MAX_DISTANCE-12, MAX_DISTANCE-14, MAX_DISTANCE-16, MAX_DISTANCE-18};
    int lags[NUM_CARS] = {MAX_DISTANCE / speeds[0], MAX_DISTANCE / speeds[1], MAX_DISTANCE / speeds[2], MAX_DISTANCE / speeds[3], MAX_DISTANCE / speeds[4], MAX_DISTANCE / speeds[5], MAX_DISTANCE / speeds[6], MAX_DISTANCE / speeds[7], MAX_DISTANCE / speeds[8], MAX_DISTANCE / speeds[9]};

    print_traffic_situation(speeds, distances, lags); // Initial traffic situation

    for(time_elapsed=1; time_elapsed<=100; time_elapsed++) {
        printf("Time elapsed: %d sec\n", time_elapsed);
        simulate_traffic_flow(speeds, distances, lags);
        print_traffic_situation(speeds, distances, lags);
        printf("\n");
    }

    return 0;
}