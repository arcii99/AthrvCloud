//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int valread;
    char buffer[1024] = {0};
    char *hello = "Hello from client";
    struct sockaddr_in serv_addr;

    // creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("\n Socket creation error\n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    // assignment of IP address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // converting IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address or address not supported\n");
        return -1;
    }

    // connecting to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    // sending message to server
    send(sockfd, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    
    // reading response from server
    valread = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    return 0;
}