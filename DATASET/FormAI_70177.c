//FormAI DATASET v1.0 Category: System event logger ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *log_file;
    time_t current_time;
    struct tm *time_info;
    char time_str[9];

    log_file = fopen("event.log", "a");
    if (log_file == NULL) {
        printf("Error: Unable to open log file.\n");
        exit(1);
    }

    current_time = time(NULL);
    time_info = localtime(&current_time);

    strftime(time_str, sizeof(time_str), "%H:%M:%S", time_info);

    fprintf(log_file, "[%s] System started.\n", time_str);

    // Simulate some system events
    fprintf(log_file, "[%s] User logged in.\n", time_str);
    fprintf(log_file, "[%s] Application started.\n", time_str);
    fprintf(log_file, "[%s] File saved.\n", time_str);
    fprintf(log_file, "[%s] User logged out.\n", time_str);

    current_time = time(NULL);
    time_info = localtime(&current_time);

    strftime(time_str, sizeof(time_str), "%H:%M:%S", time_info);

    fprintf(log_file, "[%s] System stopped.\n", time_str);

    fclose(log_file);

    return 0;
}