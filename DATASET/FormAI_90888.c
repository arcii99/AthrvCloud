//FormAI DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");

    memset(&servaddr, 0, sizeof(servaddr));

    // Assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connect the client socket to server socket
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("Connection with the server failed...\n");
        exit(0);
    }
    else
        printf("Connected to the server..\n");

    while (1)
    {
        printf("Enter message: ");
        fgets(buffer, 1024, stdin);
        if (strcmp(buffer, "exit\n") == 0)
            break;

        // Send the message to server
        write(sockfd, buffer, strlen(buffer));

        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Read the message from server
        read(sockfd, buffer, sizeof(buffer));

        // Print the server's response
        printf("From server: %s", buffer);
    }

    //Close the socket
    close(sockfd);
    return 0;
}