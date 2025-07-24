//FormAI DATASET v1.0 Category: Date and time ; Style: creative
#include<stdio.h>
#include<time.h>

int main()
{
    int day, month, year, hour, minute, second;
    time_t currentTime;

    // Get the current time
    time(&currentTime);

    // Format and print the current date and time
    printf("The current date and time is: %s\n", ctime(&currentTime));

    // Convert the current time to a struct tm
    struct tm *localTime = localtime(&currentTime);

    // Extract the current day, month, year, hour, minute, and second
    day = localTime->tm_mday;
    month = localTime->tm_mon + 1;
    year = localTime->tm_year + 1900;
    hour = localTime->tm_hour;
    minute = localTime->tm_min;
    second = localTime->tm_sec;

    // Print the extracted date and time values
    printf("Day: %d\n", day);
    printf("Month: %d\n", month);
    printf("Year: %d\n", year);
    printf("Hour: %d\n", hour);
    printf("Minute: %d\n", minute);
    printf("Second: %d\n", second);

    return 0;
}