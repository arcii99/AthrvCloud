//FormAI DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *message);

int main() {
    char message[100];
    time_t curr_time;
    srand(time(NULL));
    
    // Randomly generate events to log
    for (int i = 0; i < 50; i++) {
        switch(rand() % 3) {
            case 0:
                sprintf(message, "Error: File not found");
                break;
            case 1:
                sprintf(message, "Warning: System temperature high");
                break;
            case 2:
                sprintf(message, "Info: User logged in");
                break;
        }
        log_event(message);
    }
    
    return 0;
}

void log_event(char *message) {
    FILE *file;
    time_t curr_time;
    char *time_string;
    
    // Get current time as string
    curr_time = time(NULL);
    time_string = ctime(&curr_time);

    // Remove trailing newline character from time_string
    time_string[strlen(time_string) - 1] = '\0';
    
    // Write event to file
    file = fopen("event_log.txt", "a");
    fprintf(file, "[%s] %s\n", time_string, message);
    fclose(file);
}