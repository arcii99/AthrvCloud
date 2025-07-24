//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <ctype.h>

#define BUFSIZE 1024
#define PORT 8080

// Defines the packet structure
struct packet {
    int seq_num;
    char data[BUFSIZE];
};

// Function to check if a given string is a valid IP address
int validate_ip(char *ip) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result == 1;
}

int main() {
    int sockfd;
    struct sockaddr_in server_address;
    char buffer[BUFSIZE];
    struct packet send_pkt, recv_pkt;
    int num_packets = 0;
    int total_bytes_sent = 0;
    int total_bytes_recv = 0;
    float avg_latency = 0.0;
    float avg_throughput = 0.0;
    int seq_num = 0;

    // Create socket
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if(!validate_ip("127.0.0.1")) {
        perror("Invalid IP address");
        exit(EXIT_FAILURE);
    }
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid IP address");
        exit(EXIT_FAILURE);
    }


    // Send packets to server
    printf("Sending packets to server...\n");
    while(1) {
        // Prepare packet
        send_pkt.seq_num = seq_num;
        for(int i = 0; i < BUFSIZE; i++)
            send_pkt.data[i] = 'a';

        // Send packet
        ssize_t num_sent_bytes = sendto(sockfd, &send_pkt, sizeof(send_pkt), 0, (const struct sockaddr *) &server_address, sizeof(server_address));
        if(num_sent_bytes < 0) {
            perror("Error sending packet");
            exit(EXIT_FAILURE);
        }
        else {
            total_bytes_sent += num_sent_bytes;
            num_packets++;
        }

        // Receive packet
        int len = sizeof(server_address);
        ssize_t num_recv_bytes = recvfrom(sockfd, &recv_pkt, sizeof(recv_pkt), MSG_WAITALL, (struct sockaddr *) &server_address, &len);
        if(num_recv_bytes < 0) {
            perror("Error receiving packet");
            exit(EXIT_FAILURE);
        }
        else {
            total_bytes_recv += num_recv_bytes;

            int t = num_recv_bytes / (sizeof(int) + sizeof(char) * BUFSIZE);
            for(int i = 0; i < t; i++) {
                // Calculate latency
                float latency = (float)(recv_pkt.seq_num - seq_num) / 1000.0;
                avg_latency += latency;

                // Calculate throughput
                float throughput = (float)BUFSIZE / (float)latency;
                avg_throughput += throughput;

                seq_num = recv_pkt.seq_num;
            }
        }

        // Wait for 1 second before sending next packet
        sleep(1);
    }

    // Calculate average latency and throughput
    avg_latency /= num_packets;
    avg_throughput /= num_packets;

    printf("Total number of packets sent: %d\n", num_packets);
    printf("Total number of bytes sent: %d\n", total_bytes_sent);
    printf("Total number of bytes received: %d\n", total_bytes_recv);
    printf("Average latency: %f\n", avg_latency);
    printf("Average throughput: %f\n", avg_throughput);

    return 0;
}