//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <time.h>

int main() {
    time_t t;  // declare time variable
    struct tm travelTime = {0};  // declare travelTime object of type struct tm, initialized to all 0s

    // set desired year, month, day, hour, minute, and second for time travel
    travelTime.tm_year = 1955;
    travelTime.tm_mon = 10;
    travelTime.tm_mday = 5;
    travelTime.tm_hour = 6;
    travelTime.tm_min = 30;
    travelTime.tm_sec = 0;

    // convert travelTime to a time_t value
    t = mktime(&travelTime);

    // check that mktime was successful in converting the struct tm to time_t
    if (t == -1) {
        printf("Error creating time travel instance!\n");
        return 1;
    }

    printf("Welcome to the Time Travel Simulator!\n");
    printf("The date and time you have chosen to travel back to is: %s", asctime(&travelTime));

    // initiate time travel countdown, starting at 10 seconds and counting down to 0 seconds
    for (int i = 10; i >= 0; i--) {
        printf("%d...\n", i);
        sleep(1);  // pause for 1 second using sleep() function
    }

    // compare current time (now) to time travel instance (t) using difftime() function
    double differenceInSeconds = difftime(t, time(NULL));

    printf("You have successfully time traveled!\n");
    printf("The time travel took approximately %f seconds.\n", differenceInSeconds);

    return 0;
}