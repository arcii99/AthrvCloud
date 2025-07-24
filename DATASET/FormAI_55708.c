//FormAI DATASET v1.0 Category: Client Server Application ; Style: expert-level
/*
A simple client-server application that allows the client to send a message to the server. The server then translates the message to uppercase and sends back the message to the client.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080 // Port number to communicate through
#define MAX 1024 // Maximum size of the message to be sent

int main() {
    int sockfd, connfd;
    char buffer[MAX];
    struct sockaddr_in servaddr, cli;
    socklen_t len;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket\n");
        exit(0);
    }
    else {
        printf("Socket created successfully\n");
    }

    // Clearing servaddr and cli
    bzero(&servaddr, sizeof(servaddr));
    bzero(&cli, sizeof(cli));

    // Assigning IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding server socket
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Failed to bind socket\n");
        exit(0);
    }
    else {
        printf("Socket binded successfully\n");
    }

    // Listenting for client requests
    if ((listen(sockfd, 5)) != 0) {
        printf("Failed to listen\n");
        exit(0);
    }
    else {
        printf("Listening for client requests\n");
    }

    len = sizeof(cli);

    // Accepting client requests
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if (connfd < 0) {
        printf("Failed to accept client request\n");
        exit(0);
    }
    else {
        printf("Client request accepted\n");
    }

    // Recieving message from the client
    bzero(buffer, MAX);
    read(connfd, buffer, sizeof(buffer));
    printf("Message from client: %s\n", buffer);

    // Converting message to uppercase
    int i;
    for (i = 0; buffer[i]; i++) {
        buffer[i] = toupper(buffer[i]);
    }

    // Sending message back to client
    write(connfd, buffer, sizeof(buffer));
    printf("Message sent to client: %s\n", buffer);

    // Closing sockets
    close(sockfd);
    close(connfd);

    return 0;
}