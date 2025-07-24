//FormAI DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char *message , server_reply[2000];
    
    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }

    // Set IP address and port number of the server
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    // Connect to server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("Connection error");
        return 1;
    }

    puts("Connected\n");
    
    // Send some data to the server
    message = "Hello Server!";
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");
    
    // Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts("Reply received\n");
    puts(server_reply);
    
    close(sock);
    return 0;
}