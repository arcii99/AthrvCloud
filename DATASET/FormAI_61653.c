//FormAI DATASET v1.0 Category: Firewall ; Style: careful
#define ALLOWED_IP "10.0.0.1" // Edit this to the allowed IP address

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[16];
    printf("Enter IP Address : ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove trailing newline character

    if (strcmp(ip, ALLOWED_IP) == 0) { // If IP address matches the allowed IP
        printf("Access granted!\n");
    } else {
        printf("Access denied!\n");
    }

    return 0;
}