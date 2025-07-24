//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void scan_network_for_devices(void);

int main(void) {
    scan_network_for_devices();
    return 0;
}

void scan_network_for_devices(void) {
    int PORT = 80; // Default port
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    const char* broadcastaddr = "192.168.1.255"; // Broadcasting IP address
    struct sockaddr_in broadcast_address;
    broadcast_address.sin_family = AF_INET;
    broadcast_address.sin_addr.s_addr = inet_addr(broadcastaddr); // Convert IP address to binary format
    broadcast_address.sin_port = htons(PORT); // htons converts endianness

    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast_address, sizeof(broadcast_address)) < 0) {
        perror("setting socket option");
        exit(EXIT_FAILURE);
    }

    char message[] = "Who is there?\n"; // Message to broadcast
    ssize_t bytes_sent = sendto(sock, message, sizeof(message), 0, (struct sockaddr*)&broadcast_address, sizeof(broadcast_address));

    if (bytes_sent < 0) {
        perror("error sending message");
        exit(EXIT_FAILURE);
    } else {
        printf("Broadcast message sent successfully\n");
    }

    struct sockaddr_in remote_address; // Remote device address
    char buffer[1024];
    int len = sizeof(remote_address);
    ssize_t bytes_received = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&remote_address, &len);

    if (bytes_received < 0) {
        perror("error receiving message");
        exit(EXIT_FAILURE);
    } else {
        char remote_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(remote_address.sin_addr), remote_ip, INET_ADDRSTRLEN); // Convert IP address to string
        printf("Received message from %s: %s\n", remote_ip, buffer);
    }

    close(sock); // Close socket
}