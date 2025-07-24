//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <time.h>

void travelThroughTime(int year, int month, int day);

int main()
{
    int year, month, day;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a date (yyyy-mm-dd) to travel to: ");
    scanf("%d-%d-%d", &year, &month, &day);

    printf("\nTravelling through time...\n\n");

    travelThroughTime(year, month, day);

    return 0;
}

void travelThroughTime(int year, int month, int day)
{
    time_t current_time;
    struct tm *time_info;
    char time_string[30];

    time(&current_time);
    time_info = localtime(&current_time);

    time_info->tm_year = year - 1900;
    time_info->tm_mon = month - 1;
    time_info->tm_mday = day;

    mktime(time_info);

    strftime(time_string, sizeof(time_string), "%Y-%m-%d", time_info);

    printf("You have travelled to %s!\n", time_string);
}