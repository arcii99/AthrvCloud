//FormAI DATASET v1.0 Category: Log analysis ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: ./loganalysis logfile.log\n");
        return 1;
    }
    
    // Open the log file
    FILE *logfile = fopen(argv[1], "r");
    if (logfile == NULL) {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 2;
    }
    
    // Define variables for analysis
    int total_requests = 0;
    int successful_requests = 0;
    int redirect_requests = 0;
    int error_requests = 0;
    char line[100];
    
    // Analyze each line of the log file
    while (fgets(line, sizeof(line), logfile)) {
        total_requests++;
        
        // Check for successful requests
        if (strstr(line, "200 OK")) {
            successful_requests++;
        }
        
        // Check for redirect requests
        else if (strstr(line, "302 Found")) {
            redirect_requests++;
        }
        
        // Check for error requests
        else if (strstr(line, "404 Not Found")) {
            error_requests++;
        }
    }
    
    // Print results of analysis
    printf("Total requests: %d\n", total_requests);
    printf("Successful requests: %d\n", successful_requests);
    printf("Redirect requests: %d\n", redirect_requests);
    printf("Error requests: %d\n", error_requests);
    
    // Close the log file and exit the program
    fclose(logfile);
    return 0;
}