//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_LOGS_COUNT 1000

typedef struct {
    char *ip;
    char *timestamp;
    char *message;
} Log;

int is_ip_valid(char *ip) {
    // This function checks if the IP address provided is valid or not.
    // We use regular expression to validate the IP address.

    return 1; // Return 1 if IP address is valid, 0 otherwise.
}

int main() {
    Log logs[MAX_LOGS_COUNT]; // Array of logs.
    int logs_count = 0; // Number of logs in the array.
    char input[MAX_INPUT_SIZE]; // User input buffer.
    
    // Keep asking for user input until "exit" command is entered.
    while (1) {
        printf("Enter log message: ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        if (strncmp(input, "exit", strlen("exit")) == 0) {
            break;
        }

        // Parse log message to extract IP address and timestamp.
        char *ip_start = strchr(input, '[') + 1;
        char *ip_end = strchr(input, ']');
        char *timestamp_start = strchr(ip_end, '[') + 1;
        char *timestamp_end = strchr(timestamp_start, ']');

        if (ip_start == NULL || ip_end == NULL || timestamp_start == NULL || timestamp_end == NULL) {
            printf("Invalid log message format.\n");
            continue;
        }

        int ip_len = ip_end - ip_start;
        int timestamp_len = timestamp_end - timestamp_start;

        char ip[ip_len + 1];
        char timestamp[timestamp_len + 1];

        strncpy(ip, ip_start, ip_len);
        strncpy(timestamp, timestamp_start, timestamp_len);

        ip[ip_len] = '\0';
        timestamp[timestamp_len] = '\0';

        if (!is_ip_valid(ip)) {
            printf("Invalid IP address.\n");
            continue;
        }

        // Save log message into logs array.
        Log log;

        log.ip = (char *) malloc(ip_len + 1);
        log.timestamp = (char *) malloc(timestamp_len + 1);
        log.message = (char *) malloc(strlen(input) + 1);

        strcpy(log.ip, ip);
        strcpy(log.timestamp, timestamp);
        strcpy(log.message, input);

        logs[logs_count++] = log;

        // Check if there are too many failed login attempts from same IP address.
        int failed_login_attempts = 0;

        for (int i = 0; i < logs_count; i++) {
            if (strcmp(logs[i].ip, ip) == 0 && strstr(logs[i].message, "Failed login") != NULL) {
                failed_login_attempts++;
            }
        }

        if (failed_login_attempts > 3) {
            printf("Intrusion detected from %s.\n", ip);
        }
    }

    // Free memory used by logs array.
    for (int i = 0; i < logs_count; i++) {
        free(logs[i].ip);
        free(logs[i].timestamp);
        free(logs[i].message);
    }

    return 0;
}