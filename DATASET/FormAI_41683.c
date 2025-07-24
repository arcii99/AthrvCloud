//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

int main() {
    int sock_fd, recv_bytes, sock_addr_len, exit_condition = 0;
    unsigned char buffer[65536]; // Buffer to store incoming packets
    struct sockaddr_in source_address; // Structure to hold source IP and port
    sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP); // Creating raw socket

    if (sock_fd < 0) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    while(!exit_condition) {
        sock_addr_len = sizeof(source_address);

        memset(buffer, 0, sizeof(buffer)); // Clearing buffer

        recv_bytes = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&source_address, &sock_addr_len); // Receiving packet

        if(recv_bytes < 0) {
            perror("recvfrom() error");
            exit(EXIT_FAILURE);
        } else {
            printf("Received %d bytes of network packet from %s:%d\n", recv_bytes, inet_ntoa(source_address.sin_addr), ntohs(source_address.sin_port));

            /* Add your monitoring logic here.
               This could include checking the protocol type, source/destination IP/port,
               packet payload inspection, logging, alerting, etc. */
        }
    }

    close(sock_fd);
    return 0;
}