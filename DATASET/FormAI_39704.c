//FormAI DATASET v1.0 Category: Networking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define MAX_CONS 10
 
int main(int argc, char *argv[]) {
    int server_socket, new_socket, c;
    struct sockaddr_in server, client;
    char *message;
 
    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Could not create socket");
    }
     
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
     
    // Bind the socket to a port
    if (bind(server_socket, (struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("bind failed");
        return 1;
    }
     
    // Listen for incoming connections
    listen(server_socket, MAX_CONS);
     
    // Accept incoming connections
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    while ((new_socket = accept(server_socket, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted");
         
        // Reply to client with a message
        message = "Hello client! I have received your connection. And this message is configurable.";
        write(new_socket, message, strlen(message));
    }
     
    if (new_socket < 0) {
        perror("accept failed");
        return 1;
    }
     
    return 0;
}