//FormAI DATASET v1.0 Category: System event logger ; Style: retro
#include <stdio.h>
#include <time.h>

int main() {
    FILE *logFile;
    char fileName[25];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Create log file name
    snprintf(fileName, sizeof(fileName), "%d-%02d-%02d_event.log", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday);

    // Open log file
    logFile = fopen(fileName, "a");

    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    // Log system event
    char logEntry[100];
    printf("Enter system event to log: ");
    fgets(logEntry, 100, stdin);

    fprintf(logFile, "[%02d:%02d:%02d] %s", tm->tm_hour, tm->tm_min, tm->tm_sec, logEntry);

    printf("System event logged successfully.\n");

    // Close log file
    fclose(logFile);

    return 0;
}