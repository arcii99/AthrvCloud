//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum log_type {
    INFO,
    WARNING,
    ERROR
};

struct log_entry {
    enum log_type type;
    char message[256];
};

void print_log_entry(struct log_entry entry) {
    switch (entry.type) {
        case INFO:
            printf("[INFO] ");
            break;
        case WARNING:
            printf("[WARNING] ");
            break;
        case ERROR:
            printf("[ERROR] ");
            break;
    }
    printf("%s\n", entry.message);
}

int main() {
    char raw_log[] = "[INFO] Successfully connected to server\n[WARNING] Disk space running low\n[ERROR] Unable to open file\n[INFO] Application exiting\n";
    const char delim[] = "\n";
    char *token, *line;
    struct log_entry logs[10];
    int i = 0;

    line = strtok(raw_log, delim);

    while(line != NULL) {
        token = strtok(line, " ");
        struct log_entry entry;

        if(strcmp(token, "[INFO]") == 0) {
            entry.type = INFO;
        } else if(strcmp(token, "[WARNING]") == 0) {
            entry.type = WARNING;
        } else if(strcmp(token, "[ERROR]") == 0) {
            entry.type = ERROR;
        }

        token = strtok(NULL, "");
        strcpy(entry.message, token);

        logs[i++] = entry;

        line = strtok(NULL, delim);
    }

    for(int j = 0; j < i; j++) {
        print_log_entry(logs[j]);
    }

    return 0;
}