//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t present_time;
    struct tm *time_info;

    time(&present_time);
    time_info = localtime(&present_time);

    printf("Welcome to the Time Travel Simulator!\n\n");

    printf("Current date and time: %s", asctime(time_info));

    printf("Enter the number of years you want to travel back in time: ");
    int years;
    scanf("%d", &years);

    time_info->tm_year -= years;
    mktime(time_info);

    printf("You have arrived on %s", asctime(time_info));

    return 0;
}