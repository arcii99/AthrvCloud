//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s IP\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int socket_desc;
    struct sockaddr_in server_addr;
    char buffer[BUFF_SIZE] = {0};

    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(80);

    if (connect(socket_desc, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Failed\n");
        exit(1);
    }

    char *request = "GET / HTTP/1.1\n";
    if (send(socket_desc, request, strlen(request), 0) < 0) {
        printf("Send failed\n");
        exit(1);
    }

    if (recv(socket_desc, buffer, BUFF_SIZE, 0) < 0) {
        printf("Receive failed\n");
        exit(1);
    }

    char *response = strstr(buffer, "Server:");
    if (response) {
        response += strlen("Server:");
        printf("Server: %s\n", response);
    } else {
        printf("Server information not found\n");
    }

    close(socket_desc);
    return 0;
}