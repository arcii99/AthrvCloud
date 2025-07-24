//FormAI DATASET v1.0 Category: Client Server Application ; Style: relaxed
/* This is a simple C client-server application that allows the client to send a message to the server, and the server to send a response back to the client. The client then displays the server response to the user.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    // Creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
    {
        printf("Socket successfully created...\n");
    }
    
    struct sockaddr_in servaddr, cliaddr;
    // Clear the structures
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        printf("Binding failed...\n");
        exit(0);
    }
    else
    {
        printf("Socket successfully binded...\n");
    }

    // Listen for clients
    if (listen(sockfd, 5) < 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
    {
        printf("Server listening...\n");
    }

    // Accept the client
    socklen_t cliaddrlen = sizeof(cliaddr);
    int connfd = accept(sockfd, (struct sockaddr *)&cliaddr,
                        &cliaddrlen);
    if (connfd < 0)
    {
        printf("Error in accepting the client...\n");
        exit(0);
    }
    else
    {
        printf("Client accepted...\n");
    }

    char buffer[1024] = {0};
    // Read the message from the client
    read(connfd, buffer, 1024);
    printf("Message received from client: %s\n", buffer);

    // Send a response to the client
    char *response = "Thank you for your message, client!";
    write(connfd, response, strlen(response));

    // Close the sockets
    close(connfd);
    close(sockfd);
    return 0;
}