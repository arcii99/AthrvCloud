//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int year;
    time_t epoch_time;
    struct tm *time_info;
    char time_str[26];

    time(&epoch_time);
    time_info = localtime(&epoch_time);

    year = time_info->tm_year;
    
    // Prompt user for time travel input
    printf("Enter number of years you want to travel back in time (negative for future): ");
    int years_to_travel;
    scanf("%d", &years_to_travel);

    // Adjust year and print current and travel back year
    year -= years_to_travel;
    printf("Current year: %d\n", time_info->tm_year + 1900);
    printf("Year after time travel: %d\n", year + 1900);

    time_info->tm_year = year;
    epoch_time = mktime(time_info);

    // Convert time back to string
    strftime(time_str, sizeof(time_str), "%c", time_info);
    printf("Date after time travel: %s\n", time_str);
    
    return 0;
}