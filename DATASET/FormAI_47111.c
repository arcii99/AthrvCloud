//FormAI DATASET v1.0 Category: System boot optimizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    char cpu_specs[9] = "Potato 4";

    srand(time(NULL)); // initialize rand() function with current time

    printf("Welcome to the %s Boot Optimizer!\n", cpu_specs);

    printf("Scanning for bloatware...\n");
    sleep(2);

    printf("No bloatware found! Guess you're not so popular after all...\n");
    sleep(2);

    printf("Starting the random optimization process...\n");
    sleep(2);

    int optimization_percentage = (rand() % 100) + 1; // generate random number from 1 to 100
    printf("Optimizing boot speed by %d%%...\n", optimization_percentage);
    sleep(2);

    if (optimization_percentage >= 80) {
        printf("Wow, you got lucky! Your %s CPU is now running at lightning speed!\n", cpu_specs);
    } else if (optimization_percentage >= 50) {
        printf("Not bad, your %s CPU is now running faster than before!\n", cpu_specs);
    } else {
        printf("Sorry, your %s CPU is still slow as a snail...\n", cpu_specs);
    }

    printf("Thanks for using the %s Boot Optimizer! Come again soon (if you dare)!\n", cpu_specs);

    return 0;
}