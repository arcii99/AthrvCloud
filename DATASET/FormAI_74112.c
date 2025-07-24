//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: dynamic
#include<stdio.h>
#include<time.h>

int main(){
    long int current_time, year, month, day, hour, min, sec;
    struct tm * ptr_time;

    // Get the current time 
    time(&current_time);

    // Convert the current time to local time 
    ptr_time = localtime(&current_time);

    // Get values of individual time components 
    year = ptr_time -> tm_year + 1900;
    month = ptr_time -> tm_mon + 1;
    day = ptr_time -> tm_mday;
    hour = ptr_time -> tm_hour;
    min = ptr_time -> tm_min;
    sec = ptr_time -> tm_sec;

    printf("Current Date and Time: %d-%d-%d %d:%d:%d\n", year, month, day, hour, min, sec);

    // Set the time to the year 1800 
    ptr_time -> tm_year = 100;
    ptr_time -> tm_mon = 0;
    ptr_time -> tm_mday = 1;
    ptr_time -> tm_hour = 0;
    ptr_time -> tm_min = 0;
    ptr_time -> tm_sec = 0;

    // Convert the modified time to a new time stamp 
    current_time = mktime(ptr_time);

    // Convert the new time stamp to local time 
    ptr_time = localtime(&current_time);

    // Get values of individual time components 
    year = ptr_time -> tm_year + 1900;
    month = ptr_time -> tm_mon + 1;
    day = ptr_time -> tm_mday;
    hour = ptr_time -> tm_hour;
    min = ptr_time -> tm_min;
    sec = ptr_time -> tm_sec;

    printf("Date and Time after Time Travel: %d-%d-%d %d:%d:%d\n", year, month, day, hour, min, sec);

    return 0;
}