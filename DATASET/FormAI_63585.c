//FormAI DATASET v1.0 Category: Socket programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int sfd;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};
    char message[] = "Hello, I am a peaceful socket programming example program.";

    //Create socket
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        printf("Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    //Connect to server
    if (connect(sfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }

    //Send message to server
    send(sfd , message , strlen(message) , 0 );

    printf("Message sent: %s\n", message);

    //Receive message from server
    read(sfd , buffer, 1024);

    printf("Message received: %s\n", buffer);

    //Close socket
    close(sfd);

    return 0;
}