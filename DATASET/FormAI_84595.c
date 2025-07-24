//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int year, month, day, hour, minute, second;
    struct tm * current_time;
    time_t seconds;

    // Get current time
    time(&seconds);
    current_time = localtime(&seconds);

    // Print current time
    printf("Current Time: %02d-%02d-%04d %02d:%02d:%02d\n",
            current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900,
            current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

    printf("\nWelcome to the Time Travel Simulator!\n");

    // Get user input for year, month, day, hour, minute and second
    printf("\nEnter the year you want to travel to (format: yyyy): ");
    scanf("%d", &year);

    printf("Enter the month you want to travel to (format: mm): ");
    scanf("%d", &month);

    printf("Enter the day you want to travel to (format: dd): ");
    scanf("%d", &day);

    printf("Enter the hour you want to travel to (format: hh): ");
    scanf("%d", &hour);

    printf("Enter the minute you want to travel to (format: mm): ");
    scanf("%d", &minute);

    printf("Enter the second you want to travel to (format: ss): ");
    scanf("%d", &second);

    // Set time to user input
    current_time->tm_year = year - 1900;
    current_time->tm_mon = month - 1;
    current_time->tm_mday = day;
    current_time->tm_hour = hour;
    current_time->tm_min = minute;
    current_time->tm_sec = second;

    // Convert time to seconds
    seconds = mktime(current_time);

    // Set the system time to the user input time
    system("echo `date -u -r $EPOCHSECONDS +%Y%m%d%H%M.%S`");

    printf("\nYou have successfully time travelled to %02d-%02d-%04d %02d:%02d:%02d!\n",
            day, month, year, hour, minute, second);

    return 0;
}