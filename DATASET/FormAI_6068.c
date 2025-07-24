//FormAI DATASET v1.0 Category: System event logger ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int eventNum = 1; // Initialize the event number counter
    time_t now; // Declare a time variable
    char message[100]; // Declare a character array to hold event messages
    
    // Print a cheerful welcome message
    printf("Welcome to the System Event Logger! Let's keep track of all the fun things that happen today!\n");

    // Start a loop that continues until the user chooses to stop logging events
    while (1) {
        // Get the current time
        time(&now);
        
        // Prompt the user to enter an event message
        printf("Event %d: Enter a short description of what just happened, or 'quit' to stop logging events.\n", eventNum);
        fgets(message, 100, stdin);

        // If the user enters 'quit', break out of the loop
        if (!strcmp(message, "quit\n")) {
            break;
        }

        // Print the event message to the console along with the current time
        printf("\nEvent %d logged at %s", eventNum, ctime(&now));
        printf("Message: %s\n\n", message);

        eventNum++; // Increment the event number counter
    }

    // Print a cheerful goodbye message
    printf("Thanks for using the System Event Logger! Have a wonderful day!\n");

    return 0;
}