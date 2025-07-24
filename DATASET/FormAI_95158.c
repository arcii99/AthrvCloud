//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){

    int server_fd, client_socket, valread;
    struct sockaddr_in address;
    int address_size = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server!";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        printf("Socket creation failed\n");
        exit(EXIT_FAILURE);
    }
    
    // Assigning IP address and PORT
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Attaching socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        printf("Bind failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Socket has been bound to %d\n", PORT);
    
    // Starting to listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Listen failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening for incoming connections...\n");
    
    // Accepting incoming connection
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address_size))<0) {
        printf("Accept failed\n");
        exit(EXIT_FAILURE);
    }
    printf("A new client has connected!\n");
    
    // Reading data from client
    valread = read(client_socket, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    
    // Sending data to client
    send(client_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    
    // Closing the connection
    close(server_fd);

    return 0;   
}