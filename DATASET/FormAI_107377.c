//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Get current time
    time_t now = time(NULL);

    // Initialize variables
    int year, month, day, hour, minute, second;
    struct tm *timeinfo;

    // Prompt user for input
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter hour: ");
    scanf("%d", &hour);
    printf("Enter minute: ");
    scanf("%d", &minute);
    printf("Enter second: ");
    scanf("%d", &second);

    // Set time structure
    timeinfo = localtime(&now);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = minute;
    timeinfo->tm_sec = second;

    // Convert to epoch time
    time_t epoch = mktime(timeinfo);

    // Print results
    printf("\nCurrent Time: %s", ctime(&now));
    printf("Travel Time: %s", ctime(&epoch));

    return 0;
}