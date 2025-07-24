//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 7777
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;
    
    // send a welcome message to the client
    char* welcome_message = "Welcome to the future!\n";
    send(client_socket, welcome_message, strlen(welcome_message), 0);
    
    while((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        
        // convert the buffer to uppercase
        for(int i=0; i<read_size; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        
        // send the converted message back to the client
        send(client_socket, buffer, strlen(buffer), 0);
    }
    
    if(read_size == 0) {
        printf("Client disconnected.\n");
        fflush(stdout);
    } else if(read_size == -1) {
        perror("recv failed");
    }
}

int main() {
    int server_socket, client_socket, c;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];
    time_t current_time;
    
    // create a socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        perror("socket creation failed");
        return -1;
    }
    
    // prepare the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // bind the server socket to the address
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        return -1;
    }
    
    // listen for incoming connections
    listen(server_socket, MAX_CLIENTS);
    
    printf("Waiting for clients...\n");
    
    // accept incoming connections
    c = sizeof(struct sockaddr_in);
    while((client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&c))) {
        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // fork a new process to handle the client
        if(fork() == 0) {
            close(server_socket); // child process doesn't need the server socket
            
            // handle the client
            handle_client(client_socket);
            
            exit(0); // exit from the child process
        }
        
        close(client_socket); // parent process doesn't need the client socket
    }
    
    if(client_socket < 0) {
        perror("accept failed");
        return -1;
    }
    
    return 0;
}