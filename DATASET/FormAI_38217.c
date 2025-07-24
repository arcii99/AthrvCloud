//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: future-proof
#include <stdio.h>
#include <time.h>

#define YEAR 2021
#define MONTH 7
#define DAY 30

void printDate(struct tm *date);

int main() {
    time_t t = time(NULL);
    struct tm *currDate = localtime(&t);

    printf("Today's date is: ");
    printDate(currDate);

    // Set the time machine date to 100 years ago from now
    struct tm timeMachineDate = *currDate;
    timeMachineDate.tm_year -= 100;

    printf("Using the time machine to travel back to: ");
    printDate(&timeMachineDate);

    // Wait for 2 seconds, as if a time machine has to warm up
    printf("Warming up the time machine...\n");
    sleep(2);

    // Travel back in time via the time machine
    t = mktime(&timeMachineDate);
    currDate = localtime(&t);

    printf("Arrived at the destination date: ");
    printDate(currDate);
    
    return 0;
}

void printDate(struct tm *date) {
    printf("%d.%d.%d\n", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
}