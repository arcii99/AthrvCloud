//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

struct Packet {
    int src_port;
    int dest_port;
    char data[MAX_PACKET_SIZE];
};

struct Rule {
    int src_port;
    int dest_port;
};

int main() {
    // Define rules
    struct Rule rules[3];
    rules[0].src_port = 80;
    rules[0].dest_port = 8080;
    rules[1].src_port = 22;
    rules[1].dest_port = 5000;
    rules[2].src_port = 53;
    rules[2].dest_port = 53;

    // Start listening for incoming packets
    printf("Listening for packets...\n");
    while (1) {
        // Simulate receiving a packet
        struct Packet packet;
        packet.src_port = 80;
        packet.dest_port = 8080;
        strcpy(packet.data, "Hello World!");

        // Check if packet matches any rule
        int match_found = 0;
        int i;
        for (i = 0; i < 3; i++) {
            if (packet.src_port == rules[i].src_port && packet.dest_port == rules[i].dest_port) {
                match_found = 1;
                break;
            }
        }

        // If no match found, possible intrusion detected
        if (!match_found) {
            printf("Possible intrusion detected! Packet from port %d to port %d\n", packet.src_port, packet.dest_port);
        }
    }

    return 0;
}