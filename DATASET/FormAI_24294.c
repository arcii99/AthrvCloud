//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t raw_time;
    struct tm * time_info;
    char time_string[50];

    // get current time
    time(&raw_time);
    time_info = localtime(&raw_time);

    // display current time
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
    printf("Current time is %s\n\n", time_string);

    // travel to the past
    printf("Let's travel to the past!\n");
    printf("Enter the number of years you want to go back: ");
    int years;
    scanf("%d", &years);
    time_info->tm_year -= years;
    mktime(time_info);

    // display past time
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
    printf("You have time-traveled back %d years to %s!\n\n", years, time_string);

    // travel to the future
    printf("Now, let's travel to the future!\n");
    printf("Enter the number of years you want to go ahead: ");
    scanf("%d", &years);
    time_info->tm_year += years;
    mktime(time_info);

    // display future time
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
    printf("You have time-traveled ahead %d years to %s!\n\n", years, time_string);

    return 0;
}