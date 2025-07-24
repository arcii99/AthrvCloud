//FormAI DATASET v1.0 Category: Networking ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    // Create a socket for communicating over an IP network
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Specify the address and port to connect to
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect\n");
        exit(EXIT_FAILURE);
    }
    
    // Send a message to the server
    char message[BUF_SIZE];
    sprintf(message, "Hello server");
    write(sock, message, strlen(message));

    // Receive a response from the server
    char response[BUF_SIZE];
    read(sock, response, sizeof(response));

    // Print the response
    printf("Server response: %s\n", response);

    // Close the socket
    close(sock);

    return 0;
}