//FormAI DATASET v1.0 Category: System administration ; Style: content
#include <stdio.h>
#include <time.h>

int main() {

    // declare variables
    time_t current_time;
    struct tm * time_info;
    char time_string[50];

    // get current time
    time(&current_time);
    time_info = localtime(&current_time);

    // format time string
    strftime(time_string, 50, "%Y-%m-%d %H:%M:%S", time_info);

    // print time to console
    printf("Current date and time: %s\n", time_string);

    return 0;
}