//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    char *username, *password;
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s [username] [password]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    username = argv[1];
    password = argv[2];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket error:");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);

    if (inet_pton(AF_INET, "pop3.server.com", &server_addr.sin_addr) <= 0) {
        perror("inet_pton error:");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect error:");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Recv error:");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Send error:");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Recv error:");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Send error:");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Recv error:");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Send error:");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Recv error:");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    close(sockfd);
    return 0;
}