//FormAI DATASET v1.0 Category: Date and time ; Style: satisfied
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now;
    struct tm *current_time;

    time(&now); //get current time
    current_time = localtime(&now); //convert into local time

    //print formatted date and time
    printf("Today is %d/%d/%d.\n", current_time->tm_mon + 1, current_time->tm_mday, current_time->tm_year + 1900);
    printf("The time is %02d:%02d:%02d.\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

    //set new date and time
    current_time->tm_year += 1;
    current_time->tm_mon += 1;
    current_time->tm_mday += 1;
    current_time->tm_hour += 2;
    current_time->tm_min += 5;

    //convert new date and time back to Unix time
    time_t new_time = mktime(current_time);

    //print new Unix time value
    printf("New Unix time value: %ld\n", new_time);

    //convert new Unix time back to local time
    struct tm *new_local_time = localtime(&new_time);

    //print formatted new date and time
    printf("New date and time: %d/%d/%d %02d:%02d:%02d.\n", new_local_time->tm_mon + 1, new_local_time->tm_mday, new_local_time->tm_year + 1900, new_local_time->tm_hour, new_local_time->tm_min, new_local_time->tm_sec);

    return 0;
}