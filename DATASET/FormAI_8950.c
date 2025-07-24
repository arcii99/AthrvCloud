//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1" // server IP address
#define SERVER_PORT 8080 // server port number

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;

    // create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // convert IP address from string to binary form
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // send a message to the server
    char *message = "Hello from client!";
    send(sock, message, strlen(message), 0);
    printf("Client sent message: %s\n", message);

    // receive response from the server
    char buffer[1024] = {0};
    int valread = read(sock, buffer, 1024);
    printf("Client received message: %s\n", buffer);

    return 0;
}