//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char *host = "example.com";
    char *req = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    struct sockaddr_in serv_addr;
    int sock = 0, bytes = 0;
    char buffer[MAX_BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Creating socket failed\n"); 
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported\n"); 
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed\n"); 
        return -1;
    }

    if (send(sock, req, strlen(req), 0) < 0) {
        perror("Sending failed\n"); 
        return -1;
    }

    while ((bytes = read(sock, buffer, MAX_BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, bytes, stdout);
    }

    close(sock);

    return 0;
}