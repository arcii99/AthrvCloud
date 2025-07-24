//FormAI DATASET v1.0 Category: Date and time ; Style: sophisticated
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm* time_info;
    char time_string[20];
    char date_string[20];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    strftime(date_string, sizeof(date_string), "%Y-%m-%d", time_info);

    printf("Current time: %s\n", time_string);
    printf("Current date: %s\n", date_string);

    return 0;
}