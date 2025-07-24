//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 4444

void secure_wipe(void *ptr, size_t size) {
    volatile char *vptr = ptr;
    while (size--) *vptr++ = 0;
}

int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    // bind socket to local address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // paranoid mode activated
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        // accept incoming connection
        socklen_t addr_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
        if (new_sockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        // read data from client
        char buffer[1024] = {0};
        ssize_t bytes_received = recv(new_sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            perror("recv failed");
            exit(1);
        }

        // erase sensitive data after use
        secure_wipe(buffer, sizeof(buffer));

        // send response to client
        const char response[] = "Hello from paranoid server!\n";
        ssize_t bytes_sent = send(new_sockfd, response, sizeof(response), 0);
        if (bytes_sent < 0) {
            perror("send failed");
            exit(1);
        }

        // secure erase socket buffer
        char dummy_buffer[1024] = {0};
        while (recv(new_sockfd, dummy_buffer, sizeof(dummy_buffer), MSG_DONTWAIT) > 0) {
            secure_wipe(dummy_buffer, sizeof(dummy_buffer));
        }

        // close connection
        close(new_sockfd);
    }

    // close socket
    close(sockfd);

    return 0;
}