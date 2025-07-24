//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_descriptor;
    struct sockaddr_in server_address;
    char *host = "www.example.com";
    char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    char response[BUFFER_SIZE];

    // Create socket
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Populate server address struct
    server_address.sin_addr.s_addr = inet_addr(host);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);

    // Connect to server
    if (connect(socket_descriptor, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    // Send request to server
    if (send(socket_descriptor, request, strlen(request), 0) < 0) {
        perror("Failed to send request to server");
        return 1;
    }

    // Receive response from server
    memset(response, 0, sizeof(response));
    if (recv(socket_descriptor, response, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }

    // Print response from server
    printf("%s", response);

    // Close socket connection
    close(socket_descriptor);

    return 0;
}