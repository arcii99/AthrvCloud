//FormAI DATASET v1.0 Category: Date and time ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t current_time;
    struct tm * time_info;
    char time_string[50];

    //Get current time
    time(&current_time);

    //Convert to local time
    time_info = localtime(&current_time);

    //Format time string
    strftime(time_string, sizeof(time_string), "Today is %A, %B %d, %Y. The time is %I:%M:%S %p.", time_info);
    printf("%s\n", time_string);

    //Set new date and time
    time_info->tm_year = 125; //Year 2025
    time_info->tm_mon = 0; //January
    time_info->tm_mday = 1; //1st day of the month
    time_info->tm_hour = 0; //Midnight
    time_info->tm_min = 0;
    time_info->tm_sec = 0;

    //Convert back to time_t
    current_time = mktime(time_info);

    //Format new time string
    strftime(time_string, sizeof(time_string), "Happy New Year! The date is now %A, %B %d, %Y. The time is %I:%M:%S %p.", time_info);
    printf("%s\n", time_string);

    return 0;
}