//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define MAX_SIGNAL 100

int main(void){

    // Initialize random seed
    srand(time(NULL));

    // Configure variables
    int signal_strength = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    char signal_name[6][10] = {"SIGNAL1", "SIGNAL2", "SIGNAL3", "SIGNAL4", "SIGNAL5", "SIGNAL6"};

    // Display initial message
    printf(">>>> Wi-Fi Signal Strength Analyzer <<<<\n\n");

    // Enter infinite loop to simulate constant measurement of signal strength.
    while(1){

        // Reset signal strength variables
        int total_signal_strength = 0;
        int average_signal_strength = 0;

        // Generate random signal strength values for multiple signals
        for(i = 0; i < 6; i++){

            signal_strength = (rand() % MAX_SIGNAL) + 1;

            // Display signal strength
            printf("%s: %d\n", signal_name[i], signal_strength);
            total_signal_strength += signal_strength;

        }

        // Calculate average signal strength
        average_signal_strength = total_signal_strength / 6;

        // Display average signal strength
        printf("Average Signal Strength: %d\n\n", average_signal_strength);

        // Delay for 5 sec.
        sleep(5);

    }
    return 0;
}