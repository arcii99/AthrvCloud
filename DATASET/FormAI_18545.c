//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_PACKET_SIZE 1024
#define MAX_PENDING_PACKETS 10

int main() {
    // Initialization
    int pending_packet_count = 0;
    char pending_packets[MAX_PENDING_PACKETS][MAX_PACKET_SIZE];
    
    printf("Intrusion Detection System Initialized\n\n");
    
    // Receiving Packets
    while(1) {
        char incoming_packet[MAX_PACKET_SIZE];
        
        printf("Waiting for Incoming Packet...\n\n");
        // Code to receive incoming packet and store it in incoming_packet variable
        
        // Check if packet is suspicious
        int suspicious = 0;
        if (incoming_packet[0] == 'M' && incoming_packet[1] == 'A' && incoming_packet[2] == 'L') {
            printf("Alert! Suspicious packet detected!\n\n");
            suspicious = 1;
        }
        
        // Store packet in pending packets queue if not suspicious
        if (!suspicious) {
            if (pending_packet_count == MAX_PENDING_PACKETS) {
                // Remove oldest packet
                for(int i=1; i<MAX_PENDING_PACKETS; i++) {
                    strcpy(pending_packets[i-1], pending_packets[i]);
                }
                pending_packet_count--;
            }
            
            printf("Packet Stored in Pending Packets Queue\n\n");
            strcpy(pending_packets[pending_packet_count], incoming_packet);
            pending_packet_count++;
        }
        
        // Check if any packet in pending packet queue matches the suspicious pattern
        int found_suspicious = -1;
        for(int i=0; i<pending_packet_count; i++) {
            if (strstr(pending_packets[i], "MALICIOUS_CONTENT")) {
                found_suspicious = i;
                break;
            }
        }
        
        // Alert if suspicious packet found in pending packet queue
        if (found_suspicious > -1) {
            printf("Alert! Suspicious Pattern Detected in Pending Packets Queue\n\n");
            pending_packet_count--;
            for(int i=found_suspicious; i<pending_packet_count; i++) {
                strcpy(pending_packets[i], pending_packets[i+1]);
            }
        }
        
        // Sleep for 1 second before listening for next packet
        sleep(1);
    }
    
    return 0;
}