//FormAI DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <time.h>

void logEvent(const char* eventType, const char* eventDesc) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char date[50];
    sprintf(date, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Open the log file for appending
    FILE* file = fopen("eventlog.txt", "a");
    if (!file) {
        printf("Error opening log file!");
        return;
    }

    // Write the event details to the log file with date and time
    fprintf(file, "[%s] %s: %s\n", date, eventType, eventDesc);
    fclose(file);
}

int main() {
    // Log some sample events
    logEvent("INFO", "System started successfully.");
    logEvent("DEBUG", "Received request from client.");
    logEvent("ERROR", "Unable to connect to database.");

    // Print the contents of the log file
    FILE* file = fopen("eventlog.txt", "r");
    if (!file) {
        printf("Error opening log file!");
        return 0;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    return 0;
}