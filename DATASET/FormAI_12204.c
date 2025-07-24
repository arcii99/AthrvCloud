//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 4096
#define MAX_SAMPLES 100

typedef struct {
    int seq;
    double rtt;
} ping_sample_t;

void send_ping(int sockfd, struct sockaddr_in *addr, int seq) {
    char buffer[MAX_PACKET_SIZE] = {0};
    struct timespec start, end;
    ping_sample_t sample;
    
    // Create ICMP echo request
    buffer[0] = 0x08; // Type: Echo Request
    buffer[1] = 0x00; // Code: 0
    buffer[2] = 0x00; // Checksum (set later)
    buffer[3] = 0x00; // Checksum (set later)
    buffer[4] = 0x00; // Identifier (arbitrary)
    buffer[5] = 0x00; // Identifier (arbitrary)
    buffer[6] = seq >> 8; // Sequence number (upper 8 bits)
    buffer[7] = seq & 0xFF; // Sequence number (lower 8 bits)
    
    // Calculate checksum
    unsigned int checksum = 0;
    for (int i = 0; i < 8; i += 2) {
        checksum += buffer[i] << 8 | buffer[i+1];
    }
    checksum = ~((checksum & 0xFFFF) + (checksum >> 16));
    buffer[2] = checksum >> 8;
    buffer[3] = checksum & 0xFF;
    
    // Send ICMP echo request
    clock_gettime(CLOCK_MONOTONIC, &start);
    ssize_t bytes_sent = sendto(sockfd, buffer, 8, 0, (struct sockaddr *)addr, sizeof(struct sockaddr_in));
    if (bytes_sent < 0) {
        perror("sendto() error");
        return;
    }
    
    // Receive ICMP echo reply
    socket_timeout(sockfd, 1); // Wait up to 1 second for reply
    ssize_t bytes_received = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, NULL, NULL);
    if (bytes_received < 0) {
        printf("Seq %d: Request timed out\n", seq);
        return;
    }
    
    // Parse ICMP echo reply
    clock_gettime(CLOCK_MONOTONIC, &end);
    sample.seq = (buffer[6] << 8) | buffer[7];
    sample.rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
    printf("Seq %d: RTT = %.2f ms\n", sample.seq, sample.rtt);
}

void socket_timeout(int sockfd, int seconds) {
    struct timeval timeout = {seconds, 0};
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt() error");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in dest_addr = {0};
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(1); // Arbitrary port
    if (inet_pton(AF_INET, argv[1], &dest_addr.sin_addr) <= 0) {
        perror("inet_pton() error");
        exit(EXIT_FAILURE);
    }
    
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }
    
    ping_sample_t samples[MAX_SAMPLES] = {0};
    int seq = 0;
    while (seq < MAX_SAMPLES) {
        send_ping(sockfd, &dest_addr, seq);
        seq++;
    }
    
    close(sockfd);
    
    return 0;
}