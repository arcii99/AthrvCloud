//FormAI DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define MAX_IP_LEN 16

#define DEBUG_FLAG 0        // Set flag to 1 to enable debug output
#define ACCESS_LOG_FILE "access.log"

void parse_line(char *line, char *ip_address, char *datetime) {
    // Parse IP address and datetime from Apache access log line
    char *token;
    int i = 0;

    // Parse IP Address
    token = strtok(line, " ");
    while (token != NULL) {
        i++;
        if (i == 1) {
            strcpy(ip_address, token);
        }
        if (i == 4) {
            strcpy(datetime, token + 1);
            break;
        }
        token = strtok(NULL, " ");
    }
}

void analyze_logs(char *filename) {
    // Analyze Apache access log file, print any suspicious activity
    FILE *fp;
    char line[MAX_LINE_LEN];
    char ip_address[MAX_IP_LEN];
    char datetime[MAX_LINE_LEN];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return;
    }

    printf("Analyzing logs...\n");

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        parse_line(line, ip_address, datetime);

        // Check for suspicious activity
        if (strstr(line, "wp-login.php") != NULL) {
            printf("Possible brute force attack from IP Address %s on %s", ip_address, datetime);
        }
    }
    fclose(fp);
}

int main(void) {
    if (DEBUG_FLAG) {
        printf("Debug mode enabled.\n");
    }
    analyze_logs(ACCESS_LOG_FILE);
    return 0;
}