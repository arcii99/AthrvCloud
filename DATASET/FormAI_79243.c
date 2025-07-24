//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: unmistakable
//C Traffic Flow Simulation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define TRAFFIC_LIGHT_INTERVAL 10 //in seconds

//function to add delay - sleep for given number of seconds
void delay(int seconds) {
    time_t start = time(NULL);
    while (time(NULL) < (start + seconds));
}

int main() {
    int num_cars = 0, i, j, k, light_timer = 0, num_cars_passed = 0;
    int arrival_times[MAX_CARS];
    char lane1[MAX_CARS], lane2[MAX_CARS];

    //initialize the arrival times and lanes
    for (i = 0; i < MAX_CARS; i++) {
        arrival_times[i] = rand() % 60; //random arrival time between 0 and 60 seconds
        lane1[i] = '-';
        lane2[i] = '-';
    }

    //display initial traffic flow
    printf("Traffic Flow:\n\n");
    printf("   Lane 1      Lane 2\n");
    printf("----------------------\n");
    for (i = 0; i < MAX_CARS; i++) {
        printf("      %c            %c\n", lane1[i], lane2[i]);
    }

    //run simulation for 2 minutes (120 seconds)
    for (i = 0; i < 120; i++) {
        //update traffic light timer
        light_timer++;
        if (light_timer == TRAFFIC_LIGHT_INTERVAL) {
            light_timer = 0;
        }

        //check if cars can pass through the traffic light
        if (light_timer < (TRAFFIC_LIGHT_INTERVAL / 2)) {
            //cars can pass from lane 1 to lane 2
            for (j = 0; j < MAX_CARS; j++) {
                if (lane1[j] == 'X') {
                    if (j == 0) {
                        //car is at the front - remove from lane1
                        lane1[j] = '-';
                        num_cars_passed++;
                    } else {
                        //car can move forward
                        lane1[j] = '-';
                        lane1[j - 1] = 'X';
                    }
                }
            }

            //add new cars to lane 1
            if (num_cars < MAX_CARS && arrival_times[num_cars] == i) {
                lane1[MAX_CARS - (num_cars + 1)] = 'X';
                num_cars++;
            }
        } else {
            //cars can pass from lane 2 to lane 1
            for (k = 0; k < MAX_CARS; k++) {
                if (lane2[k] == 'X') {
                    if (k == 0) {
                        //car is at the front - remove from lane2
                        lane2[k] = '-';
                        num_cars_passed++;
                    } else {
                        //car can move forward
                        lane2[k] = '-';
                        lane2[k - 1] = 'X';
                    }
                }
            }

            //add new cars to lane 2
            if (num_cars < MAX_CARS && arrival_times[num_cars] == i) {
                lane2[num_cars] = 'X';
                num_cars++;
            }
        }

        //display updated traffic flow
        printf("\nTraffic Flow (Time: %d seconds, %d cars passed):\n\n", i, num_cars_passed);
        printf("   Lane 1      Lane 2\n");
        printf("----------------------\n");
        for (j = 0; j < MAX_CARS; j++) {
            printf("      %c            %c\n", lane1[j], lane2[j]);
        }

        //delay for a second
        delay(1);
    }

    return 0;
}