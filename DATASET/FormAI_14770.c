//FormAI DATASET v1.0 Category: Firewall ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants for packet types
#define TYPE_HTTP 1
#define TYPE_FTP 2
#define TYPE_SSH 3

// define constants for IP addresses
#define IP_ADDRESS_1 "192.168.1.1"
#define IP_ADDRESS_2 "192.168.1.2"
#define IP_ADDRESS_3 "192.168.1.3"

// data structure for a packet
typedef struct packet_t {
    int type;
    char source_ip[20];
    char destination_ip[20];
} packet;

// function that checks if a packet is allowed through the firewall
int allow_packet(packet *p) {
    if (strcmp(p->source_ip, IP_ADDRESS_1) == 0 && strcmp(p->destination_ip, IP_ADDRESS_2) == 0 && p->type == TYPE_HTTP) {
        return 1;
    } else if (strcmp(p->source_ip, IP_ADDRESS_2) == 0 && strcmp(p->destination_ip, IP_ADDRESS_3) == 0 && p->type == TYPE_FTP) {
        return 1;
    } else if (strcmp(p->source_ip, IP_ADDRESS_3) == 0 && strcmp(p->destination_ip, IP_ADDRESS_1) == 0 && p->type == TYPE_SSH) {
        return 1;
    } else {
        return 0;
    }
}

// main function
int main() {
    // create some test packets
    packet packet1 = { TYPE_HTTP, IP_ADDRESS_1, IP_ADDRESS_2 };
    packet packet2 = { TYPE_FTP, IP_ADDRESS_2, IP_ADDRESS_3 };
    packet packet3 = { TYPE_SSH, IP_ADDRESS_3, IP_ADDRESS_1 };
    packet packet4 = { TYPE_HTTP, IP_ADDRESS_2, IP_ADDRESS_1 };
    
    // check if packets are allowed through the firewall
    if (allow_packet(&packet1)) {
        printf("Packet 1: Allowed\n");
    } else {
        printf("Packet 1: Blocked\n");
    }
    
    if (allow_packet(&packet2)) {
        printf("Packet 2: Allowed\n");
    } else {
        printf("Packet 2: Blocked\n");
    }
    
    if (allow_packet(&packet3)) {
        printf("Packet 3: Allowed\n");
    } else {
        printf("Packet 3: Blocked\n");
    }
    
    if (allow_packet(&packet4)) {
        printf("Packet 4: Allowed\n");
    } else {
        printf("Packet 4: Blocked\n");
    }
    
    return 0;
}