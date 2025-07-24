//FormAI DATASET v1.0 Category: System event logger ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define the maximum length of message and event names */
#define MAX_MSG_LEN 128
#define MAX_EVENT_LEN 64

/* Define the structure of a log message */
typedef struct {
    time_t timestamp;
    char event_name[MAX_EVENT_LEN];
    char message[MAX_MSG_LEN];
} log_message_t;

/* Define the function to log a message */
void log_message(const char* event_name, const char* message) {
    /* Create a log message object and populate it */
    log_message_t log_message;
    time(&log_message.timestamp);
    strncpy(log_message.event_name, event_name, MAX_EVENT_LEN);
    strncpy(log_message.message, message, MAX_MSG_LEN);

    /* Open the log file for appending */
    FILE* log_file = fopen("event_log.txt", "a");

    /* Write the log message to the file */
    fprintf(log_file, "[%s] %s - %s\n", asctime(localtime(&log_message.timestamp)), log_message.event_name, log_message.message);

    /* Close the log file */
    fclose(log_file);
}

/* Define some events to log */
const char* EVENT_STARTUP = "Startup";
const char* EVENT_SHUTDOWN = "Shutdown";
const char* EVENT_ERROR = "Error";

/* Define the main function */
int main() {
    /* Log the startup event */
    log_message(EVENT_STARTUP, "Application started");

    /* Perform some application logic */
    int result = 1;
    if (result != 0) {
        /* Log an error event */
        log_message(EVENT_ERROR, "Application encountered an error");
    }

    /* Log the shutdown event */
    log_message(EVENT_SHUTDOWN, "Application exited");

    /* Exit the program */
    return 0;
}