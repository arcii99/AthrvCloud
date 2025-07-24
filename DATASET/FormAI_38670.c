//FormAI DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>

#define MAX_IP_LEN 15 // Maximum length of IP address
#define MAX_RULES 100 // Maximum number of firewall rules
#define MAX_LINE_LEN 256 // Maximum length of input line

typedef struct FirewallRule {
    char ip[MAX_IP_LEN + 1];
    bool isBlocked;
} FirewallRule;

// Global variables
FirewallRule rules[MAX_RULES]; // Array of firewall rules
int ruleCount = 0; // Total number of rules

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex to lock the rules array

void addRule(char *ip, bool isBlocked) {
    // Lock the array to prevent race conditions
    pthread_mutex_lock(&mutex);

    if (ruleCount == MAX_RULES) {
        printf("Error: Maximum number of rules exceeded.\n");
        return;
    }

    strcpy(rules[ruleCount].ip, ip);
    rules[ruleCount].isBlocked = isBlocked;
    ruleCount++;

    // Unlock the array
    pthread_mutex_unlock(&mutex);

    printf("Rule added successfully.\n");
}

void *processPacket(void *ipPtr) {
    char *ip = (char*) ipPtr;

    // Check if the IP address is blocked
    pthread_mutex_lock(&mutex);

    bool isBlocked = false;

    for (int i = 0; i < ruleCount; i++) {
        if (strstr(ip, rules[i].ip) != NULL) {
            isBlocked = rules[i].isBlocked;
            break;
        }
    }

    pthread_mutex_unlock(&mutex);

    if (isBlocked) {
        printf("Packet from IP %s BLOCKED.\n", ip);
    } else {
        printf("Packet from IP %s ALLOWED.\n", ip);
    }

    return NULL;
}

int main() {
    char line[MAX_LINE_LEN];

    while (true) {
        printf("Enter command: ");

        if (fgets(line, MAX_LINE_LEN, stdin) == NULL) {
            printf("Error: Failed to read line from stdin.\n");
            continue;
        }

        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, " ");

        if (strcmp(token, "add") == 0) {
            char ip[MAX_IP_LEN + 1];
            bool isBlocked;

            // Parse IP address
            token = strtok(NULL, " ");

            if (token == NULL) {
                printf("Error: IP address not specified.\n");
                continue;
            }

            if (strlen(token) > MAX_IP_LEN) {
                printf("Error: IP address too long.\n");
                continue;
            }

            strcpy(ip, token);

            // Parse isBlocked flag
            token = strtok(NULL, " ");

            if (token == NULL) {
                printf("Error: isBlocked flag not specified.\n");
                continue;
            }

            if (strcmp(token, "true") == 0) {
                isBlocked = true;
            } else if (strcmp(token, "false") == 0) {
                isBlocked = false;
            } else {
                printf("Error: Invalid isBlocked flag.\n");
                continue;
            }

            addRule(ip, isBlocked);
        } else if (strcmp(token, "process") == 0) {
            char ip[MAX_IP_LEN + 1];

            // Parse IP address
            token = strtok(NULL, " ");

            if (token == NULL) {
                printf("Error: IP address not specified.\n");
                continue;
            }

            if (strlen(token) > MAX_IP_LEN) {
                printf("Error: IP address too long.\n");
                continue;
            }

            strcpy(ip, token);

            // Create a new thread to process the packet
            pthread_t threadId;

            if (pthread_create(&threadId, NULL, processPacket, ip) != 0) {
                printf("Error: Failed to create thread.\n");
                continue;
            }
        } else if (strcmp(token, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}