//FormAI DATASET v1.0 Category: Date and time ; Style: introspective
#include <stdio.h>
#include <time.h>

int main(void) {
    time_t current_time;
    char* c_time_string;

    /* Obtain current time. */
    current_time = time(NULL);

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    /* Print current time. */
    printf("Current time is %s", c_time_string);

    /* Convert to struct tm format. */
    struct tm* time_struct;
    time_struct = localtime(&current_time);

    /* Print the year. */
    printf("Year: %d\n", time_struct->tm_year + 1900);

    /* Print the month. */
    char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Month: %s\n", months[time_struct->tm_mon]);

    /* Print the day of the month. */
    printf("Day of the month: %d\n", time_struct->tm_mday);

    /* Print the day of the week. */
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Day of the week: %s\n", days[time_struct->tm_wday]);

    /* Print the hour. */
    printf("Hour: %d\n", time_struct->tm_hour);

    /* Print the minute. */
    printf("Minute: %d\n", time_struct->tm_min);

    /* Print the second. */
    printf("Second: %d\n", time_struct->tm_sec);

    return 0;
}