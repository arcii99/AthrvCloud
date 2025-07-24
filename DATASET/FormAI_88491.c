//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 110

int main(int argc, char *argv[]) {
    // Connect to POP3 server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server");
        exit(1);
    }

    // Send request to server
    char buffer[1024];
    memset(buffer, 0, 1024);
    sprintf(buffer, "USER username\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, 1024);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    memset(buffer, 0, 1024);
    sprintf(buffer, "PASS password\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, 1024);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    memset(buffer, 0, 1024);
    sprintf(buffer, "STAT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, 1024);
    recv(sock, buffer, 1024, 0);
    printf("%s", buffer);

    // Close connection
    close(sock);

    return 0;
}