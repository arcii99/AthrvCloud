//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>

int main()
{
    int year, month, day, hour, minute, second, time_travel;
    printf("Enter the current year: ");
    scanf("%d", &year);
    printf("Enter the current month: ");
    scanf("%d", &month);
    printf("Enter the current day: ");
    scanf("%d", &day);
    printf("Enter the current hour: ");
    scanf("%d", &hour);
    printf("Enter the current minute: ");
    scanf("%d", &minute);
    printf("Enter the current second: ");
    scanf("%d", &second);
    printf("Enter the time travel (in seconds): ");
    scanf("%d", &time_travel);
    printf("\n\nCurrent time: %d/%d/%d %d:%d:%d", day, month, year, hour, minute, second);
    int total_seconds = (year*31556926) + (month*2629743) + (day*86400) + (hour*3600) + (minute*60) + second;
    total_seconds += time_travel;
    year = total_seconds / 31556926;
    month = (total_seconds % 31556926) / 2629743;
    day = ((total_seconds % 31556926) % 2629743) / 86400;
    hour = (((total_seconds % 31556926) % 2629743) % 86400) / 3600;
    minute = ((((total_seconds % 31556926) % 2629743) % 86400) % 3600) / 60;
    second = ((((total_seconds % 31556926) % 2629743) % 86400) % 3600) % 60;
    printf("\nTime travel: %d seconds", time_travel);
    printf("\nNew time: %d/%d/%d %d:%d:%d\n", day, month, year, hour, minute, second);
    return 0;
}