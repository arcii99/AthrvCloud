//FormAI DATASET v1.0 Category: Log analysis ; Style: ephemeral
#include <stdio.h>

int main(){
    printf("Welcome to our C Log analysis program!\n");

    // Open the log file and check for errors
    FILE* log = fopen("logfile.txt", "r");
    if(log == NULL){
        printf("Error: Cannot open log file.\n");
        return 0;
    }

    // Declare variables to store data from the log file
    char date[20];
    char time[20];
    char level[10];
    char message[100];

    // Loop through each line in the log file
    while(fscanf(log, "%s %s %s %s", date, time, level, message) == 4){
        // Check if the log level is ERROR or WARNING
        if(strcmp(level, "ERROR") == 0 || strcmp(level, "WARNING") == 0){
            // Print the relevant information for each log entry
            printf("Date: %s Time: %s\nLevel: %s\nMessage: %s\n\n", date, time, level, message);
        }
    }

    // Close the log file
    fclose(log);

    printf("Log analysis complete. Thank you for using our program!\n");
    return 0;
}