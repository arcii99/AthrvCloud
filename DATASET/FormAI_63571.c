//FormAI DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
  
int main(int argc, char *argv[]) 
{ 
    // Create a socket 
    int server_socket = socket(AF_INET, SOCK_STREAM, 0); 
    if (server_socket == -1) 
    { 
        printf("Could not create socket."); 
        return 1; 
    } 
     
    // Address for the server 
    struct sockaddr_in server_address; 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; // Accept any incoming address 
    server_address.sin_port = htons(8080); // Use port 8080
  
    // Bind the socket to the specified address and port 
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        printf("Binding failed."); 
        return 1; 
    } 
     
    // Listen for incoming requests 
    if (listen(server_socket, 5) < 0) // Only 5 clients can wait in queue 
    { 
        printf("Listening failed."); 
        return 1; 
    } 
     
    // Accept incoming clients 
    int new_socket, length; 
    struct sockaddr_in client_address; 
    length = sizeof(client_address); 
    char *message; 
    while (new_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&length)) 
    { 
        // Get client IP address and port 
        char *client_ip = inet_ntoa(client_address.sin_addr); 
        int client_port = ntohs(client_address.sin_port); 
         
        // Send message to client 
        message = "Connected to server."; 
        send(new_socket, message, strlen(message), 0); 
         
        // Receive HTTP GET request from client 
        char buffer[30000] = {0}; 
        read(new_socket, buffer, 30000); 
         
        // Send HTTP response to client 
        char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!"; 
        write(new_socket, response, strlen(response)); 
        printf("Response sent to %s:%d\n", client_ip, client_port); 
    } 
     
    if (new_socket < 0) 
    { 
        printf("Acceptance failed."); 
        return 1; 
    } 
     
    close(server_socket); 
     
    return 0; 
}