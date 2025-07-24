//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 25
#define TRAFFIC_LIGHT_DURATION 5

// Function to generate random numbers
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int i, j, count = 0, red_light = 1, green_light = 0;
    int cars[MAX_CARS] = {0};
    srand(time(NULL));

    while(1) {
        system("clear"); // to clear the screen in linux, use "cls" in windows
        printf("Simulation of Traffic Flow\n\n");

        // Display the traffic lights
        if(green_light) {
            printf("Traffic Light: Green\n\n");
        }
        else {
            printf("Traffic Light: Red\n\n");
        }

        // Display the road
        for(i = 0; i < MAX_CARS; i++) {
            if(cars[i]) {
                printf("0");
            }
            else {
                printf("-");
            }
        }
        printf("\n");

        // Move the cars
        for(i = MAX_CARS - 1; i >= 0; i--) {
            if(cars[i]) {
                if(i == MAX_CARS - 1) {
                    cars[i] = 0; // car has reached the end of the road, remove it
                    count++; // increment the count of cars that have passed
                }
                else if(!cars[i+1]) {
                    cars[i+1] = 1; // move the car forward
                    cars[i] = 0;
                }
            }
        }

        // Add new cars
        if(!green_light && count < MAX_CARS) {
            for(i = 0; i < MAX_CARS; i++) {
                if(random_number(1, 10) == 1 && !cars[i]) {
                    cars[i] = 1;
                }
            }
        }

        // Toggle the traffic light
        if(red_light && count == MAX_CARS) {
            red_light = 0;
            green_light = 1;
            count = 0;
        }
        else if(green_light) {
            if(count == MAX_CARS || random_number(1, 10) == 1) {
                red_light = 1;
                green_light = 0;
            }
        }

        // Wait for some time
        for(j = 0; j < TRAFFIC_LIGHT_DURATION; j++) {
            printf("\n");
            sleep(1);
        }
    }

    return 0;
}