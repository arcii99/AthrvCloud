//FormAI DATASET v1.0 Category: Client Server Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9001

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [server_ip_address]\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Opening socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address or not in network byte order: %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Client connected to server at IP address %s and port %d\n\n", argv[1], PORT);

    char buffer[1024];

    while (1) {
        printf("Enter your message to send to the server (type 'quit' to exit): ");

        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        write(sockfd, buffer, strlen(buffer));
        printf("Message sent to the server! Waiting for response...\n");

        read(sockfd, buffer, 1024);

        if (strcasecmp(buffer, "quit") == 0) {
            printf("Server closed the connection. Goodbye!\n");
            break;
        }

        printf("Server's response: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}