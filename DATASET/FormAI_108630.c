//FormAI DATASET v1.0 Category: Client Server Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, n;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, client_addr;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // clear server address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));

    // set server address values
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    // listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        error("ERROR on listening");
    }

    // accept client connection
    client_len = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
    if (newsockfd < 0) {
        error("ERROR on accept");
    }

    printf("Connected to client\n");

    while (1) {
        // clear buffer
        memset(buffer, 0, BUFFER_SIZE);

        // read from socket
        n = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }

        // check for exit command from client
        if (strncmp("exit", buffer, 4) == 0) {
            printf("Exiting\n");
            break;
        }

        // print message from client
        printf("Client: %s\n", buffer);

        // clear buffer
        memset(buffer, 0, BUFFER_SIZE);

        // get message from user
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE-1, stdin);

        // write message to socket
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }

        // check for exit command from user
        if (strncmp("exit", buffer, 4) == 0) {
            printf("Exiting\n");
            break;
        }
    }

    // close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}