//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    time_t current_time;
    struct tm * time_info;
    char time_string[9];
    
    // Get the current time
    time(&current_time);
    
    // Convert the current time to a time structure
    time_info = localtime(&current_time);
    
    // Print the current date and time
    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    printf("Current time: %s\n", time_string);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d", time_info);
    printf("Current date: %s\n", time_string);
    
    // Set a specific date and time to travel to
    struct tm travel_time;
    travel_time.tm_year = 2025 - 1900; // Year since 1900
    travel_time.tm_mon = 6 - 1; // Month (0-11, January is 0)
    travel_time.tm_mday = 1; // Day of the month (1-31)
    travel_time.tm_hour = 12; // Hour (0-23)
    travel_time.tm_min = 0; // Minute (0-59)
    travel_time.tm_sec = 0; // Second (0-60)
    
    time_t travel_time_t = mktime(&travel_time);
    
    // Calculate the time difference between the current time and the travel time
    time_t time_diff = travel_time_t - current_time;
    
    // Print the time difference in seconds
    printf("Time difference in seconds: %ld\n", time_diff);
    
    // Convert the time difference to hours, minutes, and seconds
    int hours = time_diff / 3600;
    int minutes = (time_diff % 3600) / 60;
    int seconds = time_diff % 60;
    
    // Print the time difference in a human-readable format
    printf("Time difference: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
    
    return 0;
}