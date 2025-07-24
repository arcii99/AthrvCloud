//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // current time
    time_t current_time;
    char* c_time_string;
 
    // Obtain current time as seconds since the Epoch.
    current_time = time(NULL);
 
    // Convert to local time format.
    c_time_string = ctime(&current_time);
 
    // Print results.
    printf("C System Event Logger\n");
    printf("---------------------\n\n");
    printf("Current time is %s\n", c_time_string);
 
    // initialize log file name
    char* file_name = "system_log.txt";
 
    // open log file in append mode
    FILE* log_file = fopen(file_name, "a");
 
    // check if file was opened successfully
    if(log_file == NULL){
        perror("Error opening file");
        exit(1);
    }
 
    // log event to file
    char* event_message = "System has started.\n";
    fprintf(log_file, "%s %s", c_time_string, event_message);
 
    // close log file
    fclose(log_file);
 
    // exit program
    return 0;
}