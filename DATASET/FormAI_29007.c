//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void logEvent(char* eventType, char* message) {
    /* Get the current time */
    time_t currentTime;
    time(&currentTime);

    /* Convert the current time to string format */
    char* timeString = ctime(&currentTime);
    /* Remove the newline character at the end of the string */
    timeString[strlen(timeString) - 1] = '\0';

    /* Print the log message */
    printf("%s - %s: %s\n", timeString, eventType, message);
}

int main(int argc, char* argv[]) {
    char* eventType = "System Event";
    char* message = "Program started";

    /* Log the initial event */
    logEvent(eventType, message);

    /* Perform some system tasks to generate events */
    /* E.g. opening files, creating new processes, etc. */

    /* Log the events */
    logEvent(eventType, "Opened file example.txt");
    logEvent(eventType, "Created new process with PID 1234");

    /* Perform some more system tasks */
    /* E.g. closing files, terminating processes, etc. */

    /* Log the events */
    logEvent(eventType, "Closed file example.txt");
    logEvent(eventType, "Terminated process with PID 1234");

    return 0;
}