//FormAI DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock, port;
    struct sockaddr_in server;
    char ip[16], protocol[4], scan[6];

    // Get input from user
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter protocol (TCP or UDP): ");
    scanf("%s", protocol);

    // Create socket
    if (strcmp(protocol, "TCP") == 0) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        strcpy(scan, "TCP");
    } else if (strcmp(protocol, "UDP") == 0) {
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        strcpy(scan, "UDP");
    } else {
        perror("Invalid protocol");
        return 1;
    }

    // Scan ports
    for (port = 1; port <= 65535; port++) {
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(ip);
        server.sin_port = htons(port);

        // Connect to port
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            printf("%s port %d is closed\n", scan, port);
        } else {
            printf("%s port %d is open\n", scan, port);
            close(sock);
        }
    }
    return 0;
}