//FormAI DATASET v1.0 Category: Networking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, '0', sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server!\n");

    char buffer[1024] = {0};

    while (1) {
        printf("Enter message: ");
        fgets(buffer, 1024, stdin);

        if (strlen(buffer) == 0) {
            break;
        }

        write(sockfd, buffer, strlen(buffer));

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        read(sockfd, buffer, 1024);
        printf("Server response: %s", buffer);
    }

    printf("Disconnected from server!\n");

    close(sockfd);
    return 0;
}