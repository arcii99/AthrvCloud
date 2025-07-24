//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate time travel and return a random date and time
void timeTravel() {
    time_t current_time, random_time;
    struct tm* current_timeinfo;
    struct tm* random_timeinfo;
    char current_time_str[80];
    char random_time_str[80];
    int year, month, day, hour, minute, second;

    // Get current time
    time(&current_time);
    current_timeinfo = localtime(&current_time);

    // Generate random time in the past
    srand(time(NULL));
    year = rand() % (current_timeinfo->tm_year + 1900);
    month = rand() % 12 + 1;
    day = rand() % 28 + 1;  // Assume all months have 28 days for simplicity
    hour = rand() % 24;
    minute = rand() % 60;
    second = rand() % 60;
    random_timeinfo = (struct tm*) malloc(sizeof(struct tm));
    random_timeinfo->tm_year = year - 1900;
    random_timeinfo->tm_mon = month - 1;
    random_timeinfo->tm_mday = day;
    random_timeinfo->tm_hour = hour;
    random_timeinfo->tm_min = minute;
    random_timeinfo->tm_sec = second;
    random_timeinfo->tm_isdst = -1;  // Let mktime() figure out DST

    // Convert time to strings and print
    strftime(current_time_str, 80, "%Y-%m-%d %H:%M:%S", current_timeinfo);
    strftime(random_time_str, 80, "%Y-%m-%d %H:%M:%S", random_timeinfo);
    printf("Current time: %s\n", current_time_str);
    printf("Random time in the past: %s\n", random_time_str);

    // Convert random time to time_t and check if it is earlier than current time
    random_time = mktime(random_timeinfo);
    if (random_time < current_time) {
        printf("Time travel successful!\n");
    } else {
        printf("Time travel failed.\n");
    }

    free(random_timeinfo);
}

int main() {
    timeTravel();
    return 0;
}