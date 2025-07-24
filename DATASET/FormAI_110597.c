//FormAI DATASET v1.0 Category: Networking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in server_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    char address[100] = "192.0.2.0"; // replace with real IP address

    // create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    // set the socket address
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // convert IP address from text to binary form
    if(inet_pton(AF_INET, address, &server_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // send a message to the server
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // receive a message from the server
    valread = read(sock, buffer, 1024);
    printf("%s\n",buffer);

    // close the socket
    close(sock);
    return 0;
}