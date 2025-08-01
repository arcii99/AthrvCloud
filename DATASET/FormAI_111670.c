//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];

    //init socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    //Connect to remote server
    if (connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        puts("Could not connect");
        return 1;
    }

    puts("Connected\n");

    //Send some data
    message = "GET /index.html HTTP/1.1\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    puts("Data Sent\n");

    //Receive a reply from the server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }

    puts("Reply received\n");
    puts(server_reply);

    close(socket_desc);
    return 0;
}