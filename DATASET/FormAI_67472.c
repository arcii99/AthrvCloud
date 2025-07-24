//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm * time_info;
    char time_string[100];

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Please enter a year to travel to: ");
    int year;
    scanf("%d", &year);

    //get the current time
    time(&current_time);
    time_info = localtime(&current_time);

    //set the time to the selected year
    time_info->tm_year = year - 1900;
    time_info->tm_mon = 0;
    time_info->tm_mday = 1;
    time_info->tm_hour = 0;
    time_info->tm_min = 0;
    time_info->tm_sec = 0;
    current_time = mktime(time_info);

    //format and print the time
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
    printf("\nYou have travelled to %s!\n", time_string);

    //print some fun facts about the selected year
    printf("\nFun Facts:\n");
    if (year == 1969) {
        printf("- Apollo 11 landed on the moon\n");
    }
    if (year == 1985) {
        printf("- Back to the Future was released\n");
    }
    if (year == 2001) {
        printf("- 9/11 terrorist attacks occurred\n");
    }
    if (year == 2021) {
        printf("- COVID-19 pandemic is ongoing\n");
    }

    return 0;
}