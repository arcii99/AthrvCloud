//FormAI DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int fd, n, len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    // Creating socket file descriptor
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    // Filling server information
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    len = sizeof(client_addr); // store size of client address

    while (1) {
        n = recvfrom(fd, buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *)&client_addr, &len);
        buffer[n] = '\0';
        printf("Received request from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        printf("Message: %s\n", buffer);
        sendto(fd, "ACK", 3, MSG_CONFIRM, (const struct sockaddr *)&client_addr, len);
    }

    close(fd);
    return 0;
}