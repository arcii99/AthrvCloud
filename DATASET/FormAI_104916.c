//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Alan Touring
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    time_t currentTime;
    struct tm *localTime;

    // get the current time
    currentTime = time(NULL);

    // convert to local time
    localTime = localtime(&currentTime);

    // print current time
    printf("Current time: %s", asctime(localTime));

    // travel to future
    int years;
    printf("\nEnter the number of years you want to travel to: ");
    scanf("%d", &years);

    // add years to current time
    localTime->tm_year += years;

    // normalize time
    mktime(localTime);

    // print future time
    printf("\nTime traveler arrives %d years later at: %s", years, asctime(localTime));

    // travel to past
    int days;
    printf("\nEnter the number of days you want to travel back to: ");
    scanf("%d", &days);

    // subtract days from current time
    currentTime -= days * 24 * 60 * 60;

    // update local time
    localTime = localtime(&currentTime);

    // print past time
    printf("\nTime traveler arrives %d days earlier at: %s", days, asctime(localTime));

    return 0;
}