//FormAI DATASET v1.0 Category: System event logger ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to append the event to the log file
void logEvent(char* event) {
    FILE *fp;
    fp = fopen("event_log.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fprintf(fp, "%s\n", event);
    fclose(fp);
}

int main() {
    // Get current time
    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    // Create and log system event
    char event[100];
    sprintf(event, "System event occurred on %d-%02d-%02d at %02d:%02d:%02d", 
            now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, 
            now->tm_hour, now->tm_min, now->tm_sec);
    logEvent(event);

    printf("System event logged successfully.\n");

    return 0;
}