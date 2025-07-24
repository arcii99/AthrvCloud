//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024
#define PORT 80

int main(int argc, char const *argv[])
{
    struct sockaddr_in server_address;
    char message[MAX_BUFFER_SIZE], server_reply[MAX_BUFFER_SIZE];
    int socket_fd;

    // create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error creating socket");
        return -1;
    }

    // set server address details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("216.58.194.174"); // google.com IP address
    server_address.sin_port = htons(PORT);

    // connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Error connecting to server");
        return -1;
    }

    // create HTTP request
    strcpy(message, "GET / HTTP/1.1\r\n");
    strcat(message, "Host: www.google.com\r\n");
    strcat(message, "Connection: close\r\n\r\n");

    // send HTTP request to server
    if (send(socket_fd, message, strlen(message), 0) < 0)
    {
        printf("Error sending request to server");
        return -1;
    }

    // receive and print server response
    int response_len;
    while ((response_len = recv(socket_fd, server_reply, MAX_BUFFER_SIZE, 0)) > 0)
    {
        server_reply[response_len] = '\0';
        printf("%s", server_reply);
    }

    printf("\n");

    // close socket connection
    close(socket_fd);

    return 0;
}