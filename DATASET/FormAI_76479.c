//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int year, month, day, hour, minute, second;
    char sign;

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    year = tm->tm_year + 1900;
    month = tm->tm_mon + 1;
    day = tm->tm_mday;
    hour = tm->tm_hour;
    minute = tm->tm_min;
    second = tm->tm_sec;

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("You are currently in the year %d, month %d, day %d, %02d:%02d:%02d\n\n",
           year, month, day, hour, minute, second);

    printf("Enter the number of years you want to travel in time: ");
    scanf("%d", &year);

    printf("Do you want to travel forward or backward in time? (+/-): ");
    scanf(" %c", &sign);

    if (sign == '-') {
        year = -year;
    }

    tm->tm_year += year;
    mktime(tm);

    printf("\nYou have traveled %d years %s in time!\n\n", abs(year), (sign == '-') ? "backwards" : "forwards");
    printf("You have arrived in the year %d, month %d, day %d, %02d:%02d:%02d\n",
           tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    return 0;
}