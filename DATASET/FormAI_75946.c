//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080

int main(){
    int sockfd, new_sockfd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to a specific IP and port
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("Could not bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0){
        perror("Could not listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");

    if ((new_sockfd = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("Could not accept incoming connection");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = {0};
    char *response = "Hello from the server!";

    // Read from client
    int valread = read(new_sockfd, buffer, 1024);
    printf("Received: %s", buffer);

    // Send response back to client
    send(new_sockfd, response, strlen(response), 0);
    printf("Response sent.\n");

    return 0;
}