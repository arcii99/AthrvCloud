//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants */
#define MAX_PACKET_SIZE 1024
#define MAX_IP_LEN 16

/* Define struct for storing network packets */
typedef struct packet_t {
    char source_ip[MAX_IP_LEN];
    char destination_ip[MAX_IP_LEN];
    int packet_size;
    int priority;
} packet;

/* Declare function for calculating network usage */
float calculate_network_usage(packet packets[], int num_packets) {
    int total_size = 0;
    for (int i = 0; i < num_packets; i++) {
        total_size += packets[i].packet_size;
    }
    float usage = (float) total_size / MAX_PACKET_SIZE * 100;
    return usage;
}

/* Declare function for monitoring network QoS */
void monitor_network_qos(packet packets[], int num_packets) {
    int high_priority = 0;
    int medium_priority = 0;
    int low_priority = 0;
    int total_packets = 0;

    /* Count number of packets for each priority level */
    for (int i = 0; i < num_packets; i++) {
        if (packets[i].priority == 1) {
            high_priority++;
        } else if (packets[i].priority == 2) {
            medium_priority++;
        } else if (packets[i].priority == 3) {
            low_priority++;
        }
    }
    total_packets = high_priority + medium_priority + low_priority;

    /* Display QoS metrics */
    printf("\n\n-------------------------------------\n\n");
    printf("Network QoS Metrics:\n\n");
    printf("Total Packets: %d\n", total_packets);
    printf("High Priority Packets: %d\n", high_priority);
    printf("Medium Priority Packets: %d\n", medium_priority);
    printf("Low Priority Packets: %d\n", low_priority);
    printf("Network Usage: %.2f%%\n\n", calculate_network_usage(packets, num_packets));
}

int main() {
    packet packets[5];

    /* Initialize packets */
    strcpy(packets[0].source_ip, "192.168.0.1");
    strcpy(packets[0].destination_ip, "10.10.0.1");
    packets[0].packet_size = 512;
    packets[0].priority = 1;

    strcpy(packets[1].source_ip, "10.10.0.1");
    strcpy(packets[1].destination_ip, "192.168.0.1");
    packets[1].packet_size = 256;
    packets[1].priority = 2;

    strcpy(packets[2].source_ip, "192.168.0.1");
    strcpy(packets[2].destination_ip, "10.10.0.1");
    packets[2].packet_size = 128;
    packets[2].priority = 3;

    strcpy(packets[3].source_ip, "10.10.0.1");
    strcpy(packets[3].destination_ip, "192.168.0.1");
    packets[3].packet_size = 64;
    packets[3].priority = 1;

    strcpy(packets[4].source_ip, "192.168.0.1");
    strcpy(packets[4].destination_ip, "10.10.0.1");
    packets[4].packet_size = 32;
    packets[4].priority = 2;

    /* Monitor network QoS */
    monitor_network_qos(packets, 5);

    return 0;
}