//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t present_time;
    struct tm *present_tm;

    time(&present_time);
    present_tm = localtime(&present_time);

    printf("Current date and time: %s", asctime(present_tm));
    printf("Enter the year you want to travel to (1000-9999): ");
    int year;
    scanf("%d", &year);

    if (year < 1000 || year > 9999) {
        printf("Invalid year entered. Program exit.\n");
        return 0;
    }

    struct tm target_date = {0};
    target_date.tm_year = year - 1900;

    printf("\nSetting the time machine to year %d...\n", year);

    while (difftime(mktime(&target_date), present_time) > 0) {
        present_time += 60;
        present_tm = localtime(&present_time);

        printf("Current date and time: %s", asctime(present_tm));
    }

    printf("Welcome to the year %d!\n", year);

    return 0;
}