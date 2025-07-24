//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to write events to a log file */
void write_log(char* event) {
    FILE* log_file = fopen("event.log", "a");
    if (log_file == NULL) {
        printf("Error opening log file!");
    } else {
        time_t t = time(NULL);
        struct tm* tm = localtime(&t);
        fprintf(log_file, "%02d.%02d.%04d %02d:%02d:%02d - %s\n",
            tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900,
            tm->tm_hour, tm->tm_min, tm->tm_sec, event);
        fclose(log_file);
    }
}

int main() {
    char* event;
    printf("Enter an event to log: ");
    fgets(event, 50, stdin);
    write_log(event);
    printf("Event successfully logged!");
    return 0;
}