//FormAI DATASET v1.0 Category: Socket programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 9090
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

    int server_socket, new_socket;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in server_address, client_address;
    int opt = 1;
    int client_address_length = sizeof(client_address);
    
    // create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setting socket options failed");
        exit(EXIT_FAILURE);
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding socket to address failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listening for incoming connections failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for incoming connections on port %d...\n", PORT);
    
    while (1) {
        // accept incoming connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address_length)) < 0) {
            perror("Accepting incoming connection failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Incoming connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // read data from client
        int read_size;
        while ((read_size = recv(new_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            printf("Received data from client: %s\n", buffer);
            
            // send response to client
            if (send(new_socket, buffer, strlen(buffer), 0) < 0) {
                perror("Sending response to client failed");
                exit(EXIT_FAILURE);
            }
            
            memset(buffer, 0, BUFFER_SIZE); // reset buffer
        }
        
        if (read_size == 0) {
            printf("Client disconnected\n");
        } else if (read_size == -1) {
            perror("Receiving data from client failed");
            exit(EXIT_FAILURE);
        }
        
        close(new_socket); // close connection with client
    }
    
    return 0;
}