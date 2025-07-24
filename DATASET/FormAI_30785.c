//FormAI DATASET v1.0 Category: Socket programming ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG 1024
#define PORT 8080

int main() {
    int sock, client_sock, valread;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_MSG] = {0};
    char *greeting = "Welcome to the Socket Programming Example!";
    int opt = 1;
    int addrlen = sizeof(server_addr);
     
    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }
     
    // Set the socket options
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("Could not set socket options");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
     
    // Bind the socket to the given port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not bind socket");
        exit(EXIT_FAILURE);
    }
    printf("Socket is listening on port %d\n", PORT);
     
    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Could not listen");
        exit(EXIT_FAILURE);
    }
     
    while (1) {
        // Accept incoming connection
        if ((client_sock = accept(sock, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("Could not accept connection");
            exit(EXIT_FAILURE);
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
         
        // Send greeting message to the client
        send(client_sock, greeting, strlen(greeting), 0);
        printf("Greeting sent to the client\n");
         
        // Read the message from the client
        valread = read(client_sock, buffer, MAX_MSG);
        printf("Message received from the client: %s\n", buffer);
         
        // Send confirmation message to the client
        char *confirm = "Message received successfully!";
        send(client_sock, confirm, strlen(confirm), 0);
         
        printf("Confirmation message sent to the client\n");
        close(client_sock);
    }
    return 0;
}