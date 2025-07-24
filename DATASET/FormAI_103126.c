//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: active
/* This is a simple TCP/IP server program that listens for incoming client requests, accepts the connection, receives client data, and sends a response back to the client. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char *argv[]) {
    int server_fd, client_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // CREATE SOCKET FILE DESCRIPTOR
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // SET SOCKET OPTIONS TO REUSE ADDRESS AND PORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // BIND SOCKET TO PORT AND ADDRESS
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // LISTEN ON SOCKET FOR MAX 3 CLIENTS
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server is ready to receive data from any client at port %d...\n", PORT);

    // ACCEPT CLIENT CONNECTIONS AND RECEIVE DATA
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    printf("Connection established with client at IP address %s and port %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
    valread = read(client_fd, buffer, 1024);
    printf("Data received from client: %s\n",buffer );

    // SEND RESPONSE TO CLIENT
    send(client_fd, hello, strlen(hello), 0);
    printf("Hello message sent to client\n");

    // CLOSE CLIENT SOCKET AND SERVER SOCKET
    close(client_fd);
    close(server_fd);
    return 0;
}