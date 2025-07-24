//FormAI DATASET v1.0 Category: Date and time ; Style: expert-level
#include <stdio.h>
#include <time.h>

void print_current_time() {
    time_t current_time;
    struct tm* time_info;
    char time_string[50];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    printf("Current Time: %s\n", time_string);
}

void print_tomorrow_date() {
    time_t current_time;
    struct tm* time_info;
    char date_string[50];

    time(&current_time);
    time_info = localtime(&current_time);
    time_info->tm_mday++;

    strftime(date_string, sizeof(date_string), "%Y-%m-%d", time_info);

    printf("Tomorrow's Date: %s\n", date_string);
}

int main() {
    print_current_time();
    print_tomorrow_date();

    return 0;
}