//FormAI DATASET v1.0 Category: Socket programming ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd, new_sockfd;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[1024] = {0};
    char *greeting = "Hello from the server!";

    // Create a socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to the server address and port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d...\n", PORT);

    // Accept incoming connections
    int client_addr_len = sizeof(client_addr);
    if ((new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Send a greeting message to the client
    send(new_sockfd, greeting, strlen(greeting), 0);
    printf("Greeting message sent to the client\n");

    // Receive data from the client
    int valread = read(new_sockfd, buffer, 1024);
    printf("Client sent the message: %s\n", buffer);

    // Close the sockets
    close(new_sockfd);
    close(sockfd);

    return 0;
}