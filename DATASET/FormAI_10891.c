//FormAI DATASET v1.0 Category: Browser Plugin ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("socket creation failed");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        return 1;
    }

    printf("Listening for messages on port %d\n", PORT);

    while (1) {
        int len, n;
        n = recvfrom(sockfd, (char*)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr*) &cliaddr, &len);

        buffer[n] = '\0';

        printf("Client : %s\n", buffer);

        char* message = "Message received";

        sendto(sockfd, (const char*)message, strlen(message), MSG_CONFIRM, (const struct sockaddr*) &cliaddr, len);

        printf("Message sent back\n");
    }

    close(sockfd);
    return 0;
}