//FormAI DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct packet {
    char source_address[15];
    char dest_address[15];
    char payload[1024];
} Packet;

void blockPacket(Packet packet) {
    printf("BLOCKED PACKET:\n");
    printf("Source Address: %s\n", packet.source_address);
    printf("Destination Address: %s\n", packet.dest_address);
    printf("Payload: %s\n", packet.payload);
}

void allowPacket(Packet packet) {
    printf("ALLOWED PACKET:\n");
    printf("Source Address: %s\n", packet.source_address);
    printf("Destination Address: %s\n", packet.dest_address);
    printf("Payload: %s\n", packet.payload);
}

int main() {
    // Define some sample packets for testing
    Packet packets[5];
    strcpy(packets[0].source_address, "192.168.0.1");
    strcpy(packets[0].dest_address, "8.8.8.8");
    strcpy(packets[0].payload, "Hello, world!");
    strcpy(packets[1].source_address, "10.0.0.1");
    strcpy(packets[1].dest_address, "10.0.0.2");
    strcpy(packets[1].payload, "This is a test packet.");
    strcpy(packets[2].source_address, "172.16.0.1");
    strcpy(packets[2].dest_address, "172.16.0.2");
    strcpy(packets[2].payload, "Packet payload goes here.");
    strcpy(packets[3].source_address, "192.168.1.1");
    strcpy(packets[3].dest_address, "192.168.1.2");
    strcpy(packets[3].payload, "Some data to transmit.");
    strcpy(packets[4].source_address, "10.10.10.10");
    strcpy(packets[4].dest_address, "9.9.9.9");
    strcpy(packets[4].payload, "More packet data.");

    // Define the firewall rules
    int numRules = 3;
    char *allowedSources[] = {"192.168.0.1", "10.0.0.1", "172.16.0.1"};
    char *blockedDestinations[] = {"9.9.9.9"};

    // Check each packet against the firewall rules
    int i;
    for (i = 0; i < 5; i++) {
        Packet currPacket = packets[i];
        int j;

        // Check if packet's source address is allowed
        int sourceAllowed = 0;
        for (j = 0; j < numRules; j++) {
            if (strcmp(currPacket.source_address, allowedSources[j]) == 0) {
                sourceAllowed = 1;
                break;
            }
        }

        // Check if packet's destination address is blocked
        int destBlocked = 0;
        for (j = 0; j < numRules; j++) {
            if (strcmp(currPacket.dest_address, blockedDestinations[j]) == 0) {
                destBlocked = 1;
                break;
            }
        }

        // Allow or block the packet based on the firewall rules
        if (sourceAllowed && !destBlocked) {
            allowPacket(currPacket);
        } else {
            blockPacket(currPacket);
        }
    }

    return 0;
}