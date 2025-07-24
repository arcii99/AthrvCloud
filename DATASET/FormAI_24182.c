//FormAI DATASET v1.0 Category: Client Server Application ; Style: optimized
/* 
    This is a simple client-server application in C.
    The server receives a string message from the client, converts it to upper case,
    and returns the result back to the client.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define MESSAGE_LEN 1024
#define PORT 8080

void error(char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int server_fd, client_fd, address_len;
    struct sockaddr_in server_address, client_address;
    char message[MESSAGE_LEN];

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        error("Socket creation failed");

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
        error("Binding failed");

    if (listen(server_fd, 5) < 0)
        error("Listen failed");

    printf("Server is listening on port %d.\n", PORT);

    address_len = sizeof(client_address);

    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_address, (socklen_t*)&address_len)) < 0)
            error("Accepting client connection failed");

        // receive client message
        if (recv(client_fd, message, MESSAGE_LEN, 0) < 0)
            error("Error receiving message from client");

        printf("Received message from client: %s\n", message);

        // convert message to upper case
        for (int i = 0; message[i]; i++) {
            message[i] = toupper(message[i]);
        }

        // send upper case message back to client
        if (send(client_fd, message, strlen(message), 0) < 0)
            error("Error sending message to client");

        close(client_fd);
    }

    return 0;
}