//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h> 
#include<string.h>
#include<stdlib.h>

#define BUF_SIZE 4096

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[BUF_SIZE] , server_reply[BUF_SIZE];

    //create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
        return 1;
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 143 );

    //Connect to remote server
    if (connect(sock ,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    //Receive welcome message from server
    if( recv(sock , server_reply , BUF_SIZE , 0) < 0)
    {
        puts("recv failed");
        return 1;
    }
    puts(server_reply);

    //Send username and password to server
    sprintf(message, "a001 LOGIN \"username\" \"password\"\r\n");
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    //Receive server's reply to login request
    memset(server_reply, 0, sizeof(server_reply));
    if( recv(sock , server_reply , BUF_SIZE , 0) < 0)
    {
        puts("recv failed");
        return 1;
    }
    puts(server_reply);

    //Send command to fetch inbox messages
    sprintf(message, "a002 SELECT INBOX\r\n");
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    //Receive server's reply
    memset(server_reply, 0, sizeof(server_reply));
    if( recv(sock , server_reply , BUF_SIZE , 0) < 0)
    {
        puts("recv failed");
        return 1;
    }
    puts(server_reply);

    //Close the socket
    close(sock);
    return 0;
}