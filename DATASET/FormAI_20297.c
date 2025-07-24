//FormAI DATASET v1.0 Category: System event logger ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    char event[100];
    time_t now;

    /* Open log file in append mode */
    fp = fopen("/var/log/system_events.log", "a");

    /* Check if file opened successfully */
    if (fp == NULL) {
        perror("Error opening log file!");
        exit(EXIT_FAILURE);
    }

    /* Get current time */
    time(&now);

    /* Prompt user for event description */
    printf("Enter event description: ");
    fgets(event, 100, stdin);

    /* Write event to log file */
    fprintf(fp, "[%s] %s", ctime(&now), event);

    /* Close log file */
    fclose(fp);

    /* Print success message */
    printf("Event logged successfully!");

    return 0;
}