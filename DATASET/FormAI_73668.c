//FormAI DATASET v1.0 Category: Networking ; Style: inquisitive
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        perror("Address conversion failed");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }

    char message[256];
    printf("Enter a message: ");
    fgets(message, 256, stdin);
    send(sockfd, message, strlen(message), 0);

    char buffer[1024];
    read(sockfd, buffer, 1024);
    printf("Server reply: %s\n", buffer);

    close(sockfd);
    return 0;
}