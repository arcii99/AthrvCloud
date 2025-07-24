//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t get_random_time() {
    time_t current_time;
    struct tm *time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    time_info->tm_year = rand() % (100 + 1 - 0) + 0;
    time_info->tm_mon = rand() % (11 + 1 - 0) + 0;
    time_info->tm_mday = rand() % (31 + 1 - 1) + 1;
    time_info->tm_hour = rand() % (23 + 1 - 0) + 0;
    time_info->tm_min = rand() % (59 + 1 - 0) + 0;
    time_info->tm_sec = rand() % (59 + 1 - 0) + 0;
    return mktime(time_info);
}

void time_travel(time_t travel_time) {
    char *time_string = ctime(&travel_time);
    printf("Welcome to %s", time_string);
}

int main() {
    time_t random_time = get_random_time();
    time_travel(random_time);
    return 0;
}