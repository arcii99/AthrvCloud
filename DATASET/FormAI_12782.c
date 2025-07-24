//FormAI DATASET v1.0 Category: Networking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() 
{
    printf("Welcome to my Networking program!\n");
    int sock;
    char message[100], server_reply[2000];
    struct sockaddr_in server;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Couldn't create socket!\n");
    }
    puts("Socket created successfully!\n");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0)
    {
        perror("Connect failed!");
        return 1;
    }
    puts("Connected to server successfully!\n");

    while(1)
    {
        printf("Enter message: ");
        fgets(message, 100, stdin);
        send(sock, message, strlen(message), 0);

        if (recv(sock, server_reply, 2000, 0) < 0)
        {
            puts("Failed to receive server reply!\n");
            break;
        }
        printf("Server replied with: ");
        puts(server_reply);
        memset(server_reply, 0, sizeof(server_reply));
    }
    close(sock);
    return 0;
}