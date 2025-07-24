//FormAI DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    printf("Starting the server...\n");
    
    // Creating the socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1){
        printf("Failed to create socket :(\n");
        exit(1);
    }
    
    printf("Socket created successfully :)\n");
    
    // Setting up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    // Binding the socket to the address
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1){
        printf("Failed to bind socket :(\n");
        exit(1);
    }
    
    printf("Socket binded successfully :)\n");
    
    // Starting to listen for incoming connections
    if(listen(server_socket, 5) == -1){
        printf("Failed to listen :(\n");
        exit(1);
    }
    
    printf("Server is now listening :)\n");
    
    // Accepting incoming connections
    int client_socket;
    struct sockaddr_in client_address;
    int client_address_size = sizeof(client_address);
    char * message = "Welcome to my server, stranger :)";
    int message_size = strlen(message);
    
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address_size);
    
    printf("Incoming connection accepted :)\n");
    
    // Sending welcome message to client
    send(client_socket, message, message_size, 0);
    
    printf("Welcome message sent :)\n");
    
    // Receiving messages from client
    char buffer[1024] = {0};
    int read_size;
    
    while((read_size = read(client_socket, buffer, 1024)) > 0 ){
        printf("Received message from client: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    
    printf("Client disconnected :(\n");
    
    // Closing sockets
    close(client_socket);
    close(server_socket);
    
    return 0;
}