//FormAI DATASET v1.0 Category: System event logger ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
void init_logger(void);
void log_event(char* event);
void clean_up(void);

/* Global variables */
FILE* log_file;

int main() {
    init_logger();

    log_event("Program started.");

    // Code implementation ...

    log_event("Program ended.");

    clean_up();

    return 0;
}

void init_logger() {
    log_file = fopen("event_log.txt", "w");
    if (log_file == NULL) {
        printf("Error opening log file.");
        exit(1);
    }
}

void log_event(char* event) {
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    fprintf(log_file, "%s: %s\n", c_time_string, event);
}

void clean_up() {
    fclose(log_file);
}