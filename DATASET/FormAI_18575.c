//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *request = "GET / HTTP/1.1\nHost: www.google.com\n\n";
    char buffer[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "172.217.6.68", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Send HTTP request
    send(sock, request, strlen(request), 0);

    // Receive HTTP response
    while ((valread = read(sock, buffer, 1024)) > 0) {
        printf("%s", buffer);
    }

    return 0;
}