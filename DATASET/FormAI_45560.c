//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

void scan_wireless_networks() {
    int sockfd, on = 1, len;
    char buffer[2048];
    struct sockaddr_in serv;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("Cannot create socket.");
        exit(EXIT_FAILURE);
    }

    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(0);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on)) < 0) {
        perror("Cannot set socket options.");
        exit(EXIT_FAILURE);
    }

    if (bind(sockfd, (struct sockaddr*)&serv, sizeof(serv)) < 0) {
        perror("Cannot bind socket to port 0.");
        exit(EXIT_FAILURE);
    }

    struct timeval timeout = { 2, 0 };

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("Cannot set socket options.");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in send_addr;
    send_addr.sin_family = AF_INET;
    send_addr.sin_addr.s_addr = inet_addr("255.255.255.255");
    send_addr.sin_port = htons(5353);

    const char* packet = "\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x07\x5f\x64\x6e\x73\x2d\x73\x64\x04\x5f\x74\x63\x70\x05\x6c\x6f\x63\x61\x6c\x00\x00\x0c\x00\x01";

    len = sendto(sockfd, packet, strlen(packet), 0, (struct sockaddr*)&send_addr, sizeof(send_addr));
    if (len < 0) {
        perror("Cannot send packet.");
        exit(EXIT_FAILURE);
    }

    while ((len = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, 0)) > 0) {
        printf("Received %d bytes.\n", len);
        // Add your code to extract information from the buffer here...
    }

    close(sockfd);
}

int main() {
    scan_wireless_networks();
    return 0;
}