//FormAI DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of occurrences of a string in a file
int countOccurrences(FILE* file, char* search){
    char line[100];
    int count = 0;

    // Loop through each line in the file
    while(fgets(line, 100, file) != NULL){
        // Check if the search string is in the line
        if(strstr(line, search) != NULL){
            // Increment the count if the search string is found
            count++;
        }
    }

    return count;
}

int main(){

    // Open the log file for reading
    FILE *logFile;
    logFile = fopen("log.txt", "r");
    if(logFile == NULL){
        printf("Error opening log file.\n");
        return 1;
    }

    // Get the number of occurrences of various events in the log
    int loginCount = countOccurrences(logFile, "User logged in");
    int errorCount = countOccurrences(logFile, "Error");

    // Print the results to the console
    printf("Number of logins: %d\n", loginCount);
    printf("Number of errors: %d\n", errorCount);

    // Close the log file
    fclose(logFile);

    return 0;
}