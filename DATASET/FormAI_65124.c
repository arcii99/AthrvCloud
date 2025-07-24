//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Linus Torvalds
/*
 * Intrusion Detection System in C
 *
 * Author: Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000      // maximum number of lines in log file
#define MAX_LOG_LENGTH 100      // maximum length of each log line
#define MAX_KEYWORDS 10         // maximum number of suspicious keywords
#define MAX_ALERTS 3            // maximum number of alerts to be triggered

char log_file[MAX_LOG_LINES][MAX_LOG_LENGTH];  // array to store log file
char keywords[MAX_KEYWORDS][MAX_LOG_LENGTH];   // array to store suspicious keywords
int alerts_triggered[MAX_ALERTS] = {0};        // array to store number of times each alert is triggered

void read_log_file(char* file_name) {
    FILE* file_ptr;
    char line[MAX_LOG_LENGTH];
    int line_count = 0;

    file_ptr = fopen(file_name, "r");

    if (file_ptr == NULL) {
        printf("Error! Could not open file.\n");
        exit(1);
    }

    // read each line of file
    while (fgets(line, MAX_LOG_LENGTH, file_ptr) != NULL && line_count < MAX_LOG_LINES) {
        strcpy(log_file[line_count], line);
        line_count++;
    }

    fclose(file_ptr);
}

void read_suspicious_keywords(char* file_name) {
    FILE* file_ptr;
    char keyword[MAX_LOG_LENGTH];
    int keyword_count = 0;

    file_ptr = fopen(file_name, "r");

    if (file_ptr == NULL) {
        printf("Error! Could not open file.\n");
        exit(1);
    }

    // read each keyword of file
    while (fgets(keyword, MAX_LOG_LENGTH, file_ptr) != NULL && keyword_count < MAX_KEYWORDS) {
        strcpy(keywords[keyword_count], keyword);
        keyword_count++;
    }

    fclose(file_ptr);
}

void detect_intrusion() {
    int i, j;
    int keyword_count, alert_count;

    // loop through each line of log file
    for (i = 0; i < MAX_LOG_LINES; i++) {
        keyword_count = 0;
        alert_count = 0;

        // loop through each suspicious keyword
        for (j = 0; j < MAX_KEYWORDS; j++) {
            if (strstr(log_file[i], keywords[j]) != NULL) {
                keyword_count++;
                alert_count += j+1;     // increase alert level based on keyword index
            }
        }

        // increase alert count for corresponding alert levels
        if (alert_count >= 1 && alert_count <= MAX_ALERTS) {
            alerts_triggered[alert_count-1]++;   // alert level starts from 1, so adjust index
        }
    }
}

void print_alerts() {
    int i;

    printf("\n\nINTRUSION ALERTS\n");
    printf("-----------------\n");

    for (i = 0; i < MAX_ALERTS; i++) {
        printf("ALERT %d TRIGGERED %d TIMES\n", i+1, alerts_triggered[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <log-file> <keywords-file>\n", argv[0]);
        exit(1);
    }

    read_log_file(argv[1]);
    read_suspicious_keywords(argv[2]);
    detect_intrusion();
    print_alerts();

    return 0;
}