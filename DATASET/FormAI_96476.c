//FormAI DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <time.h>

#define LOG_FILE "system.log"

int main() {
    printf("Wow! Looks like I'm logging some system events today!\n");

    FILE *log = fopen(LOG_FILE, "a");
    if (log == NULL) {
        printf("Oops, couldn't open the log file. Aborting!\n");
        return 1;
    }

    printf("Phew, log file opened successfully!\n");

    time_t current_time;
    struct tm *time_info;
    char timestamp[30];
    char event[100];

    while (1) {
        printf("Enter an event to log (or 'exit' to quit): ");
        scanf("%99[^\n]", event);
        getchar();

        if (strcmp(event, "exit") == 0) {
            printf("Goodbye, happy logging!\n");
            break;
        }

        time(&current_time);
        time_info = localtime(&current_time);
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time_info);

        fprintf(log, "[%s] %s\n", timestamp, event);
        fflush(log);

        printf("Event logged successfully! Keep 'em coming!\n");
    }

    fclose(log);

    return 0;
}