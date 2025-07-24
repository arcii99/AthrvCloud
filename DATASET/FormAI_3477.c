//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: all-encompassing
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    char date_string[20];
    int year, month, day;
    
    // Obtain current time
    current_time = time(NULL);
    time_info = localtime(&current_time);
    
    // Convert current time to string and output
    strftime(date_string, sizeof(date_string), "%Y-%m-%d", time_info);
    printf("Current date is: %s\n", date_string);
    
    // Ask user to enter desired year, month, and day
    printf("Enter a future year (YYYY): ");
    scanf("%d", &year);
    printf("Enter a future month (MM): ");
    scanf("%d", &month);
    printf("Enter a future day (DD): ");
    scanf("%d", &day);
    
    // Set time to desired date
    time_info->tm_year = year - 1900;
    time_info->tm_mon = month - 1;
    time_info->tm_mday = day;
    current_time = mktime(time_info);
    
    // Convert desired time to string and output
    time_info = localtime(&current_time);
    strftime(date_string, sizeof(date_string), "%Y-%m-%d", time_info);
    printf("Desired date is: %s\n", date_string);
    
    return 0;
}