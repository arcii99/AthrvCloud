//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h> // Standard input-output library
#include <time.h> // Library for date and time functions

int main() { // Main function
    
    FILE *logFile; // Declare FILE pointer
    
    char eventName[50]; // Declare variable to store the event name
    char eventDesc[100]; // Declare variable to store the event description
    
    time_t currentTime; // Declare time_t variable to store current time
    
    // Open log file in append mode
    logFile = fopen("eventLog.txt", "a");
    
    // Check if file is opened successfully
    if (logFile == NULL) {
        printf("Error: Log file could not be opened\n");
        return 1; // Exit program with error code 1
    }
    
    // Get current time and date
    time(&currentTime);
    
    // Display message to user to enter event name
    printf("Enter the name of the event: ");
    fgets(eventName, sizeof(eventName), stdin); // Get event name from user
    
    // Display message to user to enter event description
    printf("Enter a brief description of the event: ");
    fgets(eventDesc, sizeof(eventDesc), stdin); // Get event description from user
    
    // Write event details to the log file
    fprintf(logFile, "Event Name: %sEvent Description: %sEvent Time: %s", eventName, eventDesc, ctime(&currentTime));
    
    printf("Event has been logged to file successfully\n");
    
    // Close the log file
    fclose(logFile); 
    
    return 0; // Exit program with success code 0
}