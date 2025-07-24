//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time, new_time;
    struct tm *current_date, *new_date;

    // obtain current time
    current_time = time(NULL);
    current_date = localtime(&current_time);

    // display current time
    printf("Current date and time: %s", asctime(current_date));

    // prompt user for time travel input
    printf("Enter number of years to travel into the future or past: ");
    int years;
    scanf("%d", &years);

    // calculate new time using user input
    new_time = current_time + (years * 31536000); // 1 year = 31536000 seconds
    new_date = localtime(&new_time);

    // display new time
    printf("Date and time after time travel: %s", asctime(new_date));

    return 0;
}