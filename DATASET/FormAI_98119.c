//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define LOG_PATH "system_log.txt"

typedef enum Event {
    LOGIN,
    LOGOUT,
    SHUTDOWN,
    RESTART
} Event;

typedef struct LogRecord {
    time_t timestamp;
    Event event;
    char* user;
} LogRecord;

void log_event(Event event, char* user) {
    time_t now = time(NULL);
    LogRecord record = {now, event, user};
    
    FILE* log_file = fopen(LOG_PATH, "a");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return;
    }
    
    fprintf(log_file, "%ld|%d|%s\n", record.timestamp, record.event, record.user);
    fclose(log_file);
}

int main(void) {
    // Sample code to test the logger
    printf("Logging events...\n");
    log_event(LOGIN, "user1");
    log_event(LOGOUT, "user1");
    log_event(SHUTDOWN, NULL);
    log_event(RESTART, NULL);
    printf("Done logging.\n");
    
    return 0;
}