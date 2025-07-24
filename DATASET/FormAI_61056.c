//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    int currentYear, pastYear;

    printf("Enter the current year: ");
    scanf("%d", &currentYear);

    printf("Enter a past year to travel to: ");
    scanf("%d", &pastYear);

    if (pastYear > currentYear) {
        printf("You cannot travel to a future year!\n");
    } else {
        int yearsTraveled = currentYear - pastYear;
        printf("You have traveled %d years back in time!\n", yearsTraveled);

        printf("The year is now: %d\n", pastYear);

        if (pastYear < 1900) {
            printf("You have traveled back to a time before the internet and cell phones!\n");
        } else if (pastYear < 1960) {
            printf("You have traveled back to a time before color TV!\n");
        } else if (pastYear < 1990) {
            printf("You have traveled back to a time before the internet!\n");
        } else {
            printf("You have traveled back to a time of rapid technological change!\n");
        }
    }

    return 0;
}