//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int red = 0, yellow = 1, green = 2;
    int north_south_state = red, east_west_state = green;
    int num_iterations = 10, current_iteration = 0;

    //initialize random number generator
    srand(time(0));

    while(current_iteration < num_iterations) {
        //simulate delay between light changes
        int delay = rand() % 5 + 1;
        for(int i = delay; i > 0; i--) {
            printf("Time remaining in current state: %d\n", i);
            sleep(1);
        }

        //switch states
        if(north_south_state == red && east_west_state == green) {
            north_south_state = green;
            east_west_state = red;
        } else {
            north_south_state = red;
            east_west_state = green;
        }

        //output current state
        printf("North-South: ");
        if(north_south_state == red) {
            printf("RED\n");
        } else if(north_south_state == yellow) {
            printf("YELLOW\n");
        } else {
            printf("GREEN\n");
        }

        printf("East-West: ");
        if(east_west_state == red) {
            printf("RED\n");
        } else if(east_west_state == yellow) {
            printf("YELLOW\n");
        } else {
            printf("GREEN\n");
        }

        current_iteration++;
    }

    return 0;
}