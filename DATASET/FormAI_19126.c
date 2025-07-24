//FormAI DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function that gets a string representation of the current date and time
char* getDateTimeString() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* dateTimeString = (char*) malloc(sizeof(char) * 20);
    sprintf(dateTimeString, "%04d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    return dateTimeString;
}

// function that logs an event to a file
void logEvent(char* fileName, char* eventMessage) {
    FILE* file = fopen(fileName, "a"); // open the file in append mode

    if (file != NULL) { // check if the file is successfully opened
        char* dateTimeString = getDateTimeString(); // get current date and time string
        fprintf(file, "[%s]: %s\n", dateTimeString, eventMessage); // write the event to the file
        free(dateTimeString); // free the memory allocated to the date and time string
        fclose(file); // close the file
    }
}

int main() {
    logEvent("event_log.txt", "Application started"); // log application start event
    logEvent("event_log.txt", "System initialized"); // log system initialize event

    // simulate some events
    for (int i = 0; i < 5; i++) {
        char eventMessage[50];
        sprintf(eventMessage, "Event %d occurred", i + 1);
        logEvent("event_log.txt", eventMessage);
    }

    logEvent("event_log.txt", "Application stopped"); // log application stop event

    return 0;
}