//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char username[20];
    char action[50];
} LogEntry;

int main() {
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    FILE *fp = fopen("system_log.txt", "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (num_entries < MAX_LOG_ENTRIES && fscanf(fp, "%s %s %s", log_entries[num_entries].ip, log_entries[num_entries].username, log_entries[num_entries].action) == 3) {
        num_entries++;
    }

    fclose(fp);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(log_entries[i].action, "login") == 0) {
            int login_attempts = 0;
            for (int j = i + 1; j < num_entries; j++) {
                if (strcmp(log_entries[j].ip, log_entries[i].ip) == 0 && strcmp(log_entries[j].username, log_entries[i].username) == 0) {
                    if (strcmp(log_entries[j].action, "failed login") == 0) {
                        login_attempts++;
                    }
                    else if (strcmp(log_entries[j].action, "login") == 0) {
                        // User successfully logged in after failed attempts
                        printf("INTRUSION DETECTED: %s successfully logged in after %d failed attempts.\n", log_entries[j].username, login_attempts);
                    }
                }
            }
        }
    }

    return 0;
}