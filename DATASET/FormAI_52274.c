//FormAI DATASET v1.0 Category: System event logger ; Style: portable
#include <stdio.h>
#include <time.h>

void log_event(FILE *log_file, const char *event_type, const char *message) {
    time_t now;
    char timestamp[20];
    struct tm* time_info;

    // get current time
    now = time(NULL);
    time_info = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time_info);

    // write log entry
    fprintf(log_file, "[%s] [%s] %s\n", timestamp, event_type, message);
}

int main() {
    FILE *log_file;
    char file_name[100], input[100], message[100];

    // Ask user for filename
    printf("Enter a filename for the log file: ");
    fgets(input, 100, stdin);
    sscanf(input, "%s", file_name);

    // open file for writing
    log_file = fopen(file_name, "w");
    if (log_file == NULL) {
        printf("Error: Unable to create log file.\n");
        return 1;
    }

    // log events
    log_event(log_file, "INFO", "System startup");
    log_event(log_file, "WARNING", "Low disk space");
    log_event(log_file, "ERROR", "Unable to connect to database");
    log_event(log_file, "DEBUG", "Variable x = 5");

    // close file
    fclose(log_file);

    return 0;
}