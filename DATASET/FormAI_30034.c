//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1024

typedef struct {
    int src_port;
    int dest_port;
    char data[MAX_PACKET_SIZE];
} Packet;

void monitorQoS(Packet *pkt) {
    bool low_qos = false;
    // check if packet size exceeds limit
    if (strlen(pkt->data) > MAX_PACKET_SIZE) {
        low_qos = true;
    }
    // check if source port is within range
    if (pkt->src_port < 1024 || pkt->src_port > 49151) {
        low_qos = true;
    }
    // check if destination port is within range
    if (pkt->dest_port < 49152 || pkt->dest_port > 65535) {
        low_qos = true;
    }
    // if low quality of service is detected, print warning message
    if (low_qos) {
        printf("Warning: Packet with low quality of service detected!\n");
    }
}

int main() {
    Packet pkt1, pkt2;
    // initialize packet 1
    pkt1.src_port = 1234;
    pkt1.dest_port = 5678;
    strcpy(pkt1.data, "This is a sample packet.");
    // initialize packet 2
    pkt2.src_port = 9999;
    pkt2.dest_port = 8888;
    strcpy(pkt2.data, "This packet contains too much data and will be dropped due to low QoS.");

    // monitor quality of service for both packets
    monitorQoS(&pkt1);
    monitorQoS(&pkt2);

    printf("Program execution completed.\n");
    return 0;
}