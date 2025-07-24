//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    char request[4096], response[4096];
    
    if (argc < 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    inet_pton(AF_INET, argv[1], &server_address.sin_addr);

    connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
    
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    send(sock, request, strlen(request), 0);

    recv(sock, response, sizeof(response), 0);
    printf("%s", response);
    
    close(sock);
    return 0;
}