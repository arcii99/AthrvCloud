//FormAI DATASET v1.0 Category: Date and time ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Get current time
    time_t current_time = time(NULL);
    // Convert current time to local time
    struct tm *local_time = localtime(&current_time);

    // Display current date and time
    printf("Current date and time: %s", asctime(local_time));

    // Modify local time by adding 10 minutes
    local_time -> tm_min += 10;
    // Reformat modified time
    mktime(local_time);

    // Display modified date and time
    printf("Modified date and time: %s", asctime(local_time));

    return 0;
}