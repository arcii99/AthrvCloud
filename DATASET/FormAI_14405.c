//FormAI DATASET v1.0 Category: Firewall ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if an incoming packet should be blocked or allowed
int check_packet(char* packet) {
    // Check for potential threats
    if (strstr(packet, "malware") != NULL || strstr(packet, "hack") != NULL || strstr(packet, "virus") != NULL) {
        return 0; // Block the packet
    }

    // Check for unauthorized access attempts
    if (strstr(packet, "Unauthorized") != NULL || strstr(packet, "access") != NULL || strstr(packet, "intrusion") != NULL) {
        return 0; // Block the packet
    }
    
    // Allow all other packets
    return 1;
}

int main() {
    char packet[100];
    int decision;
    
    // Continuously receive packets until user exits
    while(1) {
        // Receive packet from user
        printf("Enter packet contents: ");
        fgets(packet, 100, stdin);
        packet[strcspn(packet, "\n")] = 0; // Remove newline character
        
        // Check if packet should be allowed or blocked
        decision = check_packet(packet);
        
        // Output decision
        if (decision) {
            printf("Packet allowed.\n");
        } else {
            printf("Packet blocked.\n");
        }
    }
    
    return 0;
}