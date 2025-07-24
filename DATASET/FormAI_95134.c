//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000

struct log_entry {
    int id;
    char message[100];
};

struct node {
    struct log_entry log;
    struct node *next;
};

struct node *head = NULL;
int current_id = 1;

void log_message(char *message) {
    struct log_entry entry;
    entry.id = current_id++;
    strcpy(entry.message, message);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->log = entry;
    new_node->next = head;
    head = new_node;
}

void print_logs() {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("[%d] %s\n", current_node->log.id, current_node->log.message);
        current_node = current_node->next;
    }
}

int main() {
    // Simulate some intrusion attempts
    log_message("Attempted SQL injection attack on database server");
    log_message("Multiple login attempts with invalid credentials");
    log_message("File system modification detected");
    log_message("Connection request from blacklisted IP address");

    // Print all log entries
    printf("All log entries:\n");
    print_logs();

    // Search for specific log entries
    printf("\nSearching for specific log entries...\n");
    struct node *current_node = head;
    while (current_node != NULL) {
        if (strstr(current_node->log.message, "injection") != NULL) {
            printf("Found an SQL injection attempt (ID %d): %s\n", current_node->log.id, current_node->log.message);
        } else if (strstr(current_node->log.message, "login attempts") != NULL) {
            printf("Found multiple failed login attempts (ID %d): %s\n", current_node->log.id, current_node->log.message);
        }
        current_node = current_node->next;
    }

    return 0;
}