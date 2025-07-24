//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>
#include <stdbool.h>

// Function to check for suspicious activity on network
bool check_activity(char* packet) {
    // Check for known attack patterns in packet data
    if (strstr(packet, "root access")) {
        return true;
    }
    if (strstr(packet, "password hack")) {
        return true;
    }
    if (strstr(packet, "backdoor install")) {
        return true;
    }
    // If no suspicious activity detected, return false
    return false;
}

int main() {
    // Initialize intrusion detection system
    printf("Initializing intrusion detection system...\n");
    bool system_on = true;
    int total_packets_received = 0;
    int suspicious_packets_detected = 0;
    
    // Loop to continuously accept incoming network packets
    while (system_on) {
        // Simulate receiving packet from network
        char packet[] = "User attempted root access";
        total_packets_received++;
        
        // Check for suspicious activity in packet
        if (check_activity(packet)) {
            printf("Alert! Suspicious activity detected in packet #%d\n", total_packets_received);
            suspicious_packets_detected++;
        } else {
            printf("Packet #%d cleared for processing\n", total_packets_received);
        }
        
        // Check if predetermined number of packets has been received
        if (total_packets_received == 100) {
            printf("System shutting down. %d suspicious packets detected out of %d total packets.\n", suspicious_packets_detected, total_packets_received);
            system_on = false;
        }
    }
    
    // Exit program
    return 0;
}