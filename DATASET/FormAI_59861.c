//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <time.h>

int main() {
    printf("Starting system event logger..\n\n");
    
    // getting the current time
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    int day   = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year  = localTime->tm_year + 1900;
    
    // creating log filename
    char filename[30];
    snprintf(filename, 30, "system_event_logs_%d-%d-%d.txt", year, month, day);
    
    // creating and opening log file
    FILE *logFile;
    logFile = fopen(filename, "w");
    if(logFile == NULL){
        printf("Error creating log file.\n");
        return -1;
    }
    
    printf("System event logger started.\n\n");
    
    // start logging system events
    int eventNumber = 1;
    char eventDetails[100];
    while(eventNumber <= 10){
        printf("Enter event details for event %d: ", eventNumber);
        fgets(eventDetails, 100, stdin);
        
        // adding event details and timestamp to log file
        fprintf(logFile, "Event %d: %s", eventNumber, eventDetails);
        fprintf(logFile, "   Timestamp: %d:%d:%d %d/%d/%d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec, day, month, year);
        
        printf("Successfully logged event %d.\n\n", eventNumber);
        eventNumber++;
    }
    
    fclose(logFile);
    printf("System event logger completed. Log file saved as %s.\n", filename);
    
    return 0;
}