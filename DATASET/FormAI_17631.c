//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    time_t current_time, travel_time;
    struct tm * current_time_info = NULL;
    struct tm * travel_time_info = NULL;
    char time_string[50];

    current_time = time(NULL);
    current_time_info = localtime(&current_time);

    printf("Current Date and Time: %s", asctime(current_time_info));
    printf("Enter year to travel to: ");
    scanf("%d", &current_time_info->tm_year);
    current_time_info->tm_year -= 1900;
    printf("Enter month to travel to: ");
    scanf("%d", &current_time_info->tm_mon);
    current_time_info->tm_mon -= 1;
    printf("Enter day to travel to: ");
    scanf("%d", &current_time_info->tm_mday);
    printf("Enter hour to travel to: ");
    scanf("%d", &current_time_info->tm_hour);
    printf("Enter minute to travel to: ");
    scanf("%d", &current_time_info->tm_min);

    travel_time = mktime(current_time_info);
    travel_time_info = localtime(&travel_time);

    strftime(time_string, 50, "Travel time is: %c", travel_time_info);
    puts(time_string);

    return 0;
}