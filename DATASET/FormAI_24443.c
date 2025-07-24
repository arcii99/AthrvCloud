//FormAI DATASET v1.0 Category: Date and time ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t current_time;
    struct tm * time_info;
    char timeString[50];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", time_info);

    printf("Current date & time: %s\n", timeString);

    char changedtime[50];
    strncpy(changedtime, timeString, strlen(timeString));
    changedtime[11] = 'T';
    printf("Current date & time in ISO 8601 format: %s\n", changedtime);
    return 0;
}