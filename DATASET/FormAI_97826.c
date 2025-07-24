//FormAI DATASET v1.0 Category: Socket programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];
    char *hello = "Hello, from the other side!";

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connection to the server failed");
        exit(1);
    }
    printf("Connection established with the server!\n");
    
    // Send message to the server
    send(sockfd, hello, strlen(hello), 0);
    printf("Message sent to the server: %s\n", hello);

    // Receive message from server
    memset(&buffer, '\0', sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("failed to receive data from server");
        exit(1);
    }
    printf("Data received from server: %s\n", buffer);

    // Close the socket
    close(sockfd);
    printf("Socket closed successfully!\n");

    return 0;
}