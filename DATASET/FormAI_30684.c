//FormAI DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define PORT 80 // Port number to ping
#define MSG_SIZE 64 // This is the message size for our ping request
#define MAX_TRIES 3 // Maximum number of times to retry a failed ping
#define TIMEOUT 1000 // Time in milliseconds to wait for response

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s ip_address\n", argv[0]);
        exit(1);
    }

    char *dest_ip = argv[1];
    int sockfd;
    struct sockaddr_in addr;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = TIMEOUT * 1000;
    char msg[MSG_SIZE];
    int seq = 0;
    int tries = 0;

    // Create socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set destination address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, dest_ip, &addr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    while (tries < MAX_TRIES) {
        // Create message
        memset(msg, '\0', sizeof(msg));
        sprintf(msg, "PING %d", seq);
        
        // Send message
        gettimeofday(&tv, NULL);
        sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&addr, sizeof(addr));

        // Wait for response
        memset(msg, '\0', sizeof(msg));
        socklen_t addr_len = sizeof(addr);
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv)) < 0) {
            perror("setsockopt error");
            exit(1);
        }
        int numbytes = recvfrom(sockfd, msg, MSG_SIZE, MSG_WAITALL, (struct sockaddr *)&addr, &addr_len);
        if (numbytes < 0) {
            printf("Timeout\n");
            tries++;
            continue;
        }

        // Print response
        printf("Received ping response from %s: %s\n", dest_ip, msg);
        tries = 0;
        seq++;

        // Wait for 1 second before sending the next ping request
        sleep(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}