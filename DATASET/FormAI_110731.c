//FormAI DATASET v1.0 Category: Date and time ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
    // declare variables for date and time
    time_t current_time;
    struct tm *time_info;
    char date[50];
    char formatted_time[50];

    // get current time
    time(&current_time);

    // convert current time to local time
    time_info = localtime(&current_time);

    // format date and time
    strftime(date, 50, "%d/%m/%Y", time_info);
    strftime(formatted_time, 50, "%I:%M:%S %p", time_info);

    // print the date and time
    printf("Today is %s\n", date);
    printf("The time is %s\n", formatted_time);

    // wait for 5 seconds
    printf("Waiting for 5 seconds...\n");
    sleep(5);

    // get new current time and format it
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(formatted_time, 50, "%I:%M:%S %p", time_info);

    // print the updated time
    printf("The time now is %s\n", formatted_time);

    return 0;
}