//FormAI DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while(1) {
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }

        // Process the buffer here
        printf("Received message: %s\n", buffer);

        // Send response back to client
        char response[] = "Hello client!";
        send(client_socket, response, strlen(response), 0);

        memset(buffer, 0, BUFFER_SIZE);
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if(listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections
    while(1) {
        if((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }

        // Handle client connection in a new process
        pid_t pid = fork();

        if(pid == 0) { // child process
            close(server_socket);
            handle_client(client_socket);
            return 0;
        }
        else if(pid < 0) { // fork error
            perror("Fork error");
            exit(EXIT_FAILURE);
        }
        else { // parent process
            close(client_socket);
        }
    }

    return 0;
}