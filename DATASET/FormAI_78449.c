//FormAI DATASET v1.0 Category: Date and time ; Style: sophisticated
#include<stdio.h>
#include<time.h>

int main()
{
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;
    int hour = localTime->tm_hour;
    int min = localTime->tm_min;
    int sec = localTime->tm_sec;

    printf("Current Date and Time: %02d/%02d/%d %02d:%02d:%02d\n", day, month, year, hour, min, sec);

    struct tm newTime = *localTime;
    newTime.tm_mday += 30;  // add 30 days
    mktime(&newTime);

    day = newTime.tm_mday;
    month = newTime.tm_mon + 1;
    year = newTime.tm_year + 1900;

    printf("Date after 30 days: %02d/%02d/%d %02d:%02d:%02d\n", day, month, year, hour, min, sec);

    return 0;
}