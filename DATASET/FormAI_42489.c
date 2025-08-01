//FormAI DATASET v1.0 Category: Client Server Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void *connection_handler(void *);

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c, *new_sock;
    struct sockaddr_in server, client;
    char message[] = "Hello from server!";
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
    
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    
    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    puts("Bind done");
    
    // Listen
    listen(socket_desc, 3);
    
    // Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    
    while ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted");
        
        // Create new thread for each incoming connection
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = new_socket;
        
        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void*)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }
        
        puts("Handler assigned");
    }
    
    if (new_socket < 0) {
        perror("Accept failed");
        return 1;
    }
    
    return 0;
}

void *connection_handler(void *socket_desc) {
    // Get socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char client_message[2000];
    
    // Send message to client
    write(sock, "Greetings from server!", strlen("Greetings from server!"));
    
    // Receive message from client
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        // End of string marker
        client_message[read_size] = '\0';
        write(sock, client_message, strlen(client_message));
    }
    
    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("Receive failed");
    }
    
    // Free socket pointer
    free(socket_desc);
    
    return 0;
}