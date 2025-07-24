//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Time Travel Happy Simulator!\n");
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);

    printf("\nIt is currently %d:%02d %s on %d/%d/%d.\n", current_time->tm_hour % 12, current_time->tm_min, current_time->tm_hour >= 12 ? "PM" : "AM", current_time->tm_mon + 1, current_time->tm_mday, current_time->tm_year + 1900);
   
    int year, month, day;

    printf("\nEnter a year to time travel to: ");
    scanf("%d", &year);
    printf("\nEnter a month to time travel to: ");
    scanf("%d", &month);
    printf("\nEnter a day to time travel to: ");
    scanf("%d", &day);

    time_t travel_time = mktime(&(struct tm){0,0,0,day,month-1,year-1900});
    current_time = localtime(&travel_time);

    if(now >= travel_time)
    {
        printf("\nYou successfully travelled back in time!\n");

        printf("\nIt is now %d:%02d %s on %d/%d/%d.\n", current_time->tm_hour % 12, current_time->tm_min, current_time->tm_hour >= 12 ? "PM" : "AM", current_time->tm_mon + 1, current_time->tm_mday, current_time->tm_year + 1900);
        printf("\nYou are now living in a time before the invention of the internet!");
    }
    else
    {
        printf("\nOh no, you missed your target date!\n");
        printf("\nIt is still %d:%02d %s on %d/%d/%d.\n", current_time->tm_hour % 12, current_time->tm_min, current_time->tm_hour >= 12 ? "PM" : "AM", current_time->tm_mon + 1, current_time->tm_mday, current_time->tm_year + 1900);
    }

    printf("\nThanks for using the Time Travel Happy Simulator! Have a great day!");
    return 0;
}