//FormAI DATASET v1.0 Category: Log analysis ; Style: Ada Lovelace
/*
** Ada Lovelace inspired C Log analysis example program
** Author: Your Name
*/

#include <stdio.h>

int main() {
    // Open the log file for reading
    FILE *logFile = fopen("app.log", "r");
    
    // Check if file was opened successfully
    if(logFile == NULL) {
        printf("Failed to open log file\n");
        return 1;
    }
    
    // Initialize variables
    int errorCount = 0;
    int warningCount = 0;
    int infoCount = 0;
    char buffer[1024];
    
    // Read through each line of the log file
    while(fgets(buffer, 1024, logFile)) {
        // Check for error messages
        if(strstr(buffer, "ERROR")) {
            errorCount++;
            printf("Error message found: %s", buffer);
        }
        
        // Check for warning messages
        else if(strstr(buffer, "WARNING")) {
            warningCount++;
            printf("Warning message found: %s", buffer);
        }
        
        // Check for info messages
        else if(strstr(buffer, "INFO")) {
            infoCount++;
            printf("Info message found: %s", buffer);
        }
    }
    
    // Print summary of log analysis
    printf("\n\nLog analysis summary:\n");
    printf("---------------------\n");
    printf("Total number of error messages: %d\n", errorCount);
    printf("Total number of warning messages: %d\n", warningCount);
    printf("Total number of info messages: %d\n", infoCount);
    
    // Close the log file
    fclose(logFile);
    
    return 0;
}