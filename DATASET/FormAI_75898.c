//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: ultraprecise
#include <stdio.h>
#include <time.h>

int main()
{
    // Set the current time
    time_t now = time(NULL);

    // Define the time travel destination
    struct tm destination;
    destination.tm_year = 2010 - 1900;
    destination.tm_mon = 1 - 1;
    destination.tm_mday = 1;
    destination.tm_hour = 0;
    destination.tm_min = 0;
    destination.tm_sec = 0;

    // Convert the destination time to a timestamp
    time_t destinationTimestamp = mktime(&destination);

    // Calculate the time difference
    double timeDifference = difftime(destinationTimestamp, now);

    // Print the current time
    printf("Current time: %s", ctime(&now));

    // Wait for 3 seconds
    sleep(3);

    // Print the time travel message
    printf("You have successfully traveled back in time!\n");

    // Print the destination time
    printf("Destination time: %s", ctime(&destinationTimestamp));

    // Print the time travel duration
    printf("Time travel duration: %.2f seconds\n", timeDifference);

    return 0;
}