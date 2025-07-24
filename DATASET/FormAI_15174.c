//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRAFFIC 150
#define MIN_SPEED 30
#define MAX_SPEED 60

int main() {
    srand(time(NULL));
    int traffic = rand() % (MAX_TRAFFIC - 50 + 1) + 50;
    int speeds[traffic];

    printf("\nWELCOME TO THE TRAFFIC FLOW SIMULATION!\n\n");

    printf("Number of Cars on the Road: %d\n\n", traffic);

    printf("Speed of Cars on the Road (in km/h):\n");

    for(int i = 0; i < traffic; i++) {
        speeds[i] = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        printf("Car %d: %d\n", i+1, speeds[i]);
    }

    int sum = 0;
    for(int i = 0; i < traffic; i++) {
        sum += speeds[i];
    }
    int average = sum / traffic;

    printf("\nAverage Speed of Cars on the Road: %d km/h\n\n", average);

    int fast_cars = 0;
    int slow_cars = 0;
    for(int i = 0; i < traffic; i++) {
        if(speeds[i] >= average) {
            fast_cars++;
        } else {
            slow_cars++;
        }
    }

    printf("Number of Cars Above Average Speed: %d\n", fast_cars);
    printf("Number of Cars Below Average Speed: %d\n\n", slow_cars);

    return 0;
}