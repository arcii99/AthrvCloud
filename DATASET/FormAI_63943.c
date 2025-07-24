//FormAI DATASET v1.0 Category: System event logger ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_FILE "events.log" // define the file name

/* Function to write event data into the log file */
void logEvent(char event[]) {
    FILE *fp;
    time_t raw_time;
    struct tm *time_info;
    char time_str[20];

    // get current time
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(time_str, 20, "%Y-%m-%d %H:%M:%S", time_info);

    // open the file for appending
    fp = fopen(EVENT_FILE, "a");

    // write the event to the file
    fprintf(fp, "%s: %s\n", time_str, event);

    // close the file
    fclose(fp);
}

int main() {
    // sample event data
    char event1[] = "System startup";
    char event2[] = "User login failed";
    char event3[] = "File saved successfully";

    // log the events
    logEvent(event1);
    logEvent(event2);
    logEvent(event3);

    // print the log file contents
    char ch;
    FILE *fp;

    fp = fopen(EVENT_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    printf("Log file contents:\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);

    return 0;
}