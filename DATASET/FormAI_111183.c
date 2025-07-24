//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime = time(NULL); // Get current time
    struct tm *now = localtime(&currentTime); // Convert time to struct

    // Print current date and time
    printf("Current date and time: %s", asctime(now));

    // Set time to travel to
    struct tm travelTime = *now;
    travelTime.tm_year = 114; // travel to year 2014
    travelTime.tm_mon = 6; // July
    travelTime.tm_mday = 4; // 4th day of the month
    travelTime.tm_hour = 12; // 12:00 pm noon
    travelTime.tm_min = 0; // Reset minutes and seconds
    travelTime.tm_sec = 0;

    time_t travelTime_t = mktime(&travelTime); // Convert struct time to time_t

    // Print time machine settings
    printf("Traveling to: %s", asctime(&travelTime));
    printf("Time machine programmed. Initiating countdown...\n");

    int countdown = 5; // Countdown before time travel

    // Loop countdown to time travel
    while (countdown > 0) {
        printf("%d...\n", countdown);
        sleep(1); // Wait 1 second
        countdown--;
    }

    // Time travel!
    printf("Time travel initiated!\n");
    sleep(2); // Wait 2 seconds for dramatic effect
    currentTime = time(NULL); // Get current time again

    // Print new date and time after time travel
    printf("New date and time: %s", asctime(localtime(&currentTime)));

    return 0;
}