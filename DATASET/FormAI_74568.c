//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to simulate time travel
void timeTravel(int year) {
    time_t currentTime;
    struct tm * timeInfo;
    char dateStr[9];
    
    // get current time
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    
    // set time to specified year
    timeInfo->tm_year = year - 1900;
    
    // convert time to string and print
    strftime(dateStr, 9, "%Y%m%d", timeInfo);
    printf("Welcome to the year %d. Today's date is %s.\n", year, dateStr);
}

int main() {
    int year;
    
    // prompt user for year
    printf("Enter a year to travel to: ");
    scanf("%d", &year);
    
    // validate input year
    if (year < 1900 || year > 2099) {
        printf("Invalid year.\n");
    } else {
        timeTravel(year);
    }
    
    return 0;
}