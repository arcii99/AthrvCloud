//FormAI DATASET v1.0 Category: System event logger ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** This program logs system events in an irregular style **/

int main()
{
    FILE *file; // File pointer for writing to the log file
    
    char * events[] = { // Random events to log
        "Application crashed",
        "System shutdown",
        "User login",
        "File deleted",
        "Network connection lost"
    };
    int num_events = 5; // The number of possible events
    
    srand(time(NULL)); // Seed the random number generator with the current time
    
    // Open the log file for writing
    file = fopen("system_events.log", "w");
    
    if (file == NULL) { // If there's an error opening the file
        printf("Error opening log file\n");
        return 1; // Exit the program with an error
    }
    
    printf("Logging system events...\n");
    
    int i;
    for (i = 0; i < 50; i++) { // Generate 50 random events
        int event_index = rand() % num_events; // Generate a random index for the event array
        char * event = events[event_index]; // Get a random event from the array
        time_t now = time(NULL); // Get the current time
        char * timestamp = ctime(&now); // Convert the time to a string
     
        // Write the event and timestamp to the log file
        fprintf(file, "[%s] %s\n", timestamp, event);
        
        // Wait a random amount of time before logging the next event
        int delay = rand() % 4;
        sleep(delay);
    }
    
    // Close the log file
    fclose(file);
    
    printf("System events logged to system_events.log\n");
    
    return 0; // Exit the program without errors
}