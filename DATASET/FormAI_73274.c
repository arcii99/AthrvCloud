//FormAI DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKED_IPS "blocked_ips.txt" // The path to the file containing blocked IPs

int main() {
    FILE *file;
    char blocked_ip[16];
    char ip[16];
    int is_blocked = 0;

    // Get input from user
    printf("Enter an IP address: ");
    fgets(ip, 16, stdin);
    ip[strlen(ip) - 1] = '\0'; // Remove newline character

    // Open file containing blocked IPs
    file = fopen(BLOCKED_IPS, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Check if input IP is blocked
    while (fgets(blocked_ip, 16, file) != NULL) {
        if (strncmp(ip, blocked_ip, strlen(blocked_ip) - 1) == 0) {
            printf("Access denied: IP address %s is blocked.\n", ip);
            is_blocked = 1;
            break;
        }
    }

    // Close file
    fclose(file);

    // If input IP is not blocked, allow access
    if (!is_blocked) {
        printf("Access granted: IP address %s is not blocked.\n", ip);
    }

    return 0;
}