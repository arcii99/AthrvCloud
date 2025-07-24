//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t currentTime;
    struct tm *currentDate;

    // Getting the current date and time
    currentTime = time(NULL);
    currentDate = localtime(&currentTime);

    // Printing the current date and time
    printf("Current date and time: %s", asctime(currentDate));

    // Adding 10 years to the current time
    currentDate->tm_year += 10;
    time_t futureTime = mktime(currentDate);
    struct tm *futureDate = localtime(&futureTime);

    // Printing the future date and time
    printf("After 10 years, the date and time will be: %s", asctime(futureDate));

    // Subtracting 5 years from the future time
    futureDate->tm_year -= 5;
    futureTime = mktime(futureDate);
    struct tm *pastDate = localtime(&futureTime);

    // Printing the past date and time
    printf("5 years before the future date and time will be: %s", asctime(pastDate));

    return 0;
}