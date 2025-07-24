//FormAI DATASET v1.0 Category: Firewall ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define macro for maximum packet size allowed
#define MAX_PACKET_SIZE 1024

// Function to check whether the packet should be allowed through the firewall
int firewall(char *packet) {
    // Check packet size limit
    if (strlen(packet) > MAX_PACKET_SIZE) {
        printf("Packet size exceeded limit! Packet dropped.\n");
        return 0;
    }

    // Check for malicious content
    if (strstr(packet, "malware") != NULL || strstr(packet, "virus") != NULL) {
        printf("Malicious packet detected! Packet dropped.\n");
        return 0;
    }

    // Check for allowed content
    if (strstr(packet, "allowed") != NULL) {
        printf("Allowed packet detected! Packet passed through firewall.\n");
        return 1;
    }

    // Default action
    printf("Unknown packet detected! Packet dropped.\n");
    return 0;
}

// Main function to test the firewall
int main() {
    char packet[MAX_PACKET_SIZE];

    // Get user input packet
    printf("Enter a packet: ");
    fgets(packet, MAX_PACKET_SIZE, stdin);

    // Remove newline character from packet
    packet[strcspn(packet, "\n")] = 0;

    // Run packet through firewall
    int allowed = firewall(packet);

    // Display result
    if (allowed) {
        printf("Packet was allowed through firewall.\n");
    } else {
        printf("Packet was dropped by firewall.\n");
    }

    return 0;
}