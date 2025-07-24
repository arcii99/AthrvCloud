//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int sock_desc;
    struct sockaddr_in server_addr;
    char server_response[1024];

    //create socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_desc == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    //setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(80);

    //connect to server
    if(connect(sock_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Could not connect to server\n");
        return 1;
    }
    printf("Connected to server %s:%d\n", argv[1], 80);

    //send request to server
    char *message = "GET / HTTP/1.1\r\n\r\n";
    if(send(sock_desc, message, strlen(message), 0) < 0)
    {
        printf("Could not send message to server\n");
        return 1;
    }
    printf("Request sent to server\n");

    //receive response from server
    if(recv(sock_desc, server_response, sizeof(server_response), 0) < 0)
    {
        printf("Could not receive response from server\n");
        return 1;
    }
    printf("Response received from server:\n");
    printf("%s", server_response);

    close(sock_desc);
    printf("Connection closed\n");
    return 0;
}