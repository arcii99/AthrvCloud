//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFSIZE 4096

// Struct for storing network quality of service metrics
typedef struct {
    double latency;
    double packet_loss;
    double jitter;
} QoS_metrics;

// Function to calculate QoS metrics for a given IP address
QoS_metrics calculate_QoS_metrics(char *ip_address) {
    QoS_metrics metrics;

    // Create socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket.\n");
        exit(1);
    }

    // Set socket timeout to 2 seconds
    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        fprintf(stderr, "Error: Failed to set socket timeout.\n");
        exit(1);
    }

    // Determine destination address
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(7);
    if (inet_aton(ip_address, &dest_addr.sin_addr) == 0) {
        fprintf(stderr, "Error: Invalid IP address.\n");
        exit(1);
    }

    // Generate random data
    char data[BUFSIZE];
    for (int i = 0; i < BUFSIZE; i++) {
        data[i] = rand() % 256;
    }

    // Ping destination address and measure latency and packet loss
    double total_latency = 0;
    int packets_sent = 0;
    int packets_received = 0;
    int lost_packets = 0;
    for (int i = 0; i < 10; i++) {
        // Send message to dest_addr
        if (sendto(sockfd, data, BUFSIZE, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
            fprintf(stderr, "Error: Failed to send message.\n");
            exit(1);
        }
        packets_sent++;

        // Receive message from dest_addr
        char recv_buf[BUFSIZE];
        socklen_t addr_len = sizeof(dest_addr);
        int bytes_received = recvfrom(sockfd, recv_buf, BUFSIZE, 0, (struct sockaddr *)&dest_addr, &addr_len);
        if (bytes_received < 0) {
            lost_packets++;
        }
        else {
            packets_received++;
            double elapsed_time = (double)(clock()) / CLOCKS_PER_SEC;
            double packet_latency = elapsed_time - *((double *)recv_buf);
            total_latency += packet_latency;
        }
    }

    // Calculate latency and packet loss
    metrics.latency = total_latency / packets_received;
    metrics.packet_loss = ((double)lost_packets / packets_sent) * 100;

    // Calculate jitter
    double total_jitter = 0;
    for (int i = 0; i < 10; i++) {
        // Send message to dest_addr
        if (sendto(sockfd, data, BUFSIZE, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
            fprintf(stderr, "Error: Failed to send message.\n");
            exit(1);
        }

        // Receive message from dest_addr
        char recv_buf[BUFSIZE];
        socklen_t addr_len = sizeof(dest_addr);
        int bytes_received = recvfrom(sockfd, recv_buf, BUFSIZE, 0, (struct sockaddr *)&dest_addr, &addr_len);
        if (bytes_received >= 0) {
            double elapsed_time = (double)(clock()) / CLOCKS_PER_SEC;
            double packet_latency = elapsed_time - *((double *)recv_buf);
            if (i > 0) {
                double packet_jitter = abs(packet_latency - total_latency);
                total_jitter += packet_jitter;
            }
            total_latency += packet_latency;
        }
    }
    metrics.jitter = total_jitter / 9;

    // Close socket
    close(sockfd);

    return metrics;
}

// Main function to test QoS_metrics calculation
int main(void) {
    QoS_metrics metrics = calculate_QoS_metrics("192.168.1.1");
    printf("Latency: %f ms\nPacket Loss: %f%%\nJitter: %f ms\n", metrics.latency, metrics.packet_loss, metrics.jitter);
    return 0;
}