//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    printf("Welcome to the HTTP Client Example program.\n");
    printf("This program will connect to a web server and send an HTTP request.\n\n");

    // Set up socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket.\n");
        return 1;
    }
    printf("Socket created.\n");

    // Set up server information
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(80);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server.\n");
        return 1;
    }
    printf("Connected to server.\n\n");

    // Prepare HTTP request
    char request[1024];
    strcpy(request, "GET / HTTP/1.1\r\n");
    strcat(request, "Host: localhost\r\n");
    strcat(request, "Connection: close\r\n\r\n");

    // Send request to server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error sending request.\n");
        return 1;
    }
    printf("HTTP request sent.\n\n");

    // Receive response from server
    char response[1024];
    memset(response, 0, sizeof(response));
    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received < 0) {
        printf("Error receiving response.\n");
        return 1;
    }
    printf("HTTP response received:\n\n%s\n", response);

    // Close socket
    close(sockfd);
    printf("Goodbye!\n");

    return 0;
}