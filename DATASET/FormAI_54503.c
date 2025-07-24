//FormAI DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <time.h>

// Define custom event types
#define EVENT_INFO 0
#define EVENT_WARNING 1
#define EVENT_ERROR 2

// Define custom event message prefixes
#define PREFIX_INFO "INFO"
#define PREFIX_WARNING "WARNING"
#define PREFIX_ERROR "ERROR"

// Define custom event message formats
#define FORMAT_INFO "[%s] [%s]: %s\n"
#define FORMAT_WARNING "[%s] [%s]: WARNING! %s\n"
#define FORMAT_ERROR "[%s] [%s]: ERROR! %s\n"

// Define function to get current time
char *getCurrentTime() {
    time_t now;
    time(&now);
    return ctime(&now);
}

// Define function to log events
void logEvent(int eventType, char *eventMessage) {
    // Determine prefix and format based on event type
    char *prefix, *format;
    switch (eventType) {
        case EVENT_INFO:
            prefix = PREFIX_INFO;
            format = FORMAT_INFO;
            break;
        case EVENT_WARNING:
            prefix = PREFIX_WARNING;
            format = FORMAT_WARNING;
            break;
        case EVENT_ERROR:
            prefix = PREFIX_ERROR;
            format = FORMAT_ERROR;
            break;
        default:
            return;
    }
    
    // Print formatted event message with prefix and current time
    printf(format, getCurrentTime(), prefix, eventMessage);
}

int main() {
    // Test logging events of each type
    logEvent(EVENT_INFO, "System initialized successfully");
    logEvent(EVENT_WARNING, "Disk space running low");
    logEvent(EVENT_ERROR, "Unable to connect to database");
    
    return 0;
}