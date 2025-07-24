//FormAI DATASET v1.0 Category: System event logger ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char log_time[64];
    strftime(log_time, sizeof(log_time), "%c", tm);
    FILE *log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error opening the log file.\n");
        exit(1);
    }
    fprintf(log_file, "[%s] %s\n", log_time, event);
    fclose(log_file);
}

int main() {
    char event[100];
    printf("Enter an event to log: ");
    fgets(event, sizeof(event), stdin);
    log_event(event);
    printf("Event logged successfully.\n");
    return 0;
}