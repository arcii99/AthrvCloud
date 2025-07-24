//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "system_logs.txt"

void log_event(char* event) {
    FILE* log_file = fopen(LOG_FILE, "a");
    time_t current_time;
    char* timestamp;

    if (log_file == NULL) {
        printf("Error: Unable to open log file for writing.\n");
        exit(1);
    }

    // get current time and format as string
    current_time = time(NULL);
    timestamp = ctime(&current_time);

    // write event with timestamp to log file
    fprintf(log_file, "[%s]: %s\n", timestamp, event);
    fclose(log_file);
}

int main() {
    char user_input[256];
    printf("Enter an event to log:\n");

    while (fgets(user_input, sizeof(user_input), stdin)) {
        // remove trailing newline character
        user_input[strcspn(user_input, "\n")] = 0;
        log_event(user_input);
        printf("Successfully logged event: %s\n", user_input);
        printf("Enter another event to log:\n");
    }

    return 0;
}