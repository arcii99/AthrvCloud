//FormAI DATASET v1.0 Category: Chat server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 4444

int main()
{
    int sockfd, clientfd, opt = 1;
    struct sockaddr_in server, client;
    char buffer[1024] = {0};
    int addrlen = sizeof(server);
    char *greeting = "Welcome to the Neon City chat server!";

    // Creating socket file descriptor
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 4444
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting up the server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( PORT );

    // Bind the socket to the port
    if(bind(sockfd, (struct sockaddr *)&server, sizeof(server))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(sockfd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    if((clientfd = accept(sockfd, (struct sockaddr *)&client, (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("New connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    // Send a welcome message to the client
    send(clientfd, greeting, strlen(greeting), 0);

    while(1)
    {
        bzero(buffer, sizeof(buffer));
        read(clientfd, buffer, sizeof(buffer));
        printf("%s\n", buffer); // Cyberpunk style! Echo the message back onto the console.

        // If the client sends "exit" then terminate the connection
        if(strcmp(buffer, "exit\n") == 0)
        {
            close(clientfd);
            printf("Connection closed with %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
            break;
        }

        // Otherwise, echo the message back to the client
        send(clientfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    return 0;
}