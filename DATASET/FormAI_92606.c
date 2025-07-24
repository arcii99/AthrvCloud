//FormAI DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX_EVENT_LENGTH 50
 
typedef struct {
    time_t timestamp;
    char event[MAX_EVENT_LENGTH];
} Event;
 
void logEvent(char* line) {
    Event event;
    event.timestamp = time(NULL);
    
    int i;
    for(i = 0; line[i] != '\0'; i++) {
        if(i >= MAX_EVENT_LENGTH - 1) {
            break;
        }
        event.event[i] = line[i];
    }
    event.event[i] = '\0';
    
    FILE* logFile = fopen("systemEvents.log", "a");
    if(logFile == NULL) {
        printf("Unable to open log file.\n");
        return;
    }
    
    fprintf(logFile, "%ld: %s\n", event.timestamp, event.event);
    fclose(logFile);
}
 
int main() {
    printf("Welcome to the system event logger!\n");
    char line[MAX_EVENT_LENGTH];
    int count = 0;
    while(1) {
        printf("Enter the event message (max %d characters): ", MAX_EVENT_LENGTH - 1);
        fgets(line, MAX_EVENT_LENGTH, stdin);
        char* pos = strchr(line, '\n');
        if(pos != NULL) {
            *pos = '\0';   
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
        
        if(strcmp(line, "quit") == 0) {
            printf("Logger terminated. %d events logged.\n", count);
            return 0;
        }
        
        logEvent(line);
        count++;
    }
}