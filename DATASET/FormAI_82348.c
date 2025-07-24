//FormAI DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

#define MAX_CONNECTIONS 10 
#define PORT 8080 

int main(int argc, char **argv) {

    int socket_fd, client_socket, read_value; 
    struct sockaddr_in server_address, client_address; 
    char buffer[1024] = {0}; 

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        printf("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Attaching socket to port 8080
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(PORT); 

    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) { 
        printf("Bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Listening for incoming connections
    if (listen(socket_fd, MAX_CONNECTIONS) < 0) { 
        printf("Listen failed"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Server started.\n");

    while(1) { 

        // Accepting incoming connections
        int client_address_size = sizeof(client_address); 
        if ((client_socket = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_address_size))<0) { 
            printf("Accept failed"); 
            exit(EXIT_FAILURE); 
        } 

        printf("Incoming request from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        char welcome_message[1024] = "Welcome to the Simple Web Server!"; 
        send(client_socket, welcome_message, strlen(welcome_message), 0);

        // Receive requests from the client
        read_value = read(client_socket, buffer, 1024); 
        printf("%s\n", buffer); 

        char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 10\n\nHello World"; 
        send(client_socket, response, strlen(response), 0);

        printf("Response sent.\n");

        // Clear the buffer
        memset(buffer, 0, strlen(buffer)); 

        close(client_socket); 
    } 

    return 0; 
}