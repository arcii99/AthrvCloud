//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8888

void error_handler(const char *message);

int main() {
    printf("Excited to showcase my TCP/IP programming skills!\n");

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error_handler("Error opening socket");

    printf("Socket opened successfully!\n");

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        error_handler("Error binding socket");

    printf("Socket bound successfully!\n");

    if (listen(sockfd, 5) < 0)
        error_handler("Error listening to the socket");

    printf("Socket is now listening!\n");

    int client_len = sizeof(client_addr);
    int client_fd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0)
        error_handler("Error accepting connection");

    printf("Connection accepted successfully!\n");

    char *message = "Hello there, client!\n";
    if (send(client_fd, message, strlen(message), 0) < 0)
        error_handler("Error sending message");

    printf("Message sent successfully!\n");

    char buffer[1024] = {0};
    if (recv(client_fd, buffer, 1024, 0) < 0)
        error_handler("Error receiving message");

    printf("Message received from client: %s\n", buffer);

    close(client_fd);
    close(sockfd);

    printf("Connection closed and socket closed. Program finished successfully!\n");

    return 0;
}

void error_handler(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}