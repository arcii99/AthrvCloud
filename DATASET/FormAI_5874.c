//FormAI DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum eventType {ERROR, WARNING, INFORMATION}; // Event types enum

struct Event {
    enum eventType type;
    char message[256];
    time_t timestamp;
};

void logEvent(struct Event event) {
    FILE *fp;
    fp = fopen("logfile.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Convert timestamp to string
    char timestampStr[32];
    strftime(timestampStr, sizeof(timestampStr), "%Y-%m-%d %H:%M:%S", localtime(&event.timestamp));

    // Write to file
    fprintf(fp, "[%s] Event Type: %d | Event Message: %s\n", timestampStr, event.type, event.message);
    fclose(fp);
}

int main() {
    // Example usage:
    struct Event errorEvent = {ERROR, "Unable to connect to server.", time(NULL)};
    logEvent(errorEvent);

    struct Event warningEvent = {WARNING, "Disk space is low.", time(NULL)};
    logEvent(warningEvent);

    struct Event infoEvent = {INFORMATION, "User 'admin' logged in.", time(NULL)};
    logEvent(infoEvent);

    return 0;
}