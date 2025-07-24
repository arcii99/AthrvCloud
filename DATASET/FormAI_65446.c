//FormAI DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int paranoid_socket() {
    int main_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (main_socket < 0) {
        perror("Error: Could not create socket!");
        exit(-1);
    }
    int opt = 1;
    if (setsockopt(main_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error: setsockopt failed!");
        exit(-1);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(main_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error: Could not bind socket!");
        exit(-1);
    }
    if (listen(main_socket, 3) < 0) {
        perror("Error: Could not listen on socket!");
        exit(-1);
    }
    printf("Server is listening on port %d\n", PORT);
    int client_socket;
    struct sockaddr_in client_address;
    int address_length = sizeof(client_address);
    if ((client_socket = accept(main_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_length)) < 0) {
        perror("Error: Could not accept client connection!");
        exit(-1);
    }
    int buffer_size = 1024;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        perror("Error: Could not allocate memory for buffer!");
        exit(-1);
    }
    while (1) {
        memset(buffer, 0, buffer_size);
        int bytes_received = recv(client_socket, buffer, buffer_size, 0);
        if (bytes_received < 0) {
            perror("Error: Could not receive message from client!");
            break;
        } else if (bytes_received == 0) {
            printf("Client disconnected from server\n");
            break;
        } else {
            printf("Received message from client: %s\n", buffer);
            int bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if (bytes_sent < 0) {
                perror("Error: Could not send message to client!");
                break;
            }
            printf("Sent message back to client: %s\n", buffer);
        }
    }
    free(buffer);
    close(client_socket);
    close(main_socket);
    return 0;
}

int main() {
    paranoid_socket();
    return 0;
}