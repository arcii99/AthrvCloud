//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 80
#define SERVER_NAME "www.google.com"

int main() {
    int socket_desc;
    struct sockaddr_in server_addr;
    char *message, server_reply[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    server_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
    puts("Connected\n");

    // Create HTTP request message
    message = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("Request sent\n");

    // Receive server response
    if (recv(socket_desc, server_reply, sizeof(server_reply), 0) < 0) {
        puts("recv failed");
    }
    puts("Response received\n");
    puts(server_reply);

    close(socket_desc);

    return 0;
}