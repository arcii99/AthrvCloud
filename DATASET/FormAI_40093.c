//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define HTTP_PORT 80

int main(int argc, char *argv[]) {
    // check if user has provided the required arguments
    if(argc < 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        return 0;
    }

    // create a socket object to connect to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    // define the server address
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(HTTP_PORT);

    // connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Unable to connect to server\n");
        return 1;
    }

    // form the HTTP GET request
    char *message = "GET / HTTP/1.1\r\n\r\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Failed to send the HTTP GET request\n");
        return 1;
    }

    // receive the response from the server
    char server_response[2048];
    if(recv(sock, server_response, 2048, 0) < 0) {
        printf("Unable to get the server response\n");
        return 1;
    }

    // print the server response
    printf("Server Response:\n%s\n", server_response);

    // close the socket connection
    close(sock);
    return 0;
}