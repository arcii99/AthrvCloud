//FormAI DATASET v1.0 Category: System event logger ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Initialize random seed
    srand(time(NULL));
    
    // Create array of possible event types
    char *event_types[] = {"singing unicorns", "flying fish", "dancing elephants", "surreal landscapes", "talking mushrooms"};
    
    // Create array of possible event severities
    char *severities[] = {"mild", "moderate", "severe", "apocalyptic"};
    
    // Open file to write log events
    FILE *log_file;
    log_file = fopen("surrealist_logs.txt", "w");
    
    // Check if file opened successfully
    if(log_file == NULL){
        printf("Error opening file!");
        exit(1);
    }
    
    // Generate random event entries and write to log file
    for(int i=0; i<50; i++){
        int event_type_index = rand() % 5;
        int severity_index = rand() % 4;
        
        char *event_type = event_types[event_type_index];
        char *severity = severities[severity_index];
        
        fprintf(log_file, "%s event detected - Severity: %s\n", event_type, severity);
    }
    
    // Close file
    fclose(log_file);
    
    return 0;
}