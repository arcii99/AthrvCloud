//FormAI DATASET v1.0 Category: Simple Web Server ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Defining the maximum buffer size to be received from client
#define MAX_BUFFER_SIZE 2048

// Function to handle incoming HTTP requests from clients
void handle_client_request(int client_socket) {
    
    char receive_buffer[MAX_BUFFER_SIZE] = {0};
    
    // Reading the incoming HTTP request from client
    int read_status = read(client_socket, receive_buffer, MAX_BUFFER_SIZE);
    
    if (read_status <= 0) {
        printf("Error: Failed to read incoming request from client.\n");
        return;
    }
    
    // Checking if the incoming request is valid
    if (strstr(receive_buffer, "HTTP/") != NULL) {
        printf("Incoming HTTP Request: %s\n", receive_buffer);
        
        // Preparing the response message to be sent back to client
        char* http_response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello World!";
        
        // Sending the http_response message to client
        int send_status = send(client_socket, http_response, strlen(http_response), 0);
        
        if (send_status == -1) {
            printf("Error: Failed to send HTTP response to client.\n");
            return;
        }
        printf("HTTP response sent to client successfully.\n");
    }
}

// Main function to start the web server
int main(int argc, char const *argv[]) {
    
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int address_len = sizeof(server_address);
    
    // Creating the socket for server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (server_socket == -1) {
        printf("Error: Failed to create server socket.\n");
        return -1;
    }
    
    // Setting the server socket configuration
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    
    // Binding the socket to the server address
    int bind_status = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    
    if (bind_status == -1) {
        printf("Error: Failed to bind server address to socket.\n");
        return -1;
    }
    printf("Server listening on port 8080...\n");
    
    // Listening for incoming connections from clients
    int listen_status = listen(server_socket, 5);
    
    if (listen_status == -1) {
        printf("Error: Failed to listen for incoming connections.\n");
        return -1;
    }

    // Handling incoming client connections and requests
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_len);
        
        if (client_socket == -1) {
            printf("Error: Failed to accept incoming client connection.\n");
            continue;
        }
        printf("Incoming connection from client accepted successfully.\n");
        
        // Handling the HTTP request from the client
        handle_client_request(client_socket);
        
        // Closing the client socket
        close(client_socket);
    }
    return 0;
}