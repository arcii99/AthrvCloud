//FormAI DATASET v1.0 Category: Client Server Application ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[1024] = "Hello, from server!";
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        printf("Failed to bind socket.\n");
        exit(1);
    }
    
    listen(server_socket, 5);
    printf("Server is listening...\n");
    
    while(1) {
        socklen_t client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
        printf("Connection established with client %d.\n", client_socket);
        
        int pid = fork();
        if(pid == 0) {
            while(1) {
                char received_message[1024];
                recv(client_socket, received_message, sizeof(received_message), 0);
                printf("Message received from client %d: %s\n", client_socket, received_message);
                if(strcmp(received_message, "bye") == 0) {
                    break;
                }
                
                send(client_socket, message, strlen(message), 0);
            }
            printf("Closing connection with client %d.\n", client_socket);
            close(client_socket);
            exit(0);
        } else {
            close(client_socket);
        }
    }
    
    return 0;
}