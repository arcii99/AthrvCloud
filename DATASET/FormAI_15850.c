//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Create TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sock == -1)
    {
        printf("Failed to create socket");
        return 1;
    }
    
    // Socket address structure
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Could not connect");
        return 1;
    }
    
    // Send data to server
    char message[100];
    strcpy(message, "Hello, world!\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    
    // Receive data from server
    char server_reply[2000];
    if (recv(sock, server_reply, 2000, 0) < 0)
    {
        printf("Receive failed");
        return 1;
    }
    
    printf("Server reply: %s", server_reply);
    
    // Close socket
    close(sock);
    
    return 0;
}