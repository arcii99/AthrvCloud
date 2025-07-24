//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <time.h>

int main() {

    time_t current_time;
    struct tm *time_info;
    char time_buffer[80];

    //get the current time and format it to display
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
    printf("Current time is %s\n", time_buffer);

    //simulate time travel to a different point in time
    struct tm travel_time = {0}; 
    travel_time.tm_year = 1066 - 1900;
    travel_time.tm_mon = 9;
    travel_time.tm_mday = 14;
    travel_time.tm_hour = 10;
    travel_time.tm_min = 0;
    travel_time.tm_sec = 0;

    //convert the travel time to UNIX time and format it for display
    time_t travel_time_unix = mktime(&travel_time);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", &travel_time);
    printf("Traveling to %s....\n", time_buffer);

    //wait for 5 seconds to simulate time travel
    printf("....\n");
    sleep(5);

    //get the current time and format it to display
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
    printf("Arrived in %s!\n", time_buffer);

    return 0;
}