//FormAI DATASET v1.0 Category: Date and time ; Style: lively
#include <stdio.h>
#include <time.h>

int main()
{
    char daysOfWeek[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char monthsOfYear[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;
    int dayOfWeek = localTime->tm_wday;

    printf("Today's date is %s, %s %d, %d\n",
            daysOfWeek[dayOfWeek], monthsOfYear[month-1], day, year);

    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    int second = localTime->tm_sec;

    printf("The time is %02d:%02d:%02d\n", hour, minute, second);
    
    return 0;
}