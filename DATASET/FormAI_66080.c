//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void red_light();
void yellow_light();
void green_light();

int main() {
    int time_interval;
    time_t start_time;

    // Set seed for random number generator
    srand(time(NULL));

    // Loop indefinitely
    while (1) {

        // Generate random time interval between 5 to 15 seconds
        time_interval = rand() % 11 + 5;

        // Store start time
        start_time = time(NULL);

        // Red light
        red_light();

        // Yellow light
        yellow_light();

        // Green light
        green_light();
        
        // Calculate time elapsed
        time_t end_time = time(NULL);
        double elapsed_time = difftime(end_time, start_time);

        // Print time elapsed
        printf("\nTime elapsed: %0.2lf seconds\n", elapsed_time);

        // If elapsed time is less than the time interval, wait for the remaining time
        if (elapsed_time < time_interval) {
            printf("\nWaiting for %0.2lf seconds\n", time_interval - elapsed_time);
            sleep((time_interval - elapsed_time));
        }
    }

    return 0;
}

// Function to display red light
void red_light() {
    printf("\nRed light\n");
    printf(" _______\n");
    printf("|       |\n");
    printf("|   R   |\n");
    printf("|_______|\n");
    printf("\n");
    sleep(3);
}

// Function to display yellow light
void yellow_light() {
    printf("\nYellow light\n");
    printf(" _______\n");
    printf("|       |\n");
    printf("|   Y   |\n");
    printf("|_______|\n");
    printf("\n");
    sleep(1);
}

// Function to display green light
void green_light() {
    printf("\nGreen light\n");
    printf(" _______\n");
    printf("|       |\n");
    printf("|   G   |\n");
    printf("|_______|\n");
    printf("\n");
    sleep(5);
}