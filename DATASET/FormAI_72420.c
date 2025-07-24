//FormAI DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <time.h>

// Function definitions
void logEvent(char* eventType, char* eventDescription);

// Main function
int main() {
    // Get the current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Log an event
    logEvent("SYSTEM", "Program started");

    // Log another event
    logEvent("ERROR", "Could not find file");

    // Log one more event
    logEvent("WARNING", "Low disk space");

    // Exit the program
    return 0;
}

// Function that logs an event
void logEvent(char* eventType, char* eventDescription) {
    // Get the current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Create a filename for the log file
    char filename[100];
    sprintf(filename, "log_%d-%02d-%02d.txt", t->tm_year+1900, t->tm_mon+1, t->tm_mday);

    // Open the log file
    FILE* logfile = fopen(filename, "a");

    // Write the event details to the log file
    fprintf(logfile, "[%02d:%02d:%02d][%s] %s\n", t->tm_hour, t->tm_min, t->tm_sec, eventType, eventDescription);

    // Close the log file
    fclose(logfile);
}