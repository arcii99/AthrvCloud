//FormAI DATASET v1.0 Category: System event logger ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "event.log"

typedef enum {
    INFO,
    WARNING,
    ERROR
} EventLevel;

const char* format = "%Y-%m-%d %H:%M:%S";

// Function to get the current timestamp
char* get_timestamp() {
    time_t rawtime;
    struct tm* timeinfo;
    char* buffer = (char*) malloc(sizeof(char) * 20);

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 20, format, timeinfo);

    return buffer;
}

// Function to log an event into the file
void log_event(EventLevel level, char* message) {
    FILE* file = fopen(LOG_FILE, "a");

    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    char* timestamp = get_timestamp();

    fprintf(file, "[%s] ", timestamp);

    switch (level) {
        case INFO:
            fprintf(file, "[INFO] %s\n", message);
            break;
        case WARNING:
            fprintf(file, "[WARNING] %s\n", message);
            break;
        case ERROR:
            fprintf(file, "[ERROR] %s\n", message);
            break;
    }

    free(timestamp);
    fclose(file);
}

int main() {
    log_event(INFO, "Program started!");

    // Do some logic

    log_event(WARNING, "Something unexpected happened!");

    // More logic

    log_event(ERROR, "Program encountered an error and crashed!");

    return 0;
}