//FormAI DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, read_length;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    char* welcome_msg = "Welcome to the networking world!\n";

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error_handling("socket() error");

    // Assign IP and port for the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified IP and port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error_handling("bind() error");

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1)
        error_handling("listen() error");

    printf("Waiting for incoming connections...\n");

    while (1) {
        socklen_t cli_addr_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &cli_addr_len);

        if (new_sockfd == -1)
            error_handling("accept() error");

        printf("Connected with client: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Send welcome message to the client
        write(new_sockfd, welcome_msg, strlen(welcome_msg));

        // Read the client message
        read_length = read(new_sockfd, buffer, 1024);

        if (read_length == -1)
            error_handling("read() error");

        printf("Message from client: %s", buffer);

        // Echo back the client message
        write(new_sockfd, buffer, strlen(buffer));

        // Close the socket
        close(new_sockfd);
    }

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}