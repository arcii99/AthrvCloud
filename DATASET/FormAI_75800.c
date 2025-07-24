//FormAI DATASET v1.0 Category: Chat server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8888
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024
#define WELCOME_MESSAGE "Welcome to the Mind-Bending Chat Server!\n"
#define PROMPT "You: "
#define GOODBYE_MESSAGE "Thank you for using the Mind-Bending Chat Server!\nGoodbye!\n"

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE] = {0};
    char username[BUFFER_SIZE] = {0};
    bool connected = false;
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening on port %d...\n", PORT);
    printf(WELCOME_MESSAGE);
    
    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
    
    // Send welcome message to client
    send(new_socket, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE), 0);
    
    // Main chat loop
    while (1) {
        // If not connected, wait for user to enter username
        if (!connected) {
            send(new_socket, "Enter a username: ", strlen("Enter a username: "), 0);
            valread = read(new_socket, username, BUFFER_SIZE);
            username[strcspn(username, "\n")] = 0; // Remove trailing newline
            sprintf(response, "Welcome, %s!\n", username);
            send(new_socket, response, strlen(response), 0);
            connected = true;
        }
        // Else, wait for user input and send response
        else {
            send(new_socket, PROMPT, strlen(PROMPT), 0);
            valread = read(new_socket, buffer, BUFFER_SIZE);
            buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
            if (strcmp(buffer, "exit") == 0) {
                send(new_socket, GOODBYE_MESSAGE, strlen(GOODBYE_MESSAGE), 0);
                break;
            }
            sprintf(response, "Server: %s? That's a weird thing to say...\n", buffer);
            send(new_socket, response, strlen(response), 0);
        }
    }
    
    // Close connection and socket
    close(new_socket);
    close(server_fd);
    
    return 0;
}