//FormAI DATASET v1.0 Category: Networking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    printf("Welcome to the Netrunners Hub!\n");

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket!\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Set server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection error!\n");
        exit(0);
    }

    printf("Connected to server successfully.\n");

    char buffer[1024];
    printf("Enter your handle: ");
    fgets(buffer, 1024, stdin);
    // Remove newline character from input
    buffer[strcspn(buffer, "\n")] = 0;

    // Send handle to server
    write(sockfd, buffer, strlen(buffer));

    while (1) {
        printf("Type your message (type \"exit\" to quit):\n");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        // Exit program if user types "exit"
        if (strcmp(buffer, "exit") == 0) {
            printf("Disconnecting from server...\n");
            break;
        }

        // Send message to server
        write(sockfd, buffer, strlen(buffer));

        // Receive message from server
        memset(buffer, 0, sizeof(buffer));
        read(sockfd, buffer, sizeof(buffer));
        printf("Server response: %s\n", buffer);
    }

    // Close socket connection
    close(sockfd);
    printf("Goodbye! Stay safe out there.\n");
    return 0;
}