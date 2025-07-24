//FormAI DATASET v1.0 Category: Client Server Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080      // Port number for communication

void communicate(int socket) {
    char buffer[1024] = {0};
    printf("\n\nYou can start the chat\n\n");
    while (1) {
        // Read message from the client
        read(socket , buffer, 1024);
        printf("Received from client : %s",buffer );
        // Send message to the client
        printf("Enter message to send :");
        fgets(buffer, 1024, stdin); 
        send(socket , buffer , strlen(buffer) , 0 );
        memset(buffer, 0, 1024);
    }
}

int main(int argc, char const *argv[]) {
    int client_socket = 0;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};
    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    // Set socket address parameters
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    // Communication between client and server
    communicate(client_socket);
    return 0;
}