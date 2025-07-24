//FormAI DATASET v1.0 Category: Networking ; Style: careful
/* This program demonstrates a simple client-server communication using sockets */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000 // server port number

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket creation failed");
        exit(1);
    }

    // set server address properties
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // loopback address
    servaddr.sin_port = htons(PORT);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        perror("connection with the server failed");
        exit(1);
    }

    // receive message from the server
    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Message from server: %s\n", buffer);

    // send message to the server
    char *message = "Hello from the client!";
    write(sockfd, message, strlen(message));

    // close the socket
    close(sockfd);

    return 0;
}