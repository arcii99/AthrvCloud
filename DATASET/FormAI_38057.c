//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    char server_reply[MAX_BUFFER_SIZE];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error: Could not create socket!");
        return 1;
    }

    //Server configuration
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    //Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error: Connection Failed!");
        return 1;
    }

    //Send some data
    char *message = "Hello Server!";
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Error: Send Failed!");
        return 1;
    }

    //Receive a reply from server
    if (recv(sock, server_reply, MAX_BUFFER_SIZE, 0) < 0)
    {
        printf("Error: Receive Failed!");
        return 1;
    }

    printf("Server Reply: %s\n", server_reply);

    close(sock);
    return 0;
}