//FormAI DATASET v1.0 Category: System event logger ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to log the system events */
void logSystemEvent(char* eventType, char* eventDetails) {
    /* Opening the log file in append mode */
    FILE *fp = fopen("system-event-log.txt", "a");
 
    /* Getting the current time and date */
    time_t now;
    struct tm *current_time;
    now = time(NULL);
    current_time = localtime(&now);

    /* Writing the event to the log file */
    fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] %s: %s\n",
        current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday,
        current_time->tm_hour, current_time->tm_min, current_time->tm_sec,
        eventType, eventDetails);

    /* Closing the log file */
    fclose(fp);
}

int main() {
    /* Sample usage of the logSystemEvent function */
    char eventType[50] = "ERROR";
    char eventDetails[100] = "Division by zero error in line 50";
    logSystemEvent(eventType, eventDetails);
 
    return 0;
}