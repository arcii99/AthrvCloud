//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm * time_info;
    int year, month, day;

    printf("Welcome to the time travel simulator!\n");

    printf("Enter a year (e.g. 2021): ");
    scanf("%d", &year);

    printf("Enter a month (1-12): ");
    scanf("%d", &month);

    printf("Enter a day (1-31): ");
    scanf("%d", &day);

    time(&current_time);
    time_info = localtime(&current_time);

    printf("\nYou have traveled from %02d/%02d/%d to %02d/%02d/%d.\n\n",
           time_info->tm_mon + 1, time_info->tm_mday, time_info->tm_year + 1900,
           month, day, year);

    printf("Press any key to continue...\n");
    getchar();

    time_info->tm_year = year - 1900;
    time_info->tm_mon = month - 1;
    time_info->tm_mday = day;

    current_time = mktime(time_info);

    time(&current_time);
    time_info = localtime(&current_time);

    printf("\nYou have arrived at %02d/%02d/%d.\n",
           time_info->tm_mon + 1, time_info->tm_mday, time_info->tm_year + 1900);

    return 0;
}