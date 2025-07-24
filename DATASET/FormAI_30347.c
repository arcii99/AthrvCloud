//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting up the time
    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    // Displaying the current time
    printf("Date and Time now: %s", asctime(currentTime));
    printf("Enter a year to travel to (1900-3000): ");
    int year;
    scanf("%d", &year);

    // Check if year is valid
    if (year < 1900 || year > 3000) {
        printf("Invalid year entered.");
        return 1;
    }

    // Update the current time to the entered year
    currentTime->tm_year = year - 1900;
    now = mktime(currentTime);

    // Displaying the updated date and time
    printf("\nAfter travelling forward in time to %d:\n", year);
    printf("Date and Time: %s", asctime(localtime(&now)));

    // Travel back to current time
    time_t currentTimeInSec = now;
    now = time(NULL);
    double secPassed = difftime(now, currentTimeInSec);
    printf("\nYou travelled back in time %.0f seconds.\n", secPassed);

    // Display the current time
    printf("Current time: %s", asctime(localtime(&now)));

    return 0; // End of the program
}