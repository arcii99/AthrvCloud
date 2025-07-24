//FormAI DATASET v1.0 Category: Socket programming ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Socket listening on port 8080!\n");
    }

    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int new_sockfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_addr_len);
    if (new_sockfd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = {0};
    int bytes_read = read(new_sockfd, buffer, 1024);
    printf("Bytes read: %d\n\n", bytes_read);
    printf("Received: %s\n", buffer);

    char* message = "Hello from server!";
    int bytes_sent = send(new_sockfd, message, strlen(message), 0);
    printf("Bytes sent: %d\n\n", bytes_sent);
    printf("Message sent: %s\n", message);

    close(new_sockfd);
    close(sockfd);

    return 0;
}