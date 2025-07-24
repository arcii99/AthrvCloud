//FormAI DATASET v1.0 Category: Client Server Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_BUFFER_SIZE];
    pid_t childpid;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set server address
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    listen(sockfd, 5);
    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        // Create child process to handle client
        if ((childpid = fork()) < 0) {
            perror("Error forking process");
            exit(1);
        } else if (childpid == 0) {
            close(sockfd);

            // Receive message from client
            bzero(buffer, MAX_BUFFER_SIZE);
            int n = read(newsockfd, buffer, MAX_BUFFER_SIZE);
            if (n < 0) {
                perror("Error reading from socket");
                exit(1);
            }
            printf("Received message from client: %s\n", buffer);

            // Send message to client
            char* response = "I am the server. This is a post-apocalyptic world. What do you need help with?";
            n = write(newsockfd, response, strlen(response));
            if (n < 0) {
                perror("Error writing to socket");
                exit(1);
            }
            printf("Sent message to client: %s\n", response);

            close(newsockfd);
            exit(0);
        } else {
            close(newsockfd);
        }
    }

    return 0;
}