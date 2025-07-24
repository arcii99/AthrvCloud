//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_CARS 20
#define MAX_LANE_LENGTH 50
#define MIN_SPEED 50
#define MAX_SPEED 150
#define TIME_UNIT 1000000

int main() {
    srand(time(NULL));
    int car_count = 0;
    int lane[MAX_LANE_LENGTH] = {0}; //initialize lane with all zeros
    int speed[MAX_CARS];

    while(1) {
        //randomly add a new car
        if (rand() % 2 == 0 && car_count < MAX_CARS) {
            lane[0] = 1; //set the first cell to indicate a new car
            speed[car_count] = (rand() % (MAX_SPEED - MIN_SPEED)) + MIN_SPEED; //randomly assign a speed to the new car
            car_count++;
        }

        //move all cars forward based on their speed
        for (int i = MAX_LANE_LENGTH - 1; i >= 0; i--) {
            if (lane[i] == 1) {
                if (i + speed[i]/TIME_UNIT >= MAX_LANE_LENGTH) { //check if the car is at the end of the lane
                    lane[i] = 0;
                    car_count--;
                } else {
                    lane[i] = 0;
                    lane[i + speed[i]/TIME_UNIT] = 1;
                }
            }
        }

        //display the current state of the lane
        printf("--------------------\n");
        for (int i = 0; i < MAX_LANE_LENGTH; i++) {
            if (lane[i] == 1) {
                printf("X");
            } else {
                printf("_");
            }
        }
        printf("\n");

        usleep(TIME_UNIT); //wait for some time before refreshing the display
        system("clear"); //clear the console before displaying the updated lane
    }

    return 0;
}