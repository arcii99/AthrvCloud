//FormAI DATASET v1.0 Category: Firewall ; Style: authentic
/* A Unique C Firewall Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024
#define ALLOWED 0
#define BLOCKED 1

// Structure to hold packet information
struct packet {
    char *ip_address;
    int port_number;
    char data[MAX_PACKET_SIZE];
};

// Function to check if IP and port are allowed
int check_ip_port(struct packet *pkt) {
    char *allowed_ips[] = {"10.0.0.1", "192.168.1.10", "127.0.0.1", "192.168.1.11"};
    int allowed_ports[] = {80, 443, 22};
    int i, j;

    // Check if IP is allowed
    for (i = 0; i < sizeof(allowed_ips)/sizeof(allowed_ips[0]); i++) {
        if (strcmp(pkt->ip_address, allowed_ips[i]) == 0) {
            break;
        }
    }
    if (i == sizeof(allowed_ips)/sizeof(allowed_ips[0])) {
        return BLOCKED;
    }

    // Check if port is allowed
    for (j = 0; j < sizeof(allowed_ports)/sizeof(allowed_ports[0]); j++) {
        if (pkt->port_number == allowed_ports[j]) {
            break;
        }
    }
    if (j == sizeof(allowed_ports)/sizeof(allowed_ports[0])) {
        return BLOCKED;
    }

    // IP and port are both allowed
    return ALLOWED;
}

int main() {
    struct packet pkt;

    pkt.ip_address = "192.168.1.11";
    pkt.port_number = 80;
    strcpy(pkt.data, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");

    if (check_ip_port(&pkt) == ALLOWED) {
        printf("Packet allowed\n");
    } else {
        printf("Packet blocked\n");
    }

    return 0;
}