//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define LANE_LENGTH 20
#define LIGHT_INTERVAL 6

int main()
{
    //Initialize the random number generator
    srand((unsigned) time(NULL));

    //Create an array for the traffic lanes
    int lanes[NUM_LANES][LANE_LENGTH];

    //Create variables for traffic lights
    int light_status = 0;
    int light_timer = LIGHT_INTERVAL;

    //Initialize the lanes to be empty
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < LANE_LENGTH; j++) {
            lanes[i][j] = 0;
        }
    }

    //Main program loop
    while (1) {

        //Decrease the traffic light timer
        light_timer--;

        //If the traffic light timer reaches 0, change the light status
        if (light_timer == 0) {
            light_status = !light_status; //Toggle the light status
            light_timer = LIGHT_INTERVAL; //Reset the timer
        }

        //Print the current lane status
        for (int i = 0; i < NUM_LANES; i++) {
            for (int j = 0; j < LANE_LENGTH; j++) {
                if (lanes[i][j] == 0) {
                    printf("-");
                } else {
                    printf("X");
                }
            }
            printf("\n");
        }
        printf("\n");

        //Add new cars to the first lane
        if (rand() % 5 == 0) {
            lanes[0][0] = 1;
        }

        //Move cars forward in each lane
        for (int i = NUM_LANES - 1; i >= 0; i--) {
            for (int j = LANE_LENGTH - 1; j >= 0; j--) {
                if (j == LANE_LENGTH - 1) {
                    //If the car is at the end of the lane, remove it
                    lanes[i][j] = 0;
                } else if (lanes[i][j] == 1) {
                    //If the car isn't at the end, move it forward
                    lanes[i][j] = 0;
                    lanes[i][j+1] = 1;
                }
            }
        }

        //Check if a car needs to turn at the intersection
        if (light_status == 0 && lanes[0][0] == 1) {
            //If the light is green and there is a car in the first lane, move it into the second lane
            lanes[0][0] = 0;
            lanes[1][0] = 1;
        } else if (light_status == 1 && lanes[1][0] == 1) {
            //If the light is red and there is a car in the second lane, move it into the third lane
            lanes[1][0] = 0;
            lanes[2][0] = 1;
        }

        //Wait for 1 second
        sleep(1);
    }

    return 0;
}