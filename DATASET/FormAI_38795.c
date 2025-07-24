//FormAI DATASET v1.0 Category: Log analysis ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000
#define MAX_IP_LEN 20
#define MAX_DATE_TIME_LEN 50

typedef struct Log {
    char ip[MAX_IP_LEN];
    char date_time[MAX_DATE_TIME_LEN];
    char request[MAX_LINE_LEN];
    int status_code;
    char user_agent[MAX_LINE_LEN];
} Log;

// Helper function to remove leading and trailing whitespace from a string
char *trim(char *s) {
    char *start = s;
    char *end = s + strlen(s) - 1;
    while (isspace(*start)) {
        start++;
    }
    while (isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    return start;
}

int main() {
    FILE *in = fopen("log.txt", "r");
    if (!in) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    Log logs[MAX_LINE_LEN];
    int n_logs = 0;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, in)) {
        // Parse IP address
        char *ip = strtok(line, " ");
        if (!ip) {
            fprintf(stderr, "Failed to parse IP address\n");
            continue;
        }

        // Parse date and time
        char *date_time = strtok(NULL, "]");
        if (!date_time) {
            fprintf(stderr, "Failed to parse date and time\n");
            continue;
        }

        // Parse HTTP request
        char *request_start = strstr(line, "\"");
        char *request_end = strstr(request_start + 1, "\"");
        if (!request_start || !request_end) {
            fprintf(stderr, "Failed to parse HTTP request\n");
            continue;
        }
        char request[MAX_LINE_LEN];
        strncpy(request, request_start, request_end - request_start + 1);
        request[request_end - request_start + 1] = '\0';

        // Parse status code
        char *status_code_str = strtok(NULL, " ");
        if (!status_code_str) {
            fprintf(stderr, "Failed to parse status code\n");
            continue;
        }
        int status_code = atoi(status_code_str);

        // Parse user agent
        char *user_agent_start = strstr(line, "\"");
        char *user_agent_end = strstr(user_agent_start + 1, "\"");
        if (!user_agent_start || !user_agent_end) {
            fprintf(stderr, "Failed to parse user agent\n");
            continue;
        }
        char user_agent[MAX_LINE_LEN];
        strncpy(user_agent, user_agent_start + 1, user_agent_end - user_agent_start - 1);
        user_agent[user_agent_end - user_agent_start - 1] = '\0';

        // Create log entry
        Log log = {
            .ip = trim(ip),
            .date_time = trim(date_time + 2),
            .request = trim(request),
            .status_code = status_code,
            .user_agent = trim(user_agent)
        };

        // Add log entry to array
        logs[n_logs++] = log;
    }

    fclose(in);

    // Output log entries
    printf("%-20s %-25s %-25s %-10s %-s\n", "IP Address", "Date and Time", "HTTP Request", "Status Code", "User Agent");
    for (int i = 0; i < n_logs; i++) {
        printf("%-20s %-25s %-25s %-10d %-s\n", logs[i].ip, logs[i].date_time, logs[i].request, logs[i].status_code, logs[i].user_agent);
    }

    return 0;
}