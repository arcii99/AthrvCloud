//FormAI DATASET v1.0 Category: Date and time ; Style: synchronous
#include <stdio.h>
#include <time.h>
int main(){
    
    // get current time
    time_t current_time;
    struct tm * time_info;
    char time_str[9];
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%H:%M:%S", time_info);
    
    // get current date
    int day, month, year;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    day = local->tm_mday;         // get day of the month (1 to 31)
    month = local->tm_mon + 1;    // get month of the year (0 to 11)
    year = local->tm_year + 1900; // get year since 1900
    
    // display date and time
    printf("Current Date: %02d/%02d/%d\n", day, month, year);
    printf("Current Time: %s\n", time_str);
    
    return 0;
}