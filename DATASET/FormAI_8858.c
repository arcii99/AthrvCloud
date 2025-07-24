//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int year, month, day, hour, minute, seconds;
    
    printf("Welcome to the Time Travel Simulator!\n\n");

    printf("Enter the year you would like to travel to (between 1900 and 2021): ");
    scanf("%d", &year);

    if (year < 1900 || year > 2021) {
        printf("Invalid year entered! Please enter a year between 1900 and 2021.\n");
        return 0;
    }

    printf("Enter the month you would like to travel to (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month entered! Please enter a month between 1 and 12.\n");
        return 0;
    }

    printf("Enter the day you would like to travel to (1-31): ");
    scanf("%d", &day);

    if (day < 1 || day > 31) {
        printf("Invalid day entered! Please enter a day between 1 and 31.\n");
        return 0;
    }

    printf("Enter the hour you would like to travel to (0-23): ");
    scanf("%d", &hour);

    if (hour < 0 || hour > 23) {
        printf("Invalid hour entered! Please enter an hour between 0 and 23.\n");
        return 0;
    }

    printf("Enter the minute you would like to travel to (0-59): ");
    scanf("%d", &minute);

    if (minute < 0 || minute > 59) {
        printf("Invalid minute entered! Please enter a minute between 0 and 59.\n");
        return 0;
    }

    printf("Enter the seconds you would like to travel to (0-59): ");
    scanf("%d", &seconds);

    if (seconds < 0 || seconds > 59) {
        printf("Invalid seconds entered! Please enter seconds between 0 and 59.\n");
        return 0;
    }

    printf("\nCalculating time travel...\n\n");

    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = seconds;

    time_t new_time = mktime(&tm);

    printf("You have successfully time traveled!\n");
    printf("The original date and time was: %02d/%02d/%d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    gmtime_r(&new_time, &tm);

    printf("The new date and time is: %02d/%02d/%d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    return 0;
}