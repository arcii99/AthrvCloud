//FormAI DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void log_event(char* event_type, char* event_description) {
    FILE* fp = fopen("system_log.txt", "a");
    if(fp == NULL) {
        printf("Error creating/opening log file.\n");
        exit(1);
    }
    time_t current_time;
    time(&current_time);
    char* time_string = ctime(&current_time);
    time_string[strlen(time_string) - 1] = '\0'; // Removing the newline character at the end.
    fprintf(fp, "%s;%s;%s\n", time_string, event_type, event_description);
    fclose(fp);
}

int main() {
    char event_type[20];
    char event_description[100];
    printf("Enter event type: ");
    scanf("%s", event_type);
    printf("Enter event description: ");
    scanf(" %[^\n]s", event_description); // Allows input with spaces.
    log_event(event_type, event_description);
    printf("Event logged successfully!\n");
    return 0;
}