//FormAI DATASET v1.0 Category: Socket programming ; Style: Claude Shannon
/* 
 * This program demonstrates the functionality of sockets in C programming language. 
 * It creates a server that accepts incoming connections from clients and responds to them
 * based on the data that they send.
 * 
 * The program follows the coding style of Claude Shannon, one of the founding fathers
 * of modern communications theory.
 * 
 * Note: This program assumes that the server is running on the same machine as the client 
 * and that the server is listening on port number 8080. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> // for socket(), bind(), listen(), accept() functions
#include <arpa/inet.h> // for htons() function

int main(int argc, char *argv[]) {
    
    int server_socket, new_socket, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    int bytes_received;
    int option = 1;
    
    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Set the socket options
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));
    
    // Set the server address details
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    
    // Bind the socket to the server address
    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    
    // Listen for incoming connections
    listen(server_socket, 5);
    
    while(1) {
        // Accept a new connection
        client_len = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr*)&client_addr, (socklen_t*)&client_len);
        
        // Receive data from the client
        bytes_received = read(new_socket, buffer, 1024);
        
        if(bytes_received > 0) {
            // Process the data received from the client
            if(strcmp(buffer, "Hello") == 0) {
                // Send a response back to the client
                write(new_socket, "Hello there!", 12);
            } else if(strcmp(buffer, "How are you?") == 0) {
                // Send a response back to the client
                write(new_socket, "I am fine, thank you!", 19);
            } else if(strcmp(buffer, "What is your name?") == 0) {
                // Send a response back to the client
                write(new_socket, "My name is Claude Shannon!", 26);
            } else {
                // Send a response back to the client
                write(new_socket, "Sorry, I did not understand what you said!", 42);
            }
        }
        
        // Close the socket
        close(new_socket);
    }
    
    // Close the server socket
    close(server_socket);
    
    return 0;
}