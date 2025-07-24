//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    char time_string[50];

    // Get current time and print it
    current_time = time(NULL);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "Current time: %m/%d/%Y %H:%M:%S", time_info);
    printf("%s\n", time_string);
    
    // Time travel to December 31st, 1999 at 11:59:50 PM
    struct tm travel_time = {0};
    travel_time.tm_year = 99;
    travel_time.tm_mon = 11;
    travel_time.tm_mday = 31;
    travel_time.tm_hour = 23;
    travel_time.tm_min = 59;
    travel_time.tm_sec = 50;
    time_t travel_time_seconds = mktime(&travel_time);

    // Calculate the difference in time and print it
    double time_diff = difftime(travel_time_seconds, current_time);
    printf("Time travel activated! Jumping back %d seconds.\n", (int)time_diff);

    // Wait for the specified time
    sleep((int)time_diff);

    // Print that we have successfully time traveled
    printf("Time travel completed! Welcome to Y2K!\n");

    return 0;
}