//FormAI DATASET v1.0 Category: System event logger ; Style: accurate
#include <stdio.h>
#include <time.h>

void logEvent(const char* eventType, const char* message) {
    // Get current time
    time_t currentTime = time(NULL);
    char* timestamp = ctime(&currentTime);

    // Open log file
    FILE* logFile = fopen("event.log", "a");

    // Write event details to log file
    fprintf(logFile, "[%s] %s: %s\n", timestamp, eventType, message);

    // Close log file
    fclose(logFile);
}

int main() {
    // Log event
    logEvent("INFO", "Program started");

    // Do some work...

    // Log event
    logEvent("WARNING", "Something unexpected happened");

    // Do more work...

    // Log event
    logEvent("ERROR", "Program encountered an error and will now exit");

    // Exit program
    return 0;
}