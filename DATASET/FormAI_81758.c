//FormAI DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h> // Import standard input-output library
#include <stdlib.h> // Import standard library
#include <string.h> // Import string handling library

int main()
{
    char log_entry[256]; // Declare a char array to store each log entry
    int num_entries = 0; // Initialize the number of log entries to 0

    FILE *log_file = fopen("log.txt", "r"); // Open the log file in read-only mode

    if(log_file == NULL) // Check if file is opened successfully
    {
        printf("Error opening file!"); // If not, print error message
        exit(1); // Exit program with error code
    }

    while(fgets(log_entry, sizeof(log_entry), log_file) != NULL) // Read each line until the end of file is reached
    {
        num_entries++; // Increment the number of log entries

        char *token = strtok(log_entry, " "); // Extract the first word of the log entry
        printf("Entry %d: %s\n", num_entries, token); // Print the entry number and the first word

        while(token != NULL) // Loop through the remaining words
        {
            token = strtok(NULL, " "); // Extract the next word
            if(token != NULL) // Check if it's not NULL
            {
                printf("%s ", token); // Print the word
            }
        }
        printf("\n\n"); // Add extra line spacing after each entry
    }

    fclose(log_file); // Close the log file

    return 0; // Exit program with success code
}