//FormAI DATASET v1.0 Category: Date and time ; Style: mathematical
#include<stdio.h>
#include<time.h>

int main()
{
    time_t now;
    struct tm *ltime;
    char tstring[9];

    time(&now);
    ltime = localtime(&now);

    int year = ltime->tm_year + 1900;
    int month = ltime->tm_mon + 1;
    int day = ltime->tm_mday;
    int hour = ltime->tm_hour;
    int minute = ltime->tm_min;

    int result = ((year/2) * (month + day) * (hour - minute)) % 1000000;

    printf("The result is: %06d\n", result);

    return 0;
}