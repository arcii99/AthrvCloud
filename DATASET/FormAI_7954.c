//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cryptic
// include header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// define macros for traffic light colors
#define RED 0
#define YELLOW 1
#define GREEN 2

// define function to change traffic light color
void change_light(int current_color, int next_color)
{
    // print current color of traffic light
    switch (current_color) {
        case RED:
            printf("Current traffic light color: RED\n");
            break;
        case YELLOW:
            printf("Current traffic light color: YELLOW\n");
            break;
        case GREEN:
            printf("Current traffic light color: GREEN\n");
            break;
    }
    
    // wait for a random amount of time between 1 to 3 seconds
    int wait_time = (rand() % 3) + 1;
    printf("Waiting for %d seconds...\n", wait_time);
    sleep(wait_time);
    
    // change traffic light color to next color
    switch (next_color) {
        case RED:
            printf("Changing traffic light color from YELLOW to RED...\n");
            break;
        case YELLOW:
            printf("Changing traffic light color from GREEN to YELLOW...\n");
            break;
        case GREEN:
            printf("Changing traffic light color from RED to GREEN...\n");
            break;
    }
}

int main()
{
    srand(time(NULL)); // seed random number generator
    
    int current_color = RED; // start with red traffic light
    bool emergency_vehicle = false; // no emergency vehicle currently
    
    while (true) {
        if (emergency_vehicle) {
            printf("EMERGENCY VEHICLE APPROACHING!\n");
            change_light(current_color, RED); // immediately turn traffic light red
            emergency_vehicle = false; // reset emergency vehicle flag
        }
        else {
            switch (current_color) {
                case RED:
                    change_light(current_color, GREEN);
                    current_color = GREEN;
                    break;
                case YELLOW:
                    change_light(current_color, RED);
                    current_color = RED;
                    break;
                case GREEN:
                    change_light(current_color, YELLOW);
                    current_color = YELLOW;
                    break;
            }
        }
        
        // wait for a fixed amount of time between traffic light changes
        sleep(5);
    }
    
    return 0;
}