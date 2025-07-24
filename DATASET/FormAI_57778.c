//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 100
#define MAX_LENGTH 100

// Global variables
char logs[MAX_LOGS][MAX_LENGTH];
int num_logs = 0;

// Function to check for suspicious activity
void check_logs() {
    int i, j;
    for (i=0; i<num_logs; i++) {
        for (j=i+1; j<num_logs; j++) {
            if (strcmp(logs[i], logs[j]) == 0) {
                printf("Intrusion detected: %s\n", logs[i]);
                break;
            }
        }
    }
}

// Main function
int main() {
    char buffer[MAX_LENGTH];
    printf("Start logging: (Type 'exit' to stop logging)\n");
    while (1) {
        fgets(buffer, MAX_LENGTH, stdin);
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }
        if (num_logs >= MAX_LOGS) {
            printf("Maximum number of logs reached.\n");
            break;
        }
        strcpy(logs[num_logs], buffer);
        num_logs++;
    }
    check_logs();
    return 0;
}