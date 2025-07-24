//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

int main() {
    int targetSteps;
    printf("Enter your daily step target: ");
    scanf("%d", &targetSteps);

    int totalSteps = 0;
    bool goalReached = false;

    while (!goalReached) {
        int steps;
        printf("Enter today's steps: ");
        scanf("%d", &steps);

        totalSteps += steps;
        printf("Total Steps: %d \n", totalSteps);

        if (totalSteps >= targetSteps) {
            printf("Congratulations! Goal reached.\n");
            goalReached = true;
        }
        else {
            int remainingSteps = targetSteps - totalSteps;
            printf("Only %d steps left to reach your goal.\n", remainingSteps);
        }
    }

    return 0;
}