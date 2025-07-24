//FormAI DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LINE_LENGTH 200

int main() {

    char logs[MAX_LOG_LINES][MAX_LOG_LINE_LENGTH];
    int num_lines = 0;

    // read log file and populate logs array
    FILE *file = fopen("sample_log.txt", "r");
    if (file == NULL) {
        printf("Failed to read log file\n");
        return 1;
    }

    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, file) != NULL) {
        if (num_lines >= MAX_LOG_LINES) {
            printf("Reached maximum log capacity\n");
            break;
        }
        strcpy(logs[num_lines], line);
        num_lines++;
    }

    fclose(file);

    printf("Total number of log lines: %d\n", num_lines);

    // count number of ERROR and WARNING messages
    int num_errors = 0;
    int num_warnings = 0;
    for (int i = 0; i < num_lines; i++) {
        char* token = strtok(logs[i], " ");
        while (token != NULL) {
            if (strcmp(token, "ERROR") == 0) {
                num_errors++;
            } else if (strcmp(token, "WARNING") == 0) {
                num_warnings++;
            }
            token = strtok(NULL, " ");
        }
    }

    printf("Number of ERROR messages: %d\n", num_errors);
    printf("Number of WARNING messages: %d\n", num_warnings);

    // calculate percentage of ERROR and WARNING messages
    double pct_errors = ((double) num_errors / (double) num_lines) * 100;
    double pct_warnings = ((double) num_warnings / (double) num_lines) * 100;

    printf("Percentage of ERROR messages: %0.2f%%\n", pct_errors);
    printf("Percentage of WARNING messages: %0.2f%%\n", pct_warnings);

    // count number of unique IP addresses
    char ip_addresses[MAX_LOG_LINES][MAX_LOG_LINE_LENGTH];
    int num_ip_addresses = 0;
    for (int i = 0; i < num_lines; i++) {
        char* token = strtok(logs[i], " ");
        while (token != NULL) {
            if (isdigit(token[0])) {
                // check if IP address already exists in array
                int found = 0;
                for (int j = 0; j < num_ip_addresses; j++) {
                    if (strcmp(ip_addresses[j], token) == 0) {
                        found = 1;
                        break;
                    }
                }
                // if IP address is not found, add it to array
                if (!found) {
                    strcpy(ip_addresses[num_ip_addresses], token);
                    num_ip_addresses++;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    printf("Number of unique IP addresses: %d\n", num_ip_addresses);

    return 0;
}