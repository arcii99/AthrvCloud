//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for signal strength
#define WEAK_SIGNAL "-.-"
#define MODERATE_SIGNAL "-.-.-"
#define STRONG_SIGNAL "-.-.-.-"

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Set the maximum signal strength
    int max_strength = 100;

    // Set the number of Wi-Fi devices in the area
    int num_devices = 5;

    // Set up an array to hold each device's signal strength
    int signal_strengths[num_devices];

    // Initialize each device's signal strength
    for (int i = 0; i < num_devices; i++) {
        signal_strengths[i] = rand() % max_strength;
    }

    // Print a medieval message to the user
    printf("Hark! Ye be in the presence of Wi-Fi!\n");

    // Loop through each device and print its signal strength
    for (int i = 0; i < num_devices; i++) {
        // Determine the signal strength category
        char* signal_category;
        if (signal_strengths[i] < 33) {
            signal_category = WEAK_SIGNAL;
        } else if (signal_strengths[i] < 66) {
            signal_category = MODERATE_SIGNAL;
        } else {
            signal_category = STRONG_SIGNAL;
        }

        // Print a medieval message about the device's signal strength
        printf("Device %d: ", i+1);
        for (int j = 0; j < signal_strengths[i]; j++) {
            printf("|");
        }
        printf(" %s\n", signal_category);
    }

    return 0;
}