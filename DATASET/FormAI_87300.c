//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(const char* event) {
    time_t now;
    time(&now);

    char timeStr[32];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", localtime(&now));

    FILE* file = fopen("events.log", "a");
    if (file != NULL) {
        fprintf(file, "[%s] %s\n", timeStr, event);
        fclose(file);
    }
}

int main() {
    logEvent("System started");
    logEvent("User logged in");
    logEvent("File created");
    logEvent("Network connection lost");
    logEvent("System crashed");

    printf("Events logged successfully!");

    return 0;
}