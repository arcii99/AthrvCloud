//FormAI DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
// Welcome to the Sherlock Holmes Client-Server Chatbot Application

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 4444

int main(void)
{
    int sockfd, new_sockfd, n;
    socklen_t clilen;

    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    // Creating a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Setting up server address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Binding the socket to server's address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Unable to bind socket");
        exit(1);
    }
    
    // Listening for connections
    listen(sockfd, 5);
    
    // Accepting a new connection
    clilen = sizeof(cli_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (new_sockfd < 0) {
        perror("ERROR: Unable to accept connection");
        exit(1);
    }

    printf("Sherlock: Welcome to the Client-Server Chatbot Application!\n");
    printf("Sherlock: How can I help you today?\n");

    while (1) {
        memset(buffer, 0, 256);
        n = read(new_sockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR: Unable to read from socket");
            exit(1);
        }

        printf("Client: %s", buffer);

        // Exit if user enters 'bye'
        if (strcasecmp(buffer, "bye\n") == 0) {
            printf("Sherlock: Goodbye! It was a pleasure helping you.\n");
            break;
        }

        // Sherlock's response
        char response[256];
        if (strcasecmp(buffer, "hello\n") == 0) {
            strcpy(response, "Hello there! How can I assist you today?\n");
        } else if (strstr(buffer, "case") != NULL) {
            strcpy(response, "I love a good case! Please tell me more.\n");
        } else if (strstr(buffer, "Watson") != NULL) {
            strcpy(response, "Ah, my dear friend Watson. How can I be of service?\n");
        } else {
            strcpy(response, "I'm sorry, I don't quite understand. Can you please rephrase that?\n");
        }

        // Replying to client
        n = write(new_sockfd, response, strlen(response));
        if (n < 0) {
            perror("ERROR: Unable to write to socket");
            exit(1);
        }
    }

    // Closing the sockets
    close(new_sockfd);
    close(sockfd);

    return 0;
}