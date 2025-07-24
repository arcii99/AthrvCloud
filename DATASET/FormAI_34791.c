//FormAI DATASET v1.0 Category: Date and time ; Style: happy
#include <stdio.h>
#include <time.h>

int main() {
    printf("Welcome to the Happy Time!\n\n");

    time_t currentTime = time(NULL);
    struct tm* timeInfo = localtime(&currentTime);

    int day = timeInfo->tm_mday;
    int month = timeInfo->tm_mon + 1;
    int year = timeInfo->tm_year + 1900;
    printf("Today is %02d/%02d/%d!\n", day, month, year);

    int hour = timeInfo->tm_hour;
    int minute = timeInfo->tm_min;
    int second = timeInfo->tm_sec;
    printf("The time is %02d:%02d:%02d right now!\n", hour, minute, second);

    printf("Let's add one second to the current time!\n");
    currentTime++;
    timeInfo = localtime(&currentTime);
    printf("The new time is %02d:%02d:%02d!\n", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);

    printf("\nI hope you had a happy time with me!\n");
    return 0;
}