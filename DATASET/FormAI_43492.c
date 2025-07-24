//FormAI DATASET v1.0 Category: Date and time ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    char time_string[30];

    // Get the current time
    current_time = time(NULL);

    // Get the local time struct
    time_info = localtime(&current_time);

    // Format the time string
    strftime(time_string, sizeof(time_string), "%A, %B %d, %Y %r", time_info);

    // Print the time string
    printf("Current date and time: %s\n", time_string);

    return 0;
}