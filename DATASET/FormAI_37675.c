//FormAI DATASET v1.0 Category: Chat server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(){
    int port = 8080;
    int max_clients = 10;

    // Create socket
    int server_fd;
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Bind socket to address
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on socket
    if(listen(server_fd, max_clients) < 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept connections
    int addrlen = sizeof(address);
    int client_fds[max_clients];
    int num_clients = 0;

    while(1){
        struct sockaddr_in client_address;
        int client_fd;

        // Accept new client connection
        if((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) < 0){
            perror("Accept failed");
            continue;
        }

        // Check for maximum number of clients
        if(num_clients == max_clients){
            printf("Too many clients, connection rejected\n");
            close(client_fd);
            continue;
        }

        // Check client IP address
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_address.sin_addr), ip, INET_ADDRSTRLEN);
        if(strcmp(ip, "127.0.0.1") == 0){
            printf("Connection from localhost rejected\n");
            close(client_fd);
            continue;
        }

        // Check client port
        if(ntohs(client_address.sin_port) < 1024){
            printf("Connection from privileged port rejected\n");
            close(client_fd);
            continue;
        }

        // Add client to list
        client_fds[num_clients++] = client_fd;
        printf("New client connected: %s:%d\n", ip, ntohs(client_address.sin_port));
    }
    return 0;
}