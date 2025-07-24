//FormAI DATASET v1.0 Category: Socket programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10

void *handle_client(void *arg);

int main(int argc, char *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    
    // create a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    // set up address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8888);
    
    // bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    pthread_t threads[MAX_CLIENTS];
    int thread_count = 0;
    
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        printf("Connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        
        // create a new thread for each client connection
        pthread_create(&threads[thread_count++], NULL, handle_client, (void *)&new_socket);
    }
    
    return 0;
}

void *handle_client(void *arg) {
    int sock = *(int *)arg;
    char buffer[1024] = {0};
    int valread;
    
    // read initial message from client
    valread = read(sock, buffer, 1024);
    printf("Message from client: %s\n", buffer);
    
    // send a message back to the client
    char *message = "Welcome to the server!";
    send(sock, message, strlen(message), 0);
    
    while (1) {
        // read messages from client
        valread = read(sock, buffer, 1024);
        if (valread == 0) {
            // client disconnected
            printf("Client disconnected\n");
            break;
        }
        printf("Message from client: %s\n", buffer);
        
        // echo message back to client
        send(sock, buffer, strlen(buffer), 0);
    }
    
    close(sock);
    return NULL;
}