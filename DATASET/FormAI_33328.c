//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: future-proof
#include <stdio.h>
#include <time.h>

int main() {
    // Get current time
    struct tm *currTime;
    time_t now;
    time(&now);
    currTime = localtime(&now);

    // Print current time
    printf("Current time: %s", asctime(currTime));

    // Get user input
    printf("Enter a year to travel to: ");
    int year;
    scanf("%d", &year);

    // Set travel time
    struct tm travelTime;
    travelTime.tm_sec = 0;
    travelTime.tm_min = 0;
    travelTime.tm_hour = 0;
    travelTime.tm_mday = 1;
    travelTime.tm_mon = 0;
    travelTime.tm_year = year - 1900;

    // Calculate difference in seconds between current time and travel time
    time_t currSec = mktime(currTime);
    time_t travelSec = mktime(&travelTime);
    double diff = difftime(travelSec, currSec);

    // Print travel time
    printf("Travel time: %s", asctime(&travelTime));

    // Handle time travel to past and future
    if (diff > 0) {
        printf("You have travelled to a future year!\n");
        printf("You have travelled %ld seconds into the future.\n", (long)diff);
    } else if (diff < 0) {
        printf("You have travelled to a past year!\n");
        printf("You have travelled %ld seconds into the past.\n", (long)(-diff));
    } else {
        printf("You have travelled to the current year!\n");
    }
    
    return 0;
}