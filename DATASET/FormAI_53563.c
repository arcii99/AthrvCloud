//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Packet {
    int source_ip;
    int destination_ip;
    char payload[100];
};

void analyzePacket(struct Packet packet) {
    // Example intrusion detection rule:
    // If payload contains the string "hack", consider it a potential intrusion
    if (strstr(packet.payload, "hack")) {
        printf("Potential intrusion detected from %d to %d!\n", packet.source_ip, packet.destination_ip);
        // Add code here to take action on the potential intrusion (e.g. log it, block the source IP)
    } else {
        printf("No intrusion detected in packet from %d to %d.\n", packet.source_ip, packet.destination_ip);
    }
}

int main() {
    // Example network traffic simulation: receive packets and analyze them
    struct Packet packet1 = {
        .source_ip = 192168001,
        .destination_ip = 192168002,
        .payload = "This is a normal packet",
    };
    analyzePacket(packet1);

    struct Packet packet2 = {
        .source_ip = 192168003,
        .destination_ip = 192168004,
        .payload = "This packet contains a hack!",
    };
    analyzePacket(packet2);

    return 0;
}