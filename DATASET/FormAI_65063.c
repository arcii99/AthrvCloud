//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_PENDING_CONNECTIONS 5
#define MAX_MESSAGE_SIZE 1024

void handle_client(int client_socket) {
    char message[MAX_MESSAGE_SIZE];
    while(1) {
        memset(message, 0, MAX_MESSAGE_SIZE);
        int bytes_received = recv(client_socket, message, MAX_MESSAGE_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }
        printf("Received message: %s\n", message);

        // Process message
        char response[MAX_MESSAGE_SIZE];
        strcpy(response, "Processed message: ");
        strcat(response, message);

        // Send response
        int bytes_sent = send(client_socket, response, strlen(response), 0);
        if(bytes_sent <= 0) {
            break;
        }
        printf("Sent response: %s\n", response);
    }
    close(client_socket);
}

int main() {
    // Step 1: Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating server socket\n");
        exit(1);
    }

    // Step 2: Bind the socket to a port
    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_port = htons(SERVER_PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Error binding server socket to port %d\n", SERVER_PORT);
        exit(1);
    }

    // Step 3: Start listening for incoming connections
    if(listen(server_socket, MAX_PENDING_CONNECTIONS) == -1) {
        printf("Error listening for incoming connections\n");
        exit(1);
    }

    // Step 4: Handle incoming connections
    while(1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if(client_socket == -1) {
            printf("Error accepting incoming connection\n");
            continue;
        }

        printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        int child_pid = fork();
        if(child_pid == -1) {
            printf("Error forking child process\n");
            continue;
        }

        if(child_pid == 0) {
            // Child process
            handle_client(client_socket);
            exit(0);
        } else {
            // Parent process
            close(client_socket);
        }
    }

    // Step 5: Close the socket
    close(server_socket);

    return 0;
}