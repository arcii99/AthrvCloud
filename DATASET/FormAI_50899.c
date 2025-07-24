//FormAI DATASET v1.0 Category: Date and time ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

int main() {
    // Get current time
    time_t currentTime;
    time(&currentTime);
    
    // Convert current time to local time
    struct tm* localTime = localtime(&currentTime);
 
    // Print current date and time in a human-readable format
    printf("Current Date and Time: %s", asctime(localTime));
    
    // Set a specific date and time
    struct tm customTime = {0};
    customTime.tm_year = 2021 - 1900; // Year - 1900
    customTime.tm_mon = 5; // Month (0-11, January = 0)
    customTime.tm_mday = 23; // Day of the month (1-31)
    customTime.tm_hour = 15; // Hour (0-23)
    customTime.tm_min = 30; // Minute (0-59)
    customTime.tm_sec = 0; // Second (0-60, 60 represents leap second)
    
    // Convert custom time to Unix timestamp
    time_t customTimestamp = mktime(&customTime);
    
    // Convert custom timestamp to local time
    struct tm* customLocalTime = localtime(&customTimestamp);
    
    // Print custom date and time in a human-readable format
    printf("Custom Date and Time: %s", asctime(customLocalTime));
    
    return 0;
}