//FormAI DATASET v1.0 Category: Firewall ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

struct packet {
    char source_ip[16], destination_ip[16], protocol[4];
    int source_port, destination_port;
};

int main() {
    struct packet pkt;
    
    printf("Enter source IP address: ");
    scanf("%s", pkt.source_ip);
    
    printf("Enter destination IP address: ");
    scanf("%s", pkt.destination_ip);
    
    printf("Enter protocol: ");
    scanf("%s", pkt.protocol);
    
    printf("Enter source port: ");
    scanf("%d", &pkt.source_port);
    
    printf("Enter destination port: ");
    scanf("%d", &pkt.destination_port);
    
    // Check if the packet should be blocked
    if (strcmp(pkt.source_ip, "10.0.0.1") == 0 && strcmp(pkt.destination_ip, "192.168.1.1") == 0 && strcmp(pkt.protocol, "TCP") == 0 && pkt.destination_port == 80) {
        printf("Packet blocked!\n");
    } else {
        printf("Packet allowed.\n");
    }
    
    return 0;
}