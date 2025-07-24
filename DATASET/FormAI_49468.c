//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to time travel
int timeTravel(int years){
    struct tm * currentTime;
    time_t rightNow, newTime;

    // Get current time
    time(&rightNow);
    currentTime = localtime(&rightNow);

    // Set new time
    currentTime->tm_year += years;
    newTime = mktime(currentTime);

    return newTime;
}

int main(){
    int years;
    time_t travelTime;

    // Welcome message
    printf("Welcome to Time Travel Simulator!\n\n");

    // Prompt user for years to travel
    printf("How many years do you want to travel to? ");
    scanf("%d", &years);

    // Validate input
    if(years < 0){
        printf("Invalid input. Years must be a positive integer.\n");
        return -1;
    }

    // Travel through time
    travelTime = timeTravel(years);

    // Print out travel information
    printf("\nYou have arrived %d years in the future!\n", years);
    printf("The new year is: %d\n", localtime(&travelTime)->tm_year + 1900);

    return 0;
}