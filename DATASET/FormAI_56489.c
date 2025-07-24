//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdbool.h>

int main() {
    int year = 2021;
    int targetYear;
    bool success = false;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter target year: ");
    scanf("%d", &targetYear);

    while (!success) {
        if (targetYear < year) {
            printf("You cannot travel back in time.\n");
            printf("Please enter a target year after %d: ", year);
            scanf("%d", &targetYear);
        } else if (targetYear > 3000) {
            printf("Sorry, you cannot travel that far into the future.\n");
            printf("Please enter a target year before 3000: ");
            scanf("%d", &targetYear);
        } else {
            printf("Preparing to travel to %d...\n", targetYear);
            success = true;
        }
    }

    printf("Arrived in %d!\n", targetYear);

    return 0;
}