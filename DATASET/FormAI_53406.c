//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: dynamic
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;

    // get current time
    time(&current_time);

    // print current time
    printf("Current time: %s", ctime(&current_time));

    // set the time machine
    struct tm time_machine;
    time_machine.tm_year = 1995 - 1900;
    time_machine.tm_mon = 5;
    time_machine.tm_mday = 24;
    time_machine.tm_hour = 12;
    time_machine.tm_min = 0;
    time_machine.tm_sec = 0;

    // convert time machine to epoch time
    time_t time_machine_epoch = mktime(&time_machine);

    // print time machine
    printf("Time machine set to: %s", ctime(&time_machine_epoch));

    // travel to time machine
    printf("You travel back in time to %s", ctime(&time_machine_epoch));

    // calculate how far in the past we are
    double diff_seconds = difftime(current_time, time_machine_epoch);
    double diff_years = diff_seconds / (60.0 * 60.0 * 24.0 * 365.0);

    // print how far in the past we are
    printf("You traveled back %.2f years to May 24, 1995.\n", diff_years);

    return 0;
}