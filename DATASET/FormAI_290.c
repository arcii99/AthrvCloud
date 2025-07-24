//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

typedef struct packet {
    char data[MAX_PACKET_SIZE];
} packet_t;

int main() {
    // Set up memory
    packet_t* packet = (packet_t*)malloc(sizeof(packet_t));
    memset(packet, 0, sizeof(packet_t));

    // Wait for a packet to arrive
    printf("Waiting for packet...\n");
    // In a real IDS system, you would be listening on a socket for incoming packets
    // but for this example we are simply going to simulate it with fgets
    fgets(packet->data, MAX_PACKET_SIZE, stdin);

    // Now that we have the packet, we need to check it for intrusion attempts
    int i;
    for (i = 0; i < MAX_PACKET_SIZE-1 && packet->data[i] != 0; i++) {
        if (packet->data[i] == 'h' && packet->data[i+1] == 'a' && packet->data[i+2] == 'c' && packet->data[i+3] == 'k') {
            printf("Intrusion attempt detected.\n");
            break;
        }
    }

    // Clean up
    free(packet);
    return 0;
}