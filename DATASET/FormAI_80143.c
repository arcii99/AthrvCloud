//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define HOST "www.google.com"
#define PORT 80

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
        exit(1);
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        exit(1);
    }

    puts("Connected\n");

    // Send HTTP request to server
    strcpy(message, "GET / HTTP/1.1\r\n");
    strcat(message, "Host: ");
    strcat(message, HOST);
    strcat(message, "\r\n");
    strcat(message, "Connection: close\r\n");
    strcat(message, "\r\n");

    if(send(sock, message, strlen(message), 0) < 0)
    {
        perror("Send failed");
        exit(1);
    }

    puts("HTTP Request Sent\n");

    //Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
        exit(1);
    }

    puts("HTTP Response Received\n");
    puts(server_reply);

    close(sock);
    return 0;
}