//FormAI DATASET v1.0 Category: Networking ; Style: inquisitive
// This program uses TCP to send and receive messages between two computers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1234

int main(int argc, char const *argv[])
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Set up serv_addr
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address from string to binary form
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

    while(1) {
        printf("Enter message: ");
        fgets(message, 1024, stdin);

        // Send message
        send(sock, message, strlen(message), 0);

        // Clear message buffer
        memset(message, 0, sizeof(message));

        // Receive message
        int valread = read(sock, message, 1024);

        printf("Server response: %s\n", message);
    }

    return 0;
}