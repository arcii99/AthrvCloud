//FormAI DATASET v1.0 Category: Date and time ; Style: excited
#include <stdio.h>
#include <time.h>

int main() {
    time_t date_time;
    struct tm *local_time;

    // get the current date and time
    time(&date_time);
    local_time = localtime(&date_time);

    // print the current date and time in various formats
    printf("Today is %d/%d/%d\n", local_time->tm_mday, local_time->tm_mon+1, local_time->tm_year+1900);
    printf("The time now is %d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
    printf("It is currently %s\n", (local_time->tm_hour >= 12) ? "afternoon" : "morning");

    // calculate the date and time exactly 1 week ago
    date_time = time(NULL) - 604800;
    local_time = localtime(&date_time);

    printf("\nExactly 1 week ago, it was %d/%d/%d %d:%02d:%02d\n", local_time->tm_mday, local_time->tm_mon+1,
        local_time->tm_year+1900, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

    // calculate the date and time 24 hours from now
    date_time = time(NULL) + 86400;
    local_time = localtime(&date_time);

    printf("24 hours from now, it will be %d/%d/%d %d:%02d:%02d\n", local_time->tm_mday, local_time->tm_mon+1,
        local_time->tm_year+1900, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

    return 0;
}