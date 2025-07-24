//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to turn on and off the traffic light bulbs
void turn_on_off(int light_state) {
    if (light_state == 1) {
        printf("ON\n");
    } else {
        printf("OFF\n");
    }
}

int main() {
    int red_light_state = 1; // Initially, the red light is on
    int green_light_state = 0; // Initially, the green light is off
    int yellow_light_state = 0; // Initially, the yellow light is off

    int duration = 0; // Variable to hold the duration of each state

    srand(time(NULL)); // Seed for the random number generator

    // Loop through the traffic light cycles indefinitely
    while (1) {
        // Generate a random number to determine the duration of the red light
        duration = rand() % 10 + 5;
        printf("Red Light: ");
        turn_on_off(red_light_state);
        printf("Green Light: ");
        turn_on_off(green_light_state);
        printf("Yellow Light: ");
        turn_on_off(yellow_light_state);
        printf("Duration: %d seconds\n", duration);

        // Wait for the duration of the red light
        for (int i = 0; i < duration; i++) {
            printf("Red Light time remaining: %d\n", duration - i);
            sleep(1);
        }

        // Change the red light state to off and the green light state to on
        red_light_state = 0;
        green_light_state = 1;
        yellow_light_state = 0;

        // Generate a random number to determine the duration of the green light
        duration = rand() % 10 + 5;
        printf("Red Light: ");
        turn_on_off(red_light_state);
        printf("Green Light: ");
        turn_on_off(green_light_state);
        printf("Yellow Light: ");
        turn_on_off(yellow_light_state);
        printf("Duration: %d seconds\n", duration);

        // Wait for the duration of the green light
        for (int i = 0; i < duration; i++) {
            printf("Green Light time remaining: %d\n", duration - i);
            sleep(1);
        }

        // Change the green light state to off and the yellow light state to on
        red_light_state = 0;
        green_light_state = 0;
        yellow_light_state = 1;

        // Set the duration of the yellow light to 2 seconds
        printf("Red Light: ");
        turn_on_off(red_light_state);
        printf("Green Light: ");
        turn_on_off(green_light_state);
        printf("Yellow Light: ");
        turn_on_off(yellow_light_state);
        printf("Duration: 2 seconds\n");

        // Wait for the duration of the yellow light
        for (int i = 0; i < 2; i++) {
            printf("Yellow Light time remaining: %d\n", 2 - i);
            sleep(1);
        }

        // Change the yellow light state to off and the red light state to on
        red_light_state = 1;
        green_light_state = 0;
        yellow_light_state = 0;
    }

    return 0;
}