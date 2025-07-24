//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <time.h>

void logEvent(char *eventType, char *description){

    //get current time
    time_t currentTime;
    time(&currentTime);
    char *timeString = ctime(&currentTime);

    //open log file in append mode
    FILE *logFile = fopen("event_log.txt", "a");

    //write event details to log file
    fprintf(logFile, "%s: %s - %s", timeString, eventType, description);

    //close log file
    fclose(logFile);

    //print success message to console
    printf("%s event logged successfully.\n", eventType);
}

int main(){

    //log some example events
    logEvent("ERROR", "Unable to open file.");
    logEvent("WARNING", "Low disk space.");
    logEvent("INFO", "User 'John' logged in.");
    
    return 0;
}