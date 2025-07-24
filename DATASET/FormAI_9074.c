//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Asynchronous function to print the current date and time
void* printDateAndTime(void *arg) {
    time_t t;
    struct tm *localTime;
    
    while(1) {
        time(&t);
        localTime = localtime(&t);
        printf("Current Date and Time: %s", asctime(localTime));
        sleep(1);
    }
}

int main() {
    pthread_t thread;
    int rc;
    
    printf("Welcome to Time Travel Simulator!\n");
    
    // Create asynchronous thread to print date and time
    rc = pthread_create(&thread, NULL, printDateAndTime, NULL);
    if (rc) {
        printf("Error: Unable to create thread.\n");
        exit(-1);
    }
    
    // Get user input for year to travel to
    printf("Enter a year to travel to (in the future): ");
    int year;
    scanf("%d", &year);
    
    // Check if input year is valid (i.e. in the future)
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    
    if (year < currentYear) {
        printf("Error: Invalid input year. Please enter a year in the future.\n");
        exit(-1);
    }
    
    // Calculate time difference between current year and input year
    int timeDiff = year - currentYear;
    
    // Simulate time travel by fast forwarding the date and time
    for (int i = 0; i < timeDiff; i++) {
        sleep(365 * 24 * 60 * 60); // Sleep for 1 year
    }
    
    // Print final date and time after time travel
    time_t finalTime;
    time(&finalTime);
    struct tm *finalLocalTime = localtime(&finalTime);
    printf("After time travel, the date and time is: %s", asctime(finalLocalTime));
    
    // Exit program
    pthread_join(thread, NULL);
    printf("Thank you for using Time Travel Simulator!\n");
    return 0;
}