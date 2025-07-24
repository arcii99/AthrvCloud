//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_IP_LEN 16
#define MAX_TIME_LEN 20

// Structures to hold intrusion event data
typedef struct {
    char time[MAX_TIME_LEN];
    char ip_addr[MAX_IP_LEN];
    char action[10];
} IntrusionEvent;

typedef struct {
    IntrusionEvent events[MAX_EVENTS];
    int num_events;
} IntrusionLog;

// Function prototypes
void readLogs(IntrusionLog *log, char *filename);
void analyzeLogs(IntrusionLog log);

int main(int argc, char *argv[]) {
    IntrusionLog log;
    char *filename = "intrusion.log";

    // Read intrusion log file
    readLogs(&log, filename);

    // Analyze log data and flag any suspicious activity
    analyzeLogs(log);

    return 0;
}

/**
 * Reads intrusion log data from file and adds it to the given IntrusionLog struct.
 * 
 * @param log Pointer to IntrusionLog struct to add log data to.
 * @param filename Name of file to read log data from.
 */
void readLogs(IntrusionLog *log, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char buffer[100];
    while (fgets(buffer, 100, file) != NULL) {
        if (log->num_events == MAX_EVENTS) {
            printf("Maximum number of events reached.\n");
            break;
        }

        if (strlen(buffer) > 0 && buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }

        char *time = strtok(buffer, ",");
        char *ip_addr = strtok(NULL, ",");
        char *action = strtok(NULL, ",");

        strcpy(log->events[log->num_events].time, time);
        strcpy(log->events[log->num_events].ip_addr, ip_addr);
        strcpy(log->events[log->num_events].action, action);

        log->num_events++;
    }

    fclose(file);
}

/**
 * Analyzes intrusion log data to flag any suspicious activity.
 * 
 * @param log IntrusionLog struct containing log data to analyze.
 */
void analyzeLogs(IntrusionLog log) {
    for (int i = 0; i < log.num_events; i++) {
        // Check for repeated login failures from same IP within 10 minutes
        if (strcmp(log.events[i].action, "failed login") == 0) {
            int count_failures = 1;
            for (int j = i+1; j < log.num_events; j++) {
                if (strcmp(log.events[j].ip_addr, log.events[i].ip_addr) == 0 &&
                    strcmp(log.events[j].action, "failed login") == 0 &&
                    atoi(log.events[j].time) - atoi(log.events[i].time) <= 600) {
                    count_failures++;
                } else {
                    break;
                }
            }
            if (count_failures >= 3) {
                printf("Possible brute-force attack - IP address: %s\n", log.events[i].ip_addr);
            }
        }

        // Check for login from suspicious IP
        if (strcmp(log.events[i].action, "login") == 0) {
            if (strcmp(log.events[i].ip_addr, "123.45.67.89") == 0) {
                printf("Possible unauthorized access - IP address: %s\n", log.events[i].ip_addr);
            }
        }
    }
}