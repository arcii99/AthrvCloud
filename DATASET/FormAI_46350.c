//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, cli_sockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    // Initializing socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Assigning server address details
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(portno);

    // Binding the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    // Listening to incoming client connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    printf("Welcome to the surrealist TCP/IP server!\n");
    printf("Waiting for clients to connect...\n\n");

    // Accepting incoming client connection
    cli_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (cli_sockfd < 0) {
        perror("Error on accept");
        exit(1);
    }

    printf("A client has connected!\n\n");

    // Receiving message from the connected client
    bzero(buffer, 256);
    read(cli_sockfd, buffer, 255);

    printf("The client has sent a message:\n");
    printf("'%s'\n", buffer);

    // Encoding the received message using surrealist cipher
    for (int i = 0; i < strlen(buffer); i++) {
        buffer[i] = ((buffer[i] * 2 + 14) % 236) + 20;
    }

    printf("\nEncoding the message using surrealist cipher...\n\n");

    // Sending the encoded message back to the client
    write(cli_sockfd, buffer, strlen(buffer));

    printf("The encoded message has been sent back to the client\n");
    printf("Disconnecting from the client...\n");

    // Closing the socket and exiting the program
    close(cli_sockfd);
    close(sockfd);
    return 0;
}