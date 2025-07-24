//FormAI DATASET v1.0 Category: System event logger ; Style: grateful
#include <stdio.h>
#include <time.h>

void log_event(char* event) {
    time_t rawtime;
    struct tm * timeinfo;
    char timestamp[20];

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", timeinfo);

    FILE* log_file = fopen("event_log.txt", "a");

    if (log_file == NULL) {
        printf("Error opening log file\n");
        return;
    }

    fprintf(log_file, "[%s] %s\n", timestamp, event);

    fclose(log_file);
}

int main() {

    log_event("System shut down");

    log_event("User login");

    return 0;
}