//FormAI DATASET v1.0 Category: Networking ; Style: genious
/*
 * Program: Genius Networking Example
 * Author: [Your Name]
 * Date: [Date]
 * Description: A program that demonstrates socket programming in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        return -1;
    }

    // set server information
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address and port
    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Bind failed\n");
        return -1;
    }

    // listen for incoming connections
    if (listen(sock, 3) < 0) {
        printf("Listen failed\n");
        return -1;
    }

    printf("Server listening on port %d...\n", PORT);

    // accept incoming connections
    struct sockaddr_in client_address;
    int client_sock, address_len = sizeof(client_address);
    char buffer[MAX_BUFFER_SIZE] = {0};

    while ((client_sock = accept(sock, (struct sockaddr *)&client_address, (socklen_t*)&address_len))) {
        printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // read data from client
        int read_size = 0;
        while ((read_size = recv(client_sock, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
            printf("Received message from client: %s\n", buffer);

            // echo back to client
            if (send(client_sock, buffer, strlen(buffer), 0) < 0) {
                printf("Send failed\n");
                break;
            }

            memset(buffer, 0, MAX_BUFFER_SIZE);
        }

        // client disconnected
        printf("Client disconnected\n");
        close(client_sock);
    }

    return 0;
}