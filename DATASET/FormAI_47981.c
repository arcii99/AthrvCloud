//FormAI DATASET v1.0 Category: Firewall ; Style: Claude Shannon
// Claude Shannon-style Firewall Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024
#define MAX_RULES 100

typedef struct {
    int src_port;
    int dst_port;
    char src_ip[16];
    char dst_ip[16];
    char protocol[10];
} Rule;

int main() {
    Rule firewall_rules[MAX_RULES];
    int num_rules = 0;
    char packet[MAX_PACKET_SIZE];
    int packet_size = 0;
    int i, j;

    // Add some initial rules to the firewall
    strcpy(firewall_rules[0].src_ip, "192.168.1.0");
    strcpy(firewall_rules[0].dst_ip, "192.168.2.0");
    strcpy(firewall_rules[0].protocol, "TCP");
    firewall_rules[0].src_port = 1024;
    firewall_rules[0].dst_port = 80;

    strcpy(firewall_rules[1].src_ip, "192.168.1.0");
    strcpy(firewall_rules[1].dst_ip, "192.168.3.0");
    strcpy(firewall_rules[1].protocol, "UDP");
    firewall_rules[1].src_port = 1024;
    firewall_rules[1].dst_port = 53;

    num_rules = 2;

    // Get a packet from the network
    printf("Enter a packet to check against the firewall:\n");
    fgets(packet, MAX_PACKET_SIZE, stdin);
    packet_size = strlen(packet);

    // Check the packet against each rule in the firewall
    for (i = 0; i < num_rules; i++) {
        if (strcmp(firewall_rules[i].protocol, "TCP") == 0) { // Check for TCP packets
            if (packet_size >= sizeof(firewall_rules[i]) && 
                strncmp(packet, firewall_rules[i].src_ip, strlen(firewall_rules[i].src_ip)) == 0 &&
                strncmp(packet + strlen(firewall_rules[i].src_ip), firewall_rules[i].dst_ip, strlen(firewall_rules[i].dst_ip)) == 0 &&
                *(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip)) == ' ' &&
                strncmp(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 1, "TCP", 3) == 0 &&
                *(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 5) == ' ' &&
                atoi(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 6) == firewall_rules[i].src_port &&
                *(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 11) == ' ' &&
                atoi(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 12) == firewall_rules[i].dst_port) {
                    printf("Packet matches rule %d!\n", i);
                    exit(0);
            }
        }
        else if (strcmp(firewall_rules[i].protocol, "UDP") == 0) { // Check for UDP packets
            if (packet_size >= sizeof(firewall_rules[i]) &&
                strncmp(packet, firewall_rules[i].src_ip, strlen(firewall_rules[i].src_ip)) == 0 &&
                strncmp(packet + strlen(firewall_rules[i].src_ip), firewall_rules[i].dst_ip, strlen(firewall_rules[i].dst_ip)) == 0 &&
                *(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip)) == ' ' &&
                strncmp(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 1, "UDP", 3) == 0 &&
                *(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 5) == ' ' &&
                atoi(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 6) == firewall_rules[i].src_port &&
                *(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 11) == ' ' &&
                atoi(packet + strlen(firewall_rules[i].src_ip) + strlen(firewall_rules[i].dst_ip) + 12) == firewall_rules[i].dst_port) {
                    printf("Packet matches rule %d!\n", i);
                    exit(0);
            }
        }
    }

    printf("No rule matched the packet.\n");

    return 0;
}