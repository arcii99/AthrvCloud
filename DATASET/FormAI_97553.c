//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

//Defining constants
#define MAX_RESPONSE_SIZE 2048
#define MAX_REQUEST_SIZE 512
#define SERVER_ADDRESS "1.2.3.4"
#define SERVER_PORT 80

int main(void) {
    int socket_desc, n;
    char *message, server_reply[MAX_RESPONSE_SIZE];
    struct sockaddr_in server;


    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    //Server settings
    server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    //Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Connect error");
        return 1;
    }

    printf("\nConnected to server %s:%d\n\n", SERVER_ADDRESS, SERVER_PORT);

    //Prepare the message to send
    message = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";

    //Send some data
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    //Get the reply from the server
    if ((n = recv(socket_desc, server_reply, MAX_RESPONSE_SIZE, 0)) == -1) {
        puts("recv failed");
    }
    else {
        printf("%s", server_reply);
    }

    close(socket_desc);

    return 0;
}