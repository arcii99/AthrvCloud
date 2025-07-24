//FormAI DATASET v1.0 Category: Date and time ; Style: bold
// This program prints the current date and time using C programming language.

#include <stdio.h>
#include <time.h>

int main() {
    // Get current time and date
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    // Get components of current time and date
    int year = timeinfo->tm_year + 1900;
    int month = timeinfo->tm_mon + 1;
    int day = timeinfo->tm_mday;
    int hour = timeinfo->tm_hour;
    int minute = timeinfo->tm_min;
    int second = timeinfo->tm_sec;
    
    // Print the current date and time in a bold style
    printf("\033[1mCurrent date and time:\033[0m\n");
    printf("\033[1m%02d/%02d/%d %02d:%02d:%02d\033[0m\n", month, day, year, hour, minute, second);
    
    return 0;
}