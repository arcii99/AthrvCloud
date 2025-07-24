//FormAI DATASET v1.0 Category: Networking ; Style: bold
/**************************************************************
*                 BOLD C NETWORKING EXAMPLE                  *
*                                                            *
* This program demonstrates a chat system where two users can *
* communicate with each other over the internet.             *
*                                                            *
* Created by <Your Name> on <Date>                           *
**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main()
{
    int sockfd;
    struct sockaddr_in serv_addr;
    char msg[1024], buffer[1024];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        error("Failed to create socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        error("Invalid address");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("Connection failed");
    }

    // Start chatting
    printf("\n ***** You are connected! Start chatting *****\n");
    while(1)
    {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Read message from the user
        printf("Enter your message: ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = 0;

        // Send message to the server
        if(send(sockfd, msg, strlen(msg), 0) < 0)
        {
            error("Failed to send the message");
        }

        // If user sends 'quit', terminate the connection
        if (strcmp(msg, "quit") == 0)
        {
            printf("\nConnection terminated.\n\n");
            close(sockfd);
            exit(0);
        }

        // Receive response from the server
        if(recv(sockfd, buffer, sizeof(buffer), 0) < 0)
        {
            error("Failed to receive response from the server");
        }

        // Display the response
        printf("Server: %s\n", buffer);
    }

    return 0;
}