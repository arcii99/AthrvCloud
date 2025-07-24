//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 200

typedef struct {
    char *timestamp;
    char *log_level;
    char *message;
} LogLine;

void analyze_logs(LogLine logs[], int num_logs) {
    int info_count = 0, warning_count = 0, error_count = 0;
    for (int i = 0; i < num_logs; i++) {
        if (strcmp(logs[i].log_level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(logs[i].log_level, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(logs[i].log_level, "ERROR") == 0) {
            error_count++;
        }
    }
    printf("\nAnalysis Results:\n");
    printf("Total Logs:\t%d\n", num_logs);
    printf("INFO Logs:\t%d\n", info_count);
    printf("WARNING Logs:\t%d\n", warning_count);
    printf("ERROR Logs:\t%d\n", error_count);
}

int main() {
    printf("Please input your log entries (Max %d lines):\n\n", MAX_LOG_LINES);
    LogLine logs[MAX_LOG_LINES];
    int num_logs = 0;
    char line[MAX_LINE_LENGTH];
    while (num_logs < MAX_LOG_LINES && fgets(line, MAX_LINE_LENGTH, stdin)) {
        char *timestamp = strtok(line, ",");
        char *log_level = strtok(NULL, ",");
        char *message = strtok(NULL, "");
        if (timestamp == NULL || log_level == NULL || message == NULL) {
            printf("Invalid log entry. Please make sure it's in the format: 'timestamp,log_level,message'\n");
            continue;
        }
        logs[num_logs].timestamp = timestamp;
        logs[num_logs].log_level = log_level;
        logs[num_logs].message = message;
        num_logs++;
    }
    analyze_logs(logs, num_logs);
    return 0;
}