//FormAI DATASET v1.0 Category: Networking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd = 0, valread;
    struct sockaddr_in serv_addr;
    
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    
    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    // set server address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return EXIT_FAILURE;
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    // send message to server
    send(sockfd, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // receive message from server
    valread = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    return EXIT_SUCCESS;
}