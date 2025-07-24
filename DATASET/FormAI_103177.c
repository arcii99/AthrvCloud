//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate time travel
void timeTravel(int destinationYear) {
    int currentYear;
    time_t t;
    struct tm *tm;

    // Get the current year
    t = time(NULL);
    tm = localtime(&t);
    currentYear = tm->tm_year + 1900;

    if (destinationYear < currentYear) {
        // Traveling back in time
        printf("You have traveled back in time to the year %d.\n", destinationYear);
        printf("WARNING: Any changes you make to the past may have unforeseen consequences on the present and future!");

    } else if (destinationYear == currentYear) {
        // Already in the destination year
        printf("You are already in the year %d.\n", destinationYear);

    } else {
        // Traveling to the future
        printf("You have traveled to the year %d.\n", destinationYear);
        printf("WARNING: Any knowledge or technology you bring back to the present may alter the course of history!");

    }
}

// Main function to test the time travel function
int main() {
    int destinationYear;
    printf("Welcome to the time travel simulator!\n");
    printf("Enter the year you would like to travel to: ");
    scanf("%d", &destinationYear);
    timeTravel(destinationYear);

    return 0;
}