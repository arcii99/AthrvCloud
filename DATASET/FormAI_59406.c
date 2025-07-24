//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PACKET_SIZE 4096

// Define struct for packet header information
struct packet_header {
    struct iphdr iph;
    struct tcphdr tcph;
    char data[PACKET_SIZE];
};

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc != 2) {
        printf("Usage: %s <target IP address>\n", argv[0]);
        return -1;
    }

    // Setup raw socket and IP header fields
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        printf("Error creating socket\n");
        return -1;
    }
    struct sockaddr_in dest;
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(argv[1]);

    // Initialize QoS counters
    int good_packets = 0;
    int bad_packets = 0;

    // Begin infinite loop to receive packets
    while (1) {
        // Allocate packet buffer and receive packet
        char packet_buffer[sizeof(struct packet_header)];
        struct packet_header *packet = (struct packet_header *) packet_buffer;
        int packet_size = recv(sock, packet_buffer, sizeof(packet_buffer), 0);

        // Verify packet is TCP packet
        if (packet_size > 0 && packet->iph.protocol == IPPROTO_TCP) {
            // Verify packet destination is correct
            if (packet->iph.daddr == dest.sin_addr.s_addr) {
                // Calculate packet checksum
                unsigned short packet_sum = packet->tcph.check;
                packet->tcph.check = 0;
                unsigned short calculated_sum = 0;
                unsigned short *ip_bytes = (unsigned short *) &packet->iph;
                for (int i = 0; i < sizeof(packet->iph)/2; i++) {
                    calculated_sum += ntohs(*(ip_bytes+i));
                }
                unsigned short *tcp_bytes = (unsigned short *) packet;
                for (int i = 0; i < sizeof(packet->tcph)/2; i++) {
                    calculated_sum += ntohs(*(tcp_bytes+i));
                }
                calculated_sum += PACKET_SIZE;
                calculated_sum = (calculated_sum >> 16) + (calculated_sum & 0xFFFF);
                calculated_sum += (calculated_sum >> 16);
                calculated_sum = ~calculated_sum;
                
                // Check if packet checksum is correct and update QoS counters
                if (packet_sum == calculated_sum) {
                    good_packets += 1;
                } else {
                    bad_packets += 1;
                }
                
                // Output QoS statistics every 10 packets
                if ((good_packets + bad_packets) % 10 == 0) {
                    printf("Good packets: %d\n", good_packets);
                    printf("Bad packets: %d\n", bad_packets);
                    printf("QoS: %f%%\n", (float) good_packets / (good_packets + bad_packets) * 100);
                }
            }
        }
    }

    // Close socket
    close(sock);

    return 0;
}