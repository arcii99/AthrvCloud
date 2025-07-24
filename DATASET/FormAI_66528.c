//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    char event[100];

    fp = fopen("system_events.log", "a"); // open file for writing logs

    if (fp == NULL) { // check if file was opened properly
        printf("Failed to open file.\n");
        exit(1);
    }

    printf("Enter the event description: ");
    fgets(event, 100, stdin); // get event from user input

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo); // format the timestamp

    // write the event and timestamp to the log file
    fprintf(fp, "[%s] %s", buffer, event);

    fclose(fp); // close file
    printf("Event logged successfully.\n");
    return 0;
}