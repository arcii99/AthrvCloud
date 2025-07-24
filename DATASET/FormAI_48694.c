//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Initialize Time Variables
    time_t currentTime, futureTime;
    
    //Get Current Time
    currentTime = time(NULL);
    
    //Set Future Time
    struct tm futureDate;
    futureDate.tm_sec = 0;
    futureDate.tm_min = 0;
    futureDate.tm_hour = 0;
    futureDate.tm_mday = 25; //Christmas Day
    futureDate.tm_mon = 11; //December
    futureDate.tm_year = 2100 - 1900; //Year 2100
    futureTime = mktime(&futureDate);
    
    //Calculate Time Difference
    double timeDifference = difftime(futureTime, currentTime);
    
    //Convert Seconds to Years
    double years = timeDifference / (365.25 * 24 * 60 * 60);
    
    //Print Results
    printf("Welcome to the Time Travel Simulator\n");
    printf("This program will transport you to the year 2100\n");
    printf("Starting from your current time, it will take %.2f years to reach 2100\n", years);
    
    //Time Travel Loop
    int travelYear = 1900;
    while (travelYear < 2100) {
        printf("You have arrived in the year %d\n", travelYear);
        travelYear++;
        sleep(1); //Delay 1 second
    }
    
    printf("Congratulations, you have arrived in 2100!\n");
    
    return 0;
}