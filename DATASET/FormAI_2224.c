//FormAI DATASET v1.0 Category: Chat server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, num_clients = 0;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow multiple connections
    int opt = 1;
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

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Set up a buffer to store received messages
    char buffer[BUFFER_SIZE] = {0};

    // Continuously accept incoming connections and handle messages
    while(1) {
        printf("Waiting for connections...\n");

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Print message confirming connection
        printf("New client connected!\n");

        // Increment number of clients
        num_clients++;

        // Respond with welcome message
        char welcome_message[] = "Welcome to the Chat Room!\n";
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Continuously handle messages from the current client
        while(1) {
            // Read message from client
            ssize_t received_bytes = read(new_socket, buffer, BUFFER_SIZE);

            // Check for errors or disconnection
            if (received_bytes <= 0) {
                if (received_bytes == 0) {
                    printf("Client disconnected\n");
                } else {
                    perror("read");
                }

                // Decrement number of clients
                num_clients--;

                // Close socket associated with disconnected client
                close(new_socket);
                break;
            }

            // Print received message and broadcast to all other clients
            printf("received: %s\n", buffer);
            for (int i=0; i<num_clients; i++) {
                if (i != new_socket) {  // Don't send message back to sender
                    send(i, buffer, strlen(buffer), 0);
                }
            }

            // Clear buffer for next message
            memset(buffer, 0, BUFFER_SIZE);
        }
    }

    return 0;
}