//FormAI DATASET v1.0 Category: Date and time ; Style: satisfied
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm * time_info;
    char time_string[50];
    int hour, minute, second, year, month, day;
    
    // Get current time information
    time(&current_time);
    time_info = localtime(&current_time);
    
    // Format time string
    strftime(time_string, sizeof(time_string), "%H:%M:%S %m/%d/%Y", time_info);
    printf("Current date and time: %s\n", time_string);
    
    // Get individual time elements
    hour = time_info->tm_hour;
    minute = time_info->tm_min;
    second = time_info->tm_sec;
    year = time_info->tm_year + 1900; // add 1900 to get current year
    month = time_info->tm_mon + 1; // add 1 to get current month
    day = time_info->tm_mday;
    
    // Print individual time elements
    printf("Current time: %02d:%02d:%02d\n", hour, minute, second);
    printf("Current date: %02d/%02d/%d\n", month, day, year);
    
    // Calculate Unix timestamp for specific date and time
    struct tm date_time = {0};
    date_time.tm_year = 2022 - 1900; // year - 1900
    date_time.tm_mon = 9 - 1; // month - 1 (October)
    date_time.tm_mday = 31; // 31st
    date_time.tm_hour = 18; // 6pm
    date_time.tm_min = 30;
    date_time.tm_sec = 0;
    time_t timestamp = mktime(&date_time);
    printf("Unix timestamp for October 31, 2022 6:30pm: %ld\n", (long)timestamp);
    
    return 0;
}