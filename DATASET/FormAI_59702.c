//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>

// Structure to represent a network packet
typedef struct Packet {
    int source_ip;
    int destination_ip;
    int size;
    char payload[100];
} Packet;

// Function to check for intrusion
int check_for_intrusion(Packet* packet) {
    if(packet->size > 1000) {
        printf("Intrusion detected: Packet size exceeds the limit.\n");
        return 1;
    }
    if(packet->payload[0] == 's' && packet->payload[1] == 'h') {
        printf("Intrusion detected: Malicious payload detected.\n");
        return 1;
    }
    return 0;
}

// Function to recursively process packets
void process_packet(Packet* packet) {
    int intrusion_detected = check_for_intrusion(packet);
    if(intrusion_detected) {
        // Take necessary action here
        return;
    }
    // Do some processing with the packet here

    // Create a new packet and process it recursively
    Packet new_packet;
    new_packet.source_ip = packet->destination_ip;
    new_packet.destination_ip = packet->source_ip;
    new_packet.size = 200;
    sprintf(new_packet.payload, "Hello from %d to %d", new_packet.source_ip, new_packet.destination_ip);

    process_packet(&new_packet);
}

int main() {
    Packet packet;
    packet.source_ip = 19216811;
    packet.destination_ip = 19216812;
    packet.size = 500;
    sprintf(packet.payload, "This is a test packet");

    // Process the packet recursively
    process_packet(&packet);

    return 0;
}