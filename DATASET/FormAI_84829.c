//FormAI DATASET v1.0 Category: System event logger ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event_type, char *description);

int main() {
    char event_type[20];
    char description[100];
    
    printf("Enter event type: ");
    fgets(event_type, 20, stdin);
    printf("Enter description: ");
    fgets(description, 100, stdin);

    log_event(event_type, description);

    return 0;
}

void log_event(char *event_type, char *description) {
    FILE *file;
    time_t log_time;

    file = fopen("event_log.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    time(&log_time);

    fprintf(file, "%s - %s: %s", ctime(&log_time), event_type, description);

    fclose(file);
}