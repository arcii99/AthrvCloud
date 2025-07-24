//FormAI DATASET v1.0 Category: Socket programming ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sockfd;
    struct sockaddr_in server_address;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];

    printf("Enter a message: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    if (send(sockfd, buffer, strlen(buffer), 0) != strlen(buffer)) {
        perror("Failed to send message");
        exit(EXIT_FAILURE);
    }

    printf("Message sent\n");

    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive message");
        exit(EXIT_FAILURE);
    }

    printf("Message received: %s\n", buffer);

    close(sockfd);
    return EXIT_SUCCESS;
}