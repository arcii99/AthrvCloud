//FormAI DATASET v1.0 Category: System event logger ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    char input[50];
    FILE *filePointer;

    // Prompt the user for input
    printf("Please enter the name of the file you'd like to log system events to: ");
    fgets(input, 50, stdin);

    // Open file for writing
    filePointer = fopen(input, "w");

    // Verify that file was opened successfully
    if(filePointer == NULL) {
        printf("Error opening file. Please try again.\n");
        return 0;
    }

    // Start logging system events
    printf("System event logging has started...\n");
    fprintf(filePointer, "System event logging has started.\n");

    // Create an array of events to log
    char events[5][50] = {"System boot", "Network connection established", "File accessed", "User logged in", "Shutdown initiated"};

    // Loop through array and log each event
    for(int i = 0; i < 5; i++) {
        printf("%s\n", events[i]);
        fprintf(filePointer, "%s\n", events[i]);
    }

    // End logging and close file
    printf("System event logging has ended.\n");
    fprintf(filePointer, "System event logging has ended.\n");
    fclose(filePointer);

    return 0;
}