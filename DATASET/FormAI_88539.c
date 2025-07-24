//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include<stdio.h>
#include<time.h>

int main(){
    // Defining variables for time travel simulation
    time_t current_time; 
    struct tm *structure_time;

    // Getting current time
    current_time = time(NULL);

    // Casting current time to structure time
    structure_time = localtime(&current_time);
 
    int option; // Defining option variable to select year 

    printf("Welcome to the Time Travel Simulator\n");

    printf("Select year to time travel:");
    scanf("%d",&option);

    // Handling negative time travel 
    if (option < structure_time->tm_year + 1900){
        printf("Invalid year! Time travel is not possible!\n");
    }
    else {
        // Calculating time difference
        int difference = (option - 1900) - structure_time->tm_year;

        // Updating structure time years to user input
        structure_time->tm_year += difference;

        // Creating new time based on modified structure time
        time_t new_time = mktime(structure_time);

        // Updating current time
        current_time = new_time;

        printf("You travelled to the year %d!\n", option);

        // Printing current date and time after time travel
        printf("Current date and time: %s", ctime(&current_time));
    }

    return 0;
}