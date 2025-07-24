//FormAI DATASET v1.0 Category: System event logger ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>

//define a struct to represent the event 
typedef struct EventLog {
    time_t timestamp;
    char message[256];
} EventLog;

//define a function to log an event
void logEvent(char* msg) {
    //create a new event 
    EventLog event;
    event.timestamp = time(NULL);
    sprintf(event.message, "%s", msg);
    
    //open the log file for appending 
    FILE *fptr;
    fptr = fopen("eventLog.txt", "a");
    
    //write the event to the log file 
    fprintf(fptr, "%ld: %s\n", event.timestamp, event.message);
    
    //close the log file 
    fclose(fptr);
}

//driver program to test the event logger 
int main() {
    //log some events 
    logEvent("First event occurred");
    logEvent("Second event occurred");
    logEvent("Third event occurred");
    
    //print the event log 
    FILE *fptr;
    fptr = fopen("eventLog.txt", "r");
    char ch;
    printf("Event log:\n");
    while((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }
    fclose(fptr);
    
    return 0;
}