//FormAI DATASET v1.0 Category: Date and time ; Style: creative
#include <stdio.h>
#include <time.h>

int main(void) {
    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);
    int hour = time_info->tm_hour;
    char meridian[3];
    if (hour < 12) {
        sprintf(meridian, "AM");
    } else {
        sprintf(meridian, "PM");
    }
    if (hour == 0) {
        hour = 12;
    } else if (hour > 12) {
        hour -= 12;
    }
    printf("The current time is %d:%02d %s\n", hour, time_info->tm_min, meridian);
    char* weekday_names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Today is %s, %s %d, %d\n", weekday_names[time_info->tm_wday], month_names[time_info->tm_mon], time_info->tm_mday, time_info->tm_year + 1900);
    return 0;
}