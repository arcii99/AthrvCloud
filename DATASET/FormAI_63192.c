//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand((unsigned) time(&t));

    int year = rand() % 10000; // Randomly selecting a year from 0-9999
    int month = rand() % 12 + 1; // Randomly selecting a month from 1-12
    int day = rand() % 31 + 1; // Randomly selecting a day from 1-31 (ignoring leap years)
    int hour = rand() % 24; // Randomly selecting an hour from 0-23
    int minute = rand() % 60; // Randomly selecting a minute from 0-59
    int second = rand() % 60; // Randomly selecting a second from 0-59

    struct tm time_struct = {0};
    time_struct.tm_year = year - 1900;
    time_struct.tm_mon = month - 1;
    time_struct.tm_mday = day;
    time_struct.tm_hour = hour;
    time_struct.tm_min = minute;
    time_struct.tm_sec = second;

    time_t time_travel = mktime(&time_struct);

    char buffer[26];
    ctime_r(&time_travel, buffer);

    printf("You have time traveled to %s", buffer);

    return 0;

}