//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int client_socket = 0;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};
    char msg[1024] = {0};
    
    // Create the socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }
    
    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to server successfully!\n\n");
    
    while(1) {
        printf("Send a message to the server (or type 'quit' to exit): ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = 0; // Remove newline character
        
        if(strcmp(msg, "quit") == 0) {
            printf("\nGoodbye!\n");
            break;
        }
        
        send(client_socket, msg, strlen(msg), 0);
        printf("Message sent to server!\n\n");
        
        memset(buffer, 0, sizeof(buffer)); // Reset buffer
        read(client_socket, buffer, sizeof(buffer));
        printf("Server response: %s\n\n", buffer);
    }
    
    // Close the socket
    close(client_socket);
    return 0;
}