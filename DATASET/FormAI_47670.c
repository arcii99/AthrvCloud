//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void timeTravel(int year, int month, int day, int hour, int minute, int second) {
    struct tm timeToTravel;
    timeToTravel.tm_year = year - 1900;
    timeToTravel.tm_mon = month - 1;
    timeToTravel.tm_mday= day;
    timeToTravel.tm_hour = hour;
    timeToTravel.tm_min = minute;
    timeToTravel.tm_sec = second;
    time_t timeTravelled = mktime(&timeToTravel);
    printf("Welcome to the Time Travel Simulator!\n");
    for (int i = 5; i >= 1; i--) {
        printf("Initializing Time Travel in %d...\n", i);
        usleep(1000000);
    }
    printf("Initiating Time Travel...\n");
    usleep(2000000);
    printf("You have successfully traveled to the past!\n");
    printf("Current Date and Time: %s", ctime(&timeTravelled));
}

int main() {
    int year, month, day, hour, minute, second;
    printf("Enter the year (1900-2100): ");
    scanf("%d", &year);
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the day (1-31): ");
    scanf("%d", &day);
    printf("Enter the hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter the minute (0-59): ");
    scanf("%d", &minute);
    printf("Enter the second (0-59): ");
    scanf("%d", &second);
    timeTravel(year, month, day, hour, minute, second);
    return 0;
}