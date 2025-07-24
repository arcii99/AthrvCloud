//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    char message[BUFFER_SIZE], response[BUFFER_SIZE];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connect error");
        return 1;
    }

    // Send HTTP request
    sprintf(message, "GET / HTTP/1.1\r\nUser-Agent: myhttpclient\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n");
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    // Receive HTTP response
    int bytes_received = 0;
    while ((bytes_received += recv(socket_desc, response + bytes_received, BUFFER_SIZE - bytes_received, 0)) <= BUFFER_SIZE);

    // Print HTTP response
    printf("%s", response);

    // Close socket
    close(socket_desc);

    return 0;
}