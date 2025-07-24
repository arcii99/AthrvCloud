//FormAI DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>

int main() {
    // Welcome message to the user
    printf("Welcome to the C Log Analysis Program! \n");
    
    // Open log file
    FILE *fp;
    fp = fopen("logfile.txt","r");
    
    // Check if log file exists or not
    if(fp == NULL) {
        printf("Error: Log file does not exist. Please create one before running this program.");
        return 0;
    }
    
    // Declare variables for log analysis
    char line[100];
    int count = 0;
    int error_count = 0;
    int warning_count = 0;
    
    // Read log file line by line
    while(fgets(line, sizeof(line), fp)) {
        // Increment count
        count++;
        
        // Check if there is an error in the log line
        if(strstr(line, "ERROR") != NULL) {
            error_count++;
            printf("Error found in log line number %d: %s", count, line);
        }
        
        // Check if there is a warning in the log line
        if(strstr(line, "WARNING") != NULL) {
            warning_count++;
            printf("Warning found in log line number %d: %s", count, line);
        }
    }
    
    // Close log file
    fclose(fp);
    
    // Print analysis report to the user
    printf("Log Analysis Report: \n");
    printf("Total Number of Lines: %d \n", count);
    printf("Total Number of Errors: %d \n", error_count);
    printf("Total Number of Warnings: %d \n", warning_count);
    
    // End of Program
    printf("Thank you for using the C Log Analysis Program! \n");
    return 0;
}