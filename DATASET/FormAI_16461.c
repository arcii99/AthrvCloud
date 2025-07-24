//FormAI DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event){
    FILE *fp;
    time_t current_time;
    char *timestamp;

    time(&current_time);
    timestamp = ctime(&current_time);

    fp = fopen("event_log.txt", "a");

    if(fp == NULL) {
        printf("Error: Could not open event log file.");
        exit(1);
    }

    fprintf(fp, "%s | %s\n", timestamp, event);

    fclose(fp);
}

int main(){
    char event[100];

    printf("Enter an event: ");
    fflush(stdin);
    fgets(event, 100, stdin);
    log_event(event);

    printf("Event logged successfully.\n");

    return 0;
}