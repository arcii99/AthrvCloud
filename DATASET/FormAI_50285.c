//FormAI DATASET v1.0 Category: Date and time ; Style: synchronous
#include <stdio.h>
#include <time.h>

int main() {
    struct tm *local_time;
    time_t current_time;

    // Get current time
    time(&current_time);

    // Convert to local time
    local_time = localtime(&current_time);

    // Print date and time
    printf("Current Date and Time: %s", asctime(local_time));

    // Print day of week
    char *day_of_week;
    switch(local_time->tm_wday) {
        case 0:
            day_of_week = "Sunday";
            break;
        case 1:
            day_of_week = "Monday";
            break;
        case 2:
            day_of_week = "Tuesday";
            break;
        case 3:
            day_of_week = "Wednesday";
            break;
        case 4:
            day_of_week = "Thursday";
            break;
        case 5:
            day_of_week = "Friday";
            break;
        case 6:
            day_of_week = "Saturday";
            break;
    }
    printf("Today is %s\n", day_of_week);

    // Print month
    char *month;
    switch(local_time->tm_mon) {
        case 0:
            month = "January";
            break;
        case 1:
            month = "February";
            break;
        case 2:
            month = "March";
            break;
        case 3:
            month = "April";
            break;
        case 4:
            month = "May";
            break;
        case 5:
            month = "June";
            break;
        case 6:
            month = "July";
            break;
        case 7:
            month = "August";
            break;
        case 8:
            month = "September";
            break;
        case 9:
            month = "October";
            break;
        case 10:
            month = "November";
            break;
        case 11:
            month = "December";
            break;
    }
    printf("Current month is %s\n", month);

    return 0;
}