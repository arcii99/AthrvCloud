//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int main() {
    int steps[MAX_SIZE];
    int numSteps = 0;
    int totalSteps = 0;

    printf("Welcome to the Fitness Tracker!\n\n");
    printf("Please enter your steps for the day.\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("Step %d: ", i+1);
        scanf("%d", &steps[i]);
        totalSteps += steps[i];
        numSteps++;
        printf("Total Steps: %d\n", totalSteps);

        char response;
        printf("Enter 'q' to quit or any other key to continue: ");
        scanf(" %c", &response);
        if (response == 'q') {
            printf("Exiting Fitness Tracker...\n");
            break;
        }
    }

    printf("\nSummary:\n");
    printf("Number of steps recorded: %d\n", numSteps);
    printf("Total steps for the day: %d\n", totalSteps);

    return 0;
}