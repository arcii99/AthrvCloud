//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

typedef struct Packet_Header {
    int source_ip;
    int dest_ip;
    int protocol;
} Packet_Header;

typedef struct Packet {
    int size;
    Packet_Header header;
    char data[MAX_PACKET_SIZE];
} Packet;

typedef struct {
    int ip;
    int num_packets;
} Host;

Host arr_hosts[10];

void log_packet(Packet packet) {
    printf("PACKET LOG:\n");
    printf("Size: %d\n", packet.size);
    printf("Source IP: %d\n", packet.header.source_ip);
    printf("Destination IP: %d\n", packet.header.dest_ip);
    printf("Protocol: %d\n", packet.header.protocol);
    printf("Data: %s\n\n", packet.data);
}

int calculate_hash(int ip) {
    return ip % 10;
}

void add_host_packet(Packet packet) {
    int hash = calculate_hash(packet.header.dest_ip);
    arr_hosts[hash].ip = packet.header.dest_ip;
    arr_hosts[hash].num_packets++;
}

void check_for_intrusion(Packet packet) {
    int hash = calculate_hash(packet.header.dest_ip);
    if (arr_hosts[hash].num_packets > 50 && arr_hosts[hash].ip == packet.header.dest_ip) {
        printf("INTRUSION DETECTED! %d packets sent to IP address %d in a short period of time\n", arr_hosts[hash].num_packets, packet.header.dest_ip);
        exit(0);
    } else {
        arr_hosts[hash].num_packets = 0;
    }
}

int main() {
    Packet packet1 = {
        .size = 128,
        .header = {
            .source_ip = 123456,
            .dest_ip = 789012,
            .protocol = 1
        },
        .data = "This is a test packet"
    };
    Packet packet2 = {
        .size = 256,
        .header = {
            .source_ip = 345678,
            .dest_ip = 901234,
            .protocol = 2
        },
        .data = "This is another test packet"
    };
    
    // Log packets
    log_packet(packet1);
    log_packet(packet2);
    
    // Add packets to host list and check for intrusion
    add_host_packet(packet1);
    add_host_packet(packet2);
    check_for_intrusion(packet2);
    
    return 0;
}