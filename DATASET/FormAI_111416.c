//FormAI DATASET v1.0 Category: Socket programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080

int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");

    // Set the server address details
    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Listen for incoming connections from clients
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");

    int len = sizeof(cli);

    // Accept new connections and handle them
    while (1) {
        connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
        if (connfd < 0) {
            printf("Server accept failed...\n");
            exit(0);
        }
        else
            printf("Server accepted the client...\n");

        // Communicate with the client
        while (1) {
            bzero(buffer, 1024);
            if (read(connfd, buffer, sizeof(buffer)) < 0) {
                printf("Server read failed...\n");
                exit(0);
            }

            // Display the message from the client
            printf("Message from client: %s", buffer);

            // Send the message to the client
            char *message = "Hello from server\n";
            write(connfd, message, strlen(message) + 1);
        }

        // Close the connection with the client
        close(connfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}