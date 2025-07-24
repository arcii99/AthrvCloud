//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Linus Torvalds
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define DEFAULT_PORT 8080
#define BUFFER_SIZE 1024

void handle_connection(int client_socket){
    char buffer[BUFFER_SIZE];
    int read_size;

    while((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0){
        printf("Received message: %s\n", buffer);
        write(client_socket, buffer, strlen(buffer));
        memset(buffer, 0, BUFFER_SIZE);
    }
}

int main(int argc, char *argv[]){
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[BUFFER_SIZE];

    // Creating TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1){
        printf("Error creating socket\n");
        exit(1);
    }

    // Setting server socket address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(DEFAULT_PORT);

    // Binding server socket to address and port
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        printf("Error binding socket\n");
        exit(1);
    }

    // Listening for incoming connections
    listen(server_socket, 3);
    printf("Listening on port %d...\n", DEFAULT_PORT);

    // Handling incoming connections
    socklen_t client_address_size = sizeof(client_address);

    while(1){
        // Accepting incoming connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if(client_socket < 0){
            printf("Error accepting connection\n");
            exit(1);
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handling connection with client
        handle_connection(client_socket);

        // Closing connection with client
        close(client_socket);
        printf("Connection closed\n");
    }

    return 0;
}