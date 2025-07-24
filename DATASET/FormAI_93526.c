//FormAI DATASET v1.0 Category: Chat server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char *argv[]) {  
    int server_socket, new_socket, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = "";
    char response[1024] = "";
    
    // Setup the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Socket creation error.\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Socket bind error.\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 1) < 0) {
        printf("Listen error.\n");
        exit(EXIT_FAILURE);
    }

    printf("Server is up and running!\n");

    client_len = sizeof(client_addr);

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
        if (new_socket < 0) {
            printf("Accept error.\n");
            exit(EXIT_FAILURE);
        }

        printf("Connection established with client: %d\n", new_socket);

        // Send welcome message
        strcpy(response, "Hello! You have connected to the server.\n");
        send(new_socket, response, sizeof(response), 0);

        while (1) {
            memset(&buffer, 0, sizeof(buffer));
            memset(&response, 0, sizeof(response));
            
            // Receive message from client
            if (recv(new_socket, buffer, 1024, 0) > 0) {
                printf("Client %d says: %s\n", new_socket, buffer);
                if (strcmp(buffer, "quit\n") == 0 || strcmp(buffer, "exit\n") == 0) {
                    break;
                }
                sprintf(response, "You said: %s", buffer);
                send(new_socket, response, sizeof(response), 0);
            }
        }

        // Close the connection with client
        close(new_socket);
        printf("Connection with client %d terminated.\n", new_socket);
    }

    // Close the server socket
    close(server_socket);
    printf("Server is shutting down.\n");
    
    return 0;
}