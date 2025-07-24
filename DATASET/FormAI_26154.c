//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, read_size;
    struct sockaddr_in server_address, client_address;
    char message[BUFFER_SIZE], client_reply[BUFFER_SIZE];
 
    // Creating socket file descriptor
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Server socket creation failed");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    // Bind the socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_socket, 3);

    printf("Waiting for incoming connections...\n");
 
    // Accept incoming connection
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address);
    if (client_socket < 0) {
        perror("Accept failed");
        exit(1);
    }

    printf("Connection accepted from %s:%d\n\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Receive data from the client
    while( (read_size = recv(client_socket, client_reply, BUFFER_SIZE, 0)) > 0 ) {

        printf("Client message: %s\n", client_reply);

        // Clear the buffer
        memset(message, 0, sizeof(message));

        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);

        // Send the message to the client
        send(client_socket, message, strlen(message), 0);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("Recv failed");
    }
     
    return 0;
}