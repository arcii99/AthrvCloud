//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024
#define MAX_IP_SIZE 16

// Simple packet structure
struct packet {
    char source_ip[MAX_IP_SIZE];
    char dest_ip[MAX_IP_SIZE];
    char data[MAX_PACKET_SIZE];
};

// Function to check if the source IP is blacklisted
int is_blacklisted(char *source_ip) {
    char *blacklist[] = {"192.168.0.1", "10.0.0.1", "127.0.0.1"};
    int i;
    for (i = 0; i < sizeof(blacklist)/sizeof(blacklist[0]); i++) {
        if (strcmp(source_ip, blacklist[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to handle incoming packets
void handle_packet(struct packet p) {
    printf("Packet received from %s to %s\n", p.source_ip, p.dest_ip);

    if (is_blacklisted(p.source_ip)) {
        printf("WARNING: Incoming traffic from %s is not allowed!\n", p.source_ip);
    } else {
        printf("Processing packet data...\n");
        // Insert code here to process packet data
    }
}

int main() {
    printf("Starting Intrusion Detection System...\n");

    // Simulate incoming packets
    struct packet p1 = {
        .source_ip = "192.168.1.100",
        .dest_ip = "10.0.0.1",
        .data = "Packet data goes here"
    };
    handle_packet(p1);

    struct packet p2 = {
        .source_ip = "10.0.0.2",
        .dest_ip = "192.168.1.100",
        .data = "Another packet data"
    };
    handle_packet(p2);

    struct packet p3 = {
        .source_ip = "127.0.0.1",
        .dest_ip = "10.0.0.1",
        .data = "Third packet data"
    };
    handle_packet(p3);

    printf("Shutting down...\n");

    return 0;
}