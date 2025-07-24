//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int red_light = 1;
    int yellow_light = 0;
    int green_light = 0;
    int seconds_to_switch = 0;

    while(1) {
        if(red_light == 1) { // Red Light
            printf("\n************************************\n");
            printf("RED LIGHT: STOP! DO NOT PROCEED!\n");
            printf("************************************\n");
            seconds_to_switch = rand() % 10 + 1; // Randomize time to switch
            printf("Switching to Green Light in %d seconds...\n", seconds_to_switch);
            sleep(seconds_to_switch);
            red_light = 0;
            green_light = 1;
        } else if(yellow_light == 1) { // Yellow Light
            printf("\n************************************\n");
            printf("YELLOW LIGHT: CAUTION! PROCEED WITH CARE!\n");
            printf("************************************\n");
            seconds_to_switch = rand() % 10 + 1; // Randomize time to switch
            printf("Switching to Red Light in %d seconds...\n", seconds_to_switch);
            sleep(seconds_to_switch);
            yellow_light = 0;
            red_light = 1;
        } else if(green_light == 1) { // Green Light
            printf("\n************************************\n");
            printf("GREEN LIGHT: GO AHEAD! DRIVE SAFELY!\n");
            printf("************************************\n");
            seconds_to_switch = rand() % 10 + 1; // Randomize time to switch
            printf("Switching to Yellow Light in %d seconds...\n", seconds_to_switch);
            sleep(seconds_to_switch);
            green_light = 0;
            yellow_light = 1;
        }
    }
    return 0;
}