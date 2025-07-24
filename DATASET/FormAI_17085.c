//FormAI DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event.log"

void log_event(char* event_type, char* source, char* message);

int main() {
    srand(time(NULL));

    char* event_types[] = {"ERROR", "WARNING", "INFO"};
    char* sources[] = {"DATABASE", "SERVER", "CLIENT", "NETWORK"};

    // Generate random events and log them
    int i;
    for(i = 0; i < 10; i++) {
        char* event_type = event_types[rand() % 3];
        char* source = sources[rand() % 4];
        char message[100];
        sprintf(message, "Event %d occurred in %s", i, source);

        log_event(event_type, source, message);
    }

    return 0;
}

void log_event(char* event_type, char* source, char* message) {
    // Asynchronous file writing
    FILE* log_file = fopen(LOG_FILE, "a");
    if(log_file != NULL) {
        time_t current_time = time(NULL);
        char* time_str = ctime(&current_time);
        time_str[strlen(time_str)-1] = '\0'; // Remove newline char

        fprintf(log_file, "[%s] <%s> (%s) %s\n", time_str, event_type, source, message);

        fclose(log_file);
    }
}