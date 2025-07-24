//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

#define MAX_REQUEST_SIZE 2048

int main(int argc, char* argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    char request[MAX_REQUEST_SIZE], server_reply[MAX_REQUEST_SIZE];

    // Creating a socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error in creating socket \n");
        exit(EXIT_FAILURE);
    }

    // Setting server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("216.239.32.21");

    // Connecting to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error in connecting \n");
        exit(EXIT_FAILURE);
    }

    // Preparing request
    sprintf(request, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");

    // Sending request
    if(send(sock, request, strlen(request), 0) == -1)
    {
        perror("Error in sending request \n");
        exit(EXIT_FAILURE);
    }

    // Receiving response
    if(recv(sock, server_reply, MAX_REQUEST_SIZE, 0) == -1)
    {
        perror("Error in receiving response \n");
        exit(EXIT_FAILURE);
    }

    // Printing response
    printf("Server Response : %s \n", server_reply);

    // Closing socket
    close(sock);

    return 0;
}