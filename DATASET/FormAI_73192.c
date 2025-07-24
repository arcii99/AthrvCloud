//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm * time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    printf("Current time: %s", asctime(time_info));

    // Time travel to the past
    time_info->tm_year = 90;   // year 1990
    time_info->tm_mon = 6;     // month July
    time_info->tm_mday = 22;   // day 22

    printf("Traveling back in time to July 22, 1990...\n");
    mktime(time_info);

    printf("New time: %s", asctime(time_info));

    // Time travel to the future
    time_info->tm_year = 120;  // year 2120
    time_info->tm_mon = 8;     // month September
    time_info->tm_mday = 15;   // day 15

    printf("Traveling forward in time to September 15, 2120...\n");
    mktime(time_info);

    printf("New time: %s", asctime(time_info));

    return 0;
}