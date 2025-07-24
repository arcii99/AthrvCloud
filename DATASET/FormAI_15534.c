//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 256
#define MAX_LOG_LINES 1000

typedef struct log_line_t {
    char msg[MAX_MSG_LEN];
} log_line_t;

typedef struct log_file_t {
    log_line_t lines[MAX_LOG_LINES];
    int pos;
} log_file_t;

void log_message(log_file_t* log, char* message) {
    if (log->pos >= MAX_LOG_LINES) {
        // roll over the log
        log->pos = 0;
    }
    strncpy(log->lines[log->pos].msg, message, MAX_MSG_LEN);
    log->pos++;
}

void check_for_intrusion(log_file_t* log) {
    int intrusion_detected = 0;
    // check for patterns that match common intrusion attempts
    for (int i = 0; i < log->pos; i++) {
        if (strstr(log->lines[i].msg, "attempted to access forbidden resources") != NULL ||
            strstr(log->lines[i].msg, "unauthorized access attempt") != NULL ||
            strstr(log->lines[i].msg, "exploit attempt detected") != NULL) {
            intrusion_detected = 1;
            break;
        }
    }
    if (intrusion_detected) {
        printf("Intrusion detected! Check logs for more information.\n");
    }
}

int main(void) {
    log_file_t log = {0};
    char message[MAX_MSG_LEN] = {0};

    printf("Press Ctrl+C to exit...\n");

    while (1) {
        printf("> ");
        fgets(message, MAX_MSG_LEN, stdin);
        log_message(&log, message);
        check_for_intrusion(&log);
    }

    return EXIT_SUCCESS;
}