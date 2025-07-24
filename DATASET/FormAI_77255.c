//FormAI DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Set up initial light state - all off
    int light1 = 0;
    int light2 = 0;
    int light3 = 0;
    int light4 = 0;

    // Print initial light state
    printf("Welcome to the post-apocalyptic smart home light control system.\n");
    printf("All lights are currently off.\n");

    // Loop indefinitely
    while(1) {

        // Choose a random light to turn on or off
        int light_number = rand() % 4 + 1;

        if(light_number == 1) {
            // Light 1 was chosen
            if(light1 == 0) {
                printf("Light 1 is turning on.\n");
                light1 = 1;
            } else {
                printf("Light 1 is turning off.\n");
                light1 = 0;
            }
        } else if(light_number == 2) {
            // Light 2 was chosen
            if(light2 == 0) {
                printf("Light 2 is turning on.\n");
                light2 = 1;
            } else {
                printf("Light 2 is turning off.\n");
                light2 = 0;
            }
        } else if(light_number == 3) {
            // Light 3 was chosen
            if(light3 == 0) {
                printf("Light 3 is turning on.\n");
                light3 = 1;
            } else {
                printf("Light 3 is turning off.\n");
                light3 = 0;
            }
        } else {
            // Light 4 was chosen
            if(light4 == 0) {
                printf("Light 4 is turning on.\n");
                light4 = 1;
            } else {
                printf("Light 4 is turning off.\n");
                light4 = 0;
            }
        }

        // Wait for a random length of time before choosing the next light
        int delay = rand() % 10 + 1;
        printf("Waiting %d seconds...\n", delay);
        sleep(delay);
    }

    return 0;
}