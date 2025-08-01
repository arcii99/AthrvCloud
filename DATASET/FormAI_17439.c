//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: synchronous
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];

    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }

    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8080 );

    // Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    // Send request to remote server
    strcpy(message, "GET / HTTP/1.1\r\nHost: localhost:8080\r\n\r\n");
    if(send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    puts("Request sent\n");

    // Receive a reply from the server
    if(recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
        return 1;
    }

    puts("Reply received\n");
    puts(server_reply);

    // Close socket
    close(sock);
    return 0;
}