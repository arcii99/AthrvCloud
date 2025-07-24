//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *request = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket\n");
        return -1;
    }

    // Set server address
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);

    if (inet_pton(AF_INET, "172.217.166.78", &server_address.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server\n");
        return -1;
    }

    // Send request
    if (send(sock, request, strlen(request), 0) != strlen(request)) {
        printf("Failed to send request\n");
        return -1;
    }

    // Receive response
    while ((valread = read(sock, buffer, MAX_BUFFER_SIZE)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    if (valread < 0) {
        printf("Failed to receive response\n");
        return -1;
    }

    close(sock);

    return 0;
}