//FormAI DATASET v1.0 Category: Networking ; Style: energetic
// Welcome to NetBoost
// A program to test networking capabilities in C
// By: [Your Name Here]
// Date: [Date Here]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    printf("Welcome to NetBoost! Let's test out your networking skills\n");

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully! sockfd = %d\n", sockfd);

    // Specify the address and port to bind to
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8000);

    // Bind the socket to the address and port
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    printf("Socket bound successfully to port 8000!\n");

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0){
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }
    printf("Listening on socket...\n");

    // Accept incoming connections
    int clientfd;
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    clientfd = accept(sockfd, (struct sockaddr*)&cli_addr, &cli_len);
    if (clientfd < 0){
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted! clientfd = %d\n", clientfd);

    // Send a welcome message to the client
    char welcome_msg[1024] = "Welcome to NetBoost! You are now connected to the server";
    if (send(clientfd, welcome_msg, strlen(welcome_msg), 0) < 0){
        perror("Error sending message to client");
        exit(EXIT_FAILURE);
    }
    printf("Welcome message sent successfully to client!\n");

    // Receive a message from the client
    char recv_msg[1024];
    if (recv(clientfd, recv_msg, sizeof(recv_msg), 0) < 0){
        perror("Error receiving message from client");
        exit(EXIT_FAILURE);
    }
    printf("Message received from client: %s\n", recv_msg);

    // Send a reply to the client
    char reply_msg[1024] = "Thanks for connecting to NetBoost! Goodbye!";
    if (send(clientfd, reply_msg, strlen(reply_msg), 0) < 0){
        perror("Error sending message to client");
        exit(EXIT_FAILURE);
    }
    printf("Reply message sent successfully to client!\n");

    // Close the connection
    close(clientfd);
    printf("Connection with client closed!\n");

    return 0;
}