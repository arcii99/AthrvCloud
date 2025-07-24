//FormAI DATASET v1.0 Category: Chat server ; Style: artistic
/*

                Artistic Chat Server

Art knows no bounds, lines, or spaces. In the same vein, the chat server we create is not just any ordinary chat server. 
It is a blend of creativity, simplicity, and performance.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8000
#define BUFFER_SIZE 1024

typedef struct {
    int socket_fd;
    struct sockaddr_in address;
} client;

int main() {

    // Creating sockets and variables for the server
    int server_socket_fd, new_socket_fd, client_count = 0;
    struct sockaddr_in serv_address, cli_address;
    char buffer[BUFFER_SIZE] = {0};
    client client_list[10]; // Maximum number of clients

    // Creating the server socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address
    serv_address.sin_family = AF_INET;
    serv_address.sin_addr.s_addr = INADDR_ANY;
    serv_address.sin_port = htons(PORT);

    // Binding the server socket to the specified address and port
    if (bind(server_socket_fd, (struct sockaddr *)&serv_address, sizeof(serv_address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Starting the server to listen for incoming connections
    if (listen(server_socket_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    puts("Server is running... Waiting for incoming connections");

    while (1) {

        // Accepting a new connection
        int address_len = sizeof(cli_address);
        if ((new_socket_fd = accept(server_socket_fd, (struct sockaddr *)&cli_address, (socklen_t *)&address_len)) < 0) {
            perror("Acceptance failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected with socket fd: %d\n", new_socket_fd);

        // Adding the new client to the client list
        client new_client;
        new_client.socket_fd = new_socket_fd;
        new_client.address = cli_address;
        client_list[client_count++] = new_client;

        // Sending a greeting message to the client
        char* message = "Welcome to the Artistic Chat Server!";
        send(new_socket_fd, message, strlen(message), 0);

        // Receiving and broadcasting the received message to all clients
        while (read(new_socket_fd, buffer, BUFFER_SIZE) > 0) {
            printf("Received message ('%s') from client with socket fd: %d\n", buffer, new_socket_fd);
            for (int i = 0; i < client_count; i++) {
                if (client_list[i].socket_fd != new_socket_fd) {
                    send(client_list[i].socket_fd, buffer, strlen(buffer), 0);
                }
            }
            memset(buffer, 0, BUFFER_SIZE); // Clear buffer
        }
    }
    return 0;
}