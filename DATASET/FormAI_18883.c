//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define PORT 8888

char buffer[BUFFER_SIZE];

void *monitor_packets(void *arg) {
    int sockfd = *(int*) arg;
    struct sockaddr_in addr;
    int addr_len = sizeof(addr);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*) &addr, &addr_len);
        printf("Received packet from %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
        printf("Packet contents: %s\n", buffer);
    }
}

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    pthread_t packet_thread;
    if (pthread_create(&packet_thread, NULL, monitor_packets, &sockfd)) {
        perror("thread creation failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        sleep(1);
    }

    close(sockfd);
    return 0;
}