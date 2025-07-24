//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;

    char *message;
    char server_reply[2000];

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("Connection error");
        return 1;
    }

    puts("Connected");

    message = "GET / HTTP/1.1\r\n\r\n";

    if (send(socket_desc, message, strlen(message), 0) < 0)
    {
        puts("Send Failed");
        return 1;
    }

    puts("Data Sent\n");

    if (recv(socket_desc, server_reply, 2000, 0) < 0)
    {
        puts("Receive Failed");
        return 1;
    }

    puts("Reply Received\n");
    puts(server_reply);

    close(socket_desc);

    return 0;
}