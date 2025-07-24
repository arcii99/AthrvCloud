//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    printf("Enter the HTTP server address: ");
    char server_address[100];
    fgets(server_address, 100, stdin);

    printf("Enter the HTTP server port: ");
    char server_port[10];
    fgets(server_port, 10, stdin);

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    server_addr.sin_port = htons(atoi(server_port));

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char request[BUFFER_SIZE];
    printf("Enter HTTP request:\n");
    fgets(request, BUFFER_SIZE, stdin);
    send(sockfd, request, strlen(request), 0);

    bool headers_finished = false;
    while (!headers_finished) {
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (strstr(buffer, "\r\n\r\n")) {
            headers_finished = true;
        }
        printf("%s", buffer);
    }

    printf("\nHTTP Response:\n");
    
    bool response_finished = false;
    while (!response_finished) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == 0) {
            response_finished = true;
        }
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}