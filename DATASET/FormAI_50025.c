//FormAI DATASET v1.0 Category: System event logger ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char event[], char level[]) {
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    c_time_string[strlen(c_time_string)-1] = '\0'; // remove newline at end
    
    FILE *logfile;
    logfile = fopen("eventlog.log", "a");
    if (!logfile) {
        printf("Error: could not open log file!\n");
        return; // don't try to log if file couldn't be opened
    }
    
    fprintf(logfile, "%s | %s | %s\n", c_time_string, level, event);
    fclose(logfile);
}

int main() {
    printf("Enter an event to log: ");
    char event[100];
    fgets(event, sizeof(event), stdin);
    event[strlen(event)-1] = '\0'; // remove newline at end
    
    printf("Enter a log level (INFO, WARN, or ERROR): ");
    char level[10];
    fgets(level, sizeof(level), stdin);
    level[strlen(level)-1] = '\0'; // remove newline at end
    
    logEvent(event, level);
    printf("Event logged successfully!\n");
    
    return 0;
}