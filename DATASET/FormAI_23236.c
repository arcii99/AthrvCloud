//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char send_buffer[MAX_BUFFER_SIZE], receive_buffer[MAX_BUFFER_SIZE];
    int socket_fd;
    struct sockaddr_in server_address;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_fd == -1)
    {
        printf("Error creating a socket.\n");
        exit(0);
    }

    printf("Socket created successfully.\n");

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr("216.58.194.206"); //ip address of google.com

    if(connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) != 0)
    {
        printf("Error in connecting.\n");
        exit(0);
    }

    printf("Connected successfully.\n");

    strcpy(send_buffer, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n"); //HTTP GET request

    if(send(socket_fd, send_buffer, strlen(send_buffer), 0) < 0)
    {
        printf("Error in sending request.\n");
        exit(0);
    }

    printf("Request sent successfully.\n");

    if(recv(socket_fd, receive_buffer, MAX_BUFFER_SIZE, 0) < 0)
    {
        printf("Error in receiving response.\n");
        exit(0);
    }

    printf("Response:\n%s\n", receive_buffer);

    close(socket_fd);

    return 0;
}