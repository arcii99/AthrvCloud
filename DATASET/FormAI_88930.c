//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PACKETS 1000
#define MAX_PACKET_SIZE 1024

char packets[MAX_PACKETS][MAX_PACKET_SIZE];
bool intrusions[MAX_PACKETS];

int num_packets = 0;

void add_packet(char* packet) {
    if(num_packets < MAX_PACKETS) {
        strcpy(packets[num_packets], packet);
        num_packets++;
    } else {
        printf("Max packets reached, cannot add more!\n");
    }
}

bool find_intrusion(char* packet) {
    // Dummy check for demo purposes, replace with actual intrusion detection algorithm
    return strlen(packet) > 10;
}

void process_packets() {
    for(int i=0; i<num_packets; i++) {
        if(find_intrusion(packets[i])) {
            intrusions[i] = true;
            printf("Intrusion found in packet number %d\n", i+1);
        } else {
            intrusions[i] = false;
        }
    }
}

int main() {
    char packet[MAX_PACKET_SIZE];
    do {
        printf("Enter packet data (or type 'finish' to stop):\n");
        fgets(packet, MAX_PACKET_SIZE, stdin);
        if(strcmp(packet, "finish\n") != 0) {
            add_packet(packet);
        }
    } while(strcmp(packet, "finish\n") != 0);
    process_packets();
    return 0;
}