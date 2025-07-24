//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t current_time;
    struct tm * time_info;
    char time_string[9]; // HH:MM:SS\0

    // Get current time
    current_time = time(NULL);
    time_info = localtime(&current_time);

    // Convert time to string format
    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    printf("Current time: %s\n", time_string);

    // Enter desired era to time travel to
    printf("Enter desired era to time travel to (1: Jurassic, 2: Medieval, 3: Renaissance): ");
    int era;
    scanf("%d", &era);

    // Set new time based on chosen era
    switch (era) {
        case 1: // Jurassic era (65 million years ago)
            time_info->tm_year = -65;
            break;
        case 2: // Medieval era (476 AD - 1453 AD)
            time_info->tm_year = 800; // set to middle of medieval period
            break;
        case 3: // Renaissance era (14th century - 17th century)
            time_info->tm_year = 1550; // set to middle of renaissance period
            break;
        default:
            printf("Invalid selection\n");
            exit(1);
    }

    // Convert new time to string format
    current_time = mktime(time_info);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    printf("Time after time travel: %s\n", time_string);

    return 0;
}