//FormAI DATASET v1.0 Category: Chat server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_info {
    int sock_fd;
    struct sockaddr_in client_addr;
    int active;
};

void init_clients(struct client_info clients[]) {
    for(int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].sock_fd = 0;
        clients[i].active = 0;
    }
}

int add_client(int sock_fd, struct sockaddr_in *client_addr, struct client_info clients[]) {
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i].active == 0) {
            clients[i].sock_fd = sock_fd;
            clients[i].client_addr = *client_addr;
            clients[i].active = 1;
            return i;
        }
    }
    return -1;
}

void remove_client(int client_index, struct client_info clients[]) {
    close(clients[client_index].sock_fd);
    clients[client_index].active = 0;
}

int receive_message(int client_index, char recv_buffer[], struct client_info clients[]) {
    int n = read(clients[client_index].sock_fd, recv_buffer, BUFFER_SIZE);
    if(n == 0) {
        remove_client(client_index, clients);
        return -1;
    }
    return n;
}

void send_message(int sender_index, char *message, struct client_info clients[]) {
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i].active && i != sender_index) {
            write(clients[i].sock_fd, message, strlen(message));
        }
    }
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *response = "Message received.\n";
    char recv_buffer[BUFFER_SIZE] = {0};
    struct client_info clients[MAX_CLIENTS];
    init_clients(clients);
    
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket.");
        exit(EXIT_FAILURE);
    }
    
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options.");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed.");
        exit(EXIT_FAILURE);
    }
    
    if(listen(server_fd, 3) < 0) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d.\n", PORT);
    
    while(1) {
        int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if(new_socket < 0) {
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }
        printf("New client connected.\n");
        
        int client_index = add_client(new_socket, &address, clients);
        if(client_index == -1) {
            printf("Too many clients connected, closing connection.\n");
            close(new_socket);
        }
        
        while(1) {
            int n = receive_message(client_index, recv_buffer, clients);
            if(n == -1) {
                printf("Client disconnected.\n");
                break;
            }
            printf("Received message: %s", recv_buffer);
            send_message(client_index, response, clients);
        }
    }
    
    return 0;
}