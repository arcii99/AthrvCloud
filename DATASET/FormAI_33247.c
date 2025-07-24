//FormAI DATASET v1.0 Category: System event logger ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOGFILE "system_events.log"

void log_event(char *event_type, char *event_description) {
    FILE *fp;

    fp = fopen(LOGFILE, "a");
    if (fp == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    time_t current_time;
    char *time_str;
    current_time = time(NULL);
    time_str = ctime(&current_time);
    time_str[strlen(time_str)-1] = '\0';

    fprintf(fp, "[%s] %s - %s\n", time_str, event_type, event_description);

    fclose(fp);
}

int main() {

    char event_type[20];
    char event_description[200];

    printf("Welcome to the system event logger.\n");
    printf("Please enter the type of event: ");
    scanf("%s", event_type);
    printf("Please enter a brief description of the event: ");
    scanf("%s", event_description);

    log_event(event_type, event_description);

    printf("Event logged successfully. Check the log file %s for details.\n", LOGFILE);

    return 0;
}