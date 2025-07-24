//FormAI DATASET v1.0 Category: System event logger ; Style: automated
#include <stdio.h>
#include <time.h>

void log_event(char* event) {
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);

    if (current_time == ((time_t)-1)) {
        fprintf(stderr, "Failed to get current time.\n");
        return;
    }

    c_time_string = ctime(&current_time);

    if (c_time_string == NULL) {
        fprintf(stderr, "Failed to convert current time.\n");
        return;
    }

    FILE* log_file = fopen("event.log", "a");

    if (log_file == NULL) {
        fprintf(stderr, "Failed to open log file.\n");
        return;
    }

    fprintf(log_file, "%s: %s", c_time_string, event);
    fclose(log_file);
}

int main() {
    char event[100];

    printf("Enter the event you want to log: ");
    fgets(event, 100, stdin);

    log_event(event);

    return 0;
}