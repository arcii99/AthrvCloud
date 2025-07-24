//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime = time(NULL); // Get the current time
    printf("The current date and time is: %s\n", ctime(&currentTime));

    // Manual time input
    struct tm timeSet;
    printf("Enter a date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%d-%d-%d %d:%d:%d",
          &timeSet.tm_year, &timeSet.tm_mon, &timeSet.tm_mday,
          &timeSet.tm_hour, &timeSet.tm_min, &timeSet.tm_sec);
    timeSet.tm_year -= 1900; // Need to adjust year value
    timeSet.tm_mon -=1; // Need to adjust month value
    time_t timeToTravel = mktime(&timeSet);

    // Calculate time difference
    double timeDiff = difftime(timeToTravel, currentTime);
    if (timeDiff < 0) {
        // Handle going back to the past
        printf("You have gone back in time! The date and time you entered is earlier than the current time.\n");
        timeDiff *= -1;
    }
    int years = (int)(timeDiff / (60 * 60 * 24 * 365)); // Number of years travelled
    timeDiff -= years * 60 * 60 * 24 * 365; // Remove years from time difference
    int days = (int)(timeDiff / (60 * 60 * 24)); // Number of days travelled
    timeDiff -= days * 60 * 60 * 24; // Remove days from time difference
    int hours = (int)(timeDiff / (60 * 60)); // Number of hours travelled
    timeDiff -= hours * 60 * 60; // Remove hours from time difference
    int mins = (int)(timeDiff / 60); // Number of minutes travelled
    timeDiff -= mins * 60; // Remove minutes from time difference
    int secs = (int)timeDiff; // Number of seconds travelled

    // Print out time travelled
    printf("You have travelled %d years, %d days, %d hours, %d minutes, and %d seconds.\n",
           years, days, hours, mins, secs);

    return 0;
}