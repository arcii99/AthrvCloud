//FormAI DATASET v1.0 Category: System event logger ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event.log"

void logEvent(char *event) {
    FILE *fp;
    time_t curr_time;
    char timestamp[40];

    memset(timestamp, 0, sizeof(timestamp));

    curr_time = time(NULL);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&curr_time));

    fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        printf("Could not open file %s for writing. Exiting...", LOG_FILE);
        exit(1);
    }

    fprintf(fp, "[%s] %s\n", timestamp, event);
    fclose(fp);
}

int main() {
    char event[100];

    printf("Enter event: ");
    fgets(event, sizeof(event), stdin);

    logEvent(event);

    printf("Event logged in %s\n", LOG_FILE);

    return 0;
}