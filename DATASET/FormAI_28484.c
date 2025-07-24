//FormAI DATASET v1.0 Category: Date and time ; Style: active
#include <stdio.h>
#include <time.h>

int main()
{
    // Get current date and time
    time_t currentTime = time(NULL);

    // Convert to local time
    struct tm* localTime = localtime(&currentTime);

    // Print current date and time
    printf("Current date and time: %s", asctime(localTime));

    // Get user input for year, month, and day
    int year, month, day;

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter day of month (1-31): ");
    scanf("%d", &day);

    // Create custom date and time structure
    struct tm inputTime;
    inputTime.tm_year = year - 1900;
    inputTime.tm_mon = month - 1;
    inputTime.tm_mday = day;
    inputTime.tm_hour = 0;
    inputTime.tm_min = 0;
    inputTime.tm_sec = 0;

    // Convert custom date and time to Unix timestamp
    time_t inputTimeUnix = mktime(&inputTime);

    // Convert custom timestamp to local time
    struct tm* inputTimeLocal = localtime(&inputTimeUnix);

    // Print custom date and time
    printf("Custom date and time: %s", asctime(inputTimeLocal));

    return 0;
}