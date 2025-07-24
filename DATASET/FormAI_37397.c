//FormAI DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // open the log file
    FILE *logfile = fopen("example.log", "r");
    
    // check if log file was opened successfully
    if (logfile == NULL) {
        printf("Error opening log file\n");
        return 1;
    }
    
    // initialize variables to store log data
    char line[200];
    char date[12];
    char time[12];
    char message[150];
    int count = 0;
    
    // read each line of the log file and parse data
    while (fgets(line, sizeof(line), logfile)) {
    
        // split the line into date, time, and message
        sscanf(line, "%s %s %[^\n]", date, time, message);
        
        // check if message contains the word "error"
        if (strstr(message, "error") != NULL) {
            // if error, print date, time, and message to console
            printf("%s %s %s\n", date, time, message);
            
            // increment error count
            count++;
        }
    }
    
    // close the log file
    fclose(logfile);
    
    // print total number of errors found
    printf("Total number of errors: %d\n", count);
    
    return 0;
}