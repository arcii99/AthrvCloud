//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    // Create a socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sockfd < 0) {
        perror("Failed to create a socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.1.100");
    server_address.sin_port = htons(8000);

    // Connect to the server
    int status;
    status = connect(sockfd, (struct sockaddr*)&server_address, sizeof(struct sockaddr_in));

    if (status < 0) {
        perror("Failed to connect to the server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Send an HTTP request
    char *message = "GET / HTTP/1.1\r\nHost: 192.168.1.100:8000\r\n\r\n";
    status = send(sockfd, message, strlen(message), 0);

    if (status < 0) {
        perror("Failed to send an HTTP request");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive an HTTP response
    char response[1024];
    memset(response, 0, sizeof(response));
    status = recv(sockfd, response, sizeof(response), 0);

    if (status < 0) {
        perror("Failed to receive an HTTP response");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Print the HTTP response
    printf("%s", response);

    // Close the socket
    close(sockfd);

    return 0;
}