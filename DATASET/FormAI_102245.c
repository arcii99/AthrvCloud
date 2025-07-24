//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime;
    struct tm *timeInfo;

    // get the current time
    time(&currentTime);
    timeInfo = localtime(&currentTime);

    // ask the user for a year to travel to
    printf("Enter a year to travel to: ");
    int year;
    scanf("%d", &year);

    // calculate the difference between the current year and the year to travel to
    int yearDifference = year - (timeInfo->tm_year + 1900);

    // travel to the specified year
    timeInfo->tm_year += yearDifference;
    currentTime = mktime(timeInfo);

    // print the date in the futuristic style
    printf("Welcome to the year %d\n", year);
    printf("The current date is %d.%d.%d\n", timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900);
    printf("The current time is %d:%02d:%02d\n", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);

    return 0;
}