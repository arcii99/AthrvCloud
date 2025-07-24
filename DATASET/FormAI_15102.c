//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <time.h>

int main(void) {
    // get current time
    time_t current_time = time(NULL);
    printf("Current time: %s\n", ctime(&current_time));

    // add 10 years to current time
    struct tm *future_time = localtime(&current_time);
    future_time->tm_year += 10;
    time_t future_time_t = mktime(future_time);
    printf("Time 10 years from now: %s\n", ctime(&future_time_t));

    // go back in time to the 1800s
    struct tm back_in_time = {0};
    back_in_time.tm_mday = 1;
    back_in_time.tm_mon = 0;
    back_in_time.tm_year = 1800 - 1900;
    time_t back_in_time_t = mktime(&back_in_time);
    printf("Time in the 1800s: %s\n", ctime(&back_in_time_t));

    // travel to a specific date and time
    char datetime_str[] = "20321212113000";
    struct tm travel_time = {0};
    sscanf(datetime_str, "%4d%2d%2d%2d%2d%2d", &travel_time.tm_year, &travel_time.tm_mon, &travel_time.tm_mday, &travel_time.tm_hour, &travel_time.tm_min, &travel_time.tm_sec);
    travel_time.tm_year -= 1900;
    travel_time.tm_mon -= 1;
    time_t travel_time_t = mktime(&travel_time);
    printf("Time travel to %s: %s\n", datetime_str, ctime(&travel_time_t));

    return 0;
}