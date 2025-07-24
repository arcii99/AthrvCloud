//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8888

int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from the other side";
    char buffer[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Send a message to the server
    send(sock , hello , strlen(hello) , 0 );
    printf("Message sent: %s\n", hello);

    // Receive a message from the server
    valread = read( sock , buffer, 1024);
    printf("Server says: %s\n", buffer );

    // Close the socket
    close(sock);

    return 0;
}