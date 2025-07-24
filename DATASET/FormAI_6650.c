//FormAI DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define allowed IPs
char* allowed_ips[] = {"127.0.0.1", "192.168.1.1", "10.0.0.1"};

// Define blocking time for malicious IPs
int block_time = 300; // 5 minutes

// Define max attempts before blocking IP
int max_attempts = 3;

// Define IP attempts struct
typedef struct {
    char* ip;
    time_t last_attempt;
    int count;
    bool blocked;
} ip_attempt;

// Initialize empty attempts array
ip_attempt attempts[1000];
int attempts_count = 0;

// Check if IP is allowed
bool is_allowed(char* ip) {
    int i, n = sizeof(allowed_ips) / sizeof(allowed_ips[0]);
    for (i = 0; i < n; i++) {
        if (strcmp(ip, allowed_ips[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Check if IP is blocked
bool is_blocked(char* ip) {
    int i;
    for (i = 0; i < attempts_count; i++) {
        if (strcmp(ip, attempts[i].ip) == 0 && attempts[i].blocked) {
            time_t now = time(NULL);
            if (now - attempts[i].last_attempt < block_time) {
                return true;
            } else {
                attempts[i].blocked = false;
                attempts[i].count = 0;
                return false;
            }
        }
    }
    return false;
}

// Block IP
void block_ip(char* ip) {
    int i;
    for (i = 0; i < attempts_count; i++) {
        if (strcmp(ip, attempts[i].ip) == 0) {
            attempts[i].blocked = true;
            attempts[i].last_attempt = time(NULL);
            printf("Blocked IP: %s\n", ip);
            break;
        }
    }
}

int main() {
    printf("Welcome to the Firewall!\n");

    char input[20];
    while (1) {
        printf("\nEnter IP address: ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        printf("Checking IP: %s\n", input);

        if (is_allowed(input)) {
            printf("Access Granted!\n");
        } else if (is_blocked(input)) {
            printf("IP blocked. Please try again later.\n");
        } else {
            int i;
            for (i = 0; i < attempts_count; i++) {
                if (strcmp(input, attempts[i].ip) == 0) {
                    attempts[i].count++;
                    if (attempts[i].count >= max_attempts) {
                        block_ip(input);
                    }
                    break;
                }
            }
            if (i == attempts_count) {
                attempts[attempts_count].ip = strdup(input);
                attempts[attempts_count].last_attempt = time(NULL);
                attempts[attempts_count].count = 1;
                attempts[attempts_count].blocked = false;
                attempts_count++;
            }
            printf("Access Denied!\n");
        }
    }
    return 0;
}