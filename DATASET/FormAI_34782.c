//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t currentTime;
    struct tm *localTime;
    char choice;
    int yearsToAdd;
    
    // Get the current time
    currentTime = time(NULL);
    
    // Convert the current time to local time
    localTime = localtime(&currentTime);
    
    // Display the current time
    printf("The current date is %d-%d-%d\n", localTime->tm_mday, localTime->tm_mon+1, localTime->tm_year+1900);
    
    // Ask the user if they want to time travel
    printf("Would you like to time travel? (y/n)\n");
    scanf("%c", &choice);
    
    // If the user chooses yes, ask them how many years they want to travel
    if (choice == 'y') {
        printf("How many years would you like to travel? ");
        scanf("%d", &yearsToAdd);
        
        // Add the number of years to the current year
        localTime->tm_year += yearsToAdd;
        
        // Normalize the time
        mktime(localTime);
        
        // Display the new date
        printf("The new date is %d-%d-%d\n", localTime->tm_mday, localTime->tm_mon+1, localTime->tm_year+1900);
    } else {
        printf("No time travel today.\n");
    }
    
    return 0;
}