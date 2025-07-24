//FormAI DATASET v1.0 Category: Firewall ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

typedef struct Node {
    char ip[16];
    struct Node* next;
} Node;

Node* head = NULL;

void insert(char* ip) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    strncpy(temp->ip, ip, 16);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

int search(char* ip) {
    Node* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->ip, ip) == 0) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void delete(char* ip) {
    if (head == NULL) {
        return;
    }
    if (strcmp(head->ip, ip) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL) {
        if (strcmp(curr->ip, ip) == 0) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void printList() {
    Node* curr = head;
    while (curr != NULL) {
        printf("%s\n", curr->ip);
        curr = curr->next;
    }
}

int main() {
    srand(time(NULL));
    printf("Starting firewall...\n");

    while (1) {
        char packet[MAX_PACKET_SIZE];
        printf("Enter packet data: ");
        fgets(packet, MAX_PACKET_SIZE, stdin);

        // Simulate packet analysis
        int pass = rand() % 2;
        if (pass == 0) {
            printf("Blocked!\n");
            continue;
        }

        // Extract IP address from packet
        char* token = strtok(packet, " ");
        while (token != NULL) {
            if (strstr(token, "src=") != NULL) {
                char* ip = strstr(token, "=") + 1;
                ip = strtok(ip, "\n");
                printf("Detected IP: %s\n", ip);

                // Check if IP is in block list
                if (search(ip) == 1) {
                    printf("Blocked!\n");
                    continue;
                }

                // Allow packet through
                printf("Passed!\n");

                // Add IP to pass list
                insert(ip);

                // Clean up old entries
                if (rand() % 4 == 0) {
                    printf("Cleaning up pass list...\n");
                    delete(head->ip);
                }

                break;
            }
            token = strtok(NULL, " ");
        }

        // Print pass list
        printf("Pass list:\n");
        printList();
    }
    
    return 0;
}