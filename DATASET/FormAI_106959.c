//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
    char timestamp[20];
    char message[100];
} LogEntry;

LogEntry logs[MAX_LOG_ENTRIES];
int num_entries = 0;

void log_entry(char* message) {
    if (num_entries >= MAX_LOG_ENTRIES) {
        printf("ERROR: Log is full\n");
    } else {
        LogEntry entry;
        sprintf(entry.timestamp, "%d", time(NULL));
        strcpy(entry.message, message);
        logs[num_entries] = entry;
        num_entries++;
    }
}

int main() {
    printf("Welcome to the Intrusion Detection System\n");

    char input[100];
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "quit") == 0) {
            printf("Exiting...\n");
            break;
        } else if (strcmp(input, "view_logs") == 0) {
            for (int i = 0; i < num_entries; i++) {
                printf("%s - %s\n", logs[i].timestamp, logs[i].message);
            }
            if (num_entries == 0) {
                printf("No logs found\n");
            }
        } else {
            log_entry(input);
            printf("Logged: %s\n", input);
        }
    }

    return 0;
}