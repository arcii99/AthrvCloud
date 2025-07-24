//FormAI DATASET v1.0 Category: Chat server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char* welcome_message = "Welcome to the Chat Server!";

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind server socket to the address listeing on the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Begin listening for incomming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", welcome_message);

    // Continuously accept incoming connections and handle them as chat requests
    while(1) {

        // Accept incoming connection.
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected!\n");

        // Send welcome message to connecting client.
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Continuously receive messages from the connected client and reply with a message of our own.
        while(1) {
            // Receive message from client.
            memset(buffer, 0, sizeof(buffer));
            if (recv(new_socket, buffer, sizeof(buffer), 0) < 0) {
                perror("recv failed");
                exit(EXIT_FAILURE);
            }
            printf("Client: %s\n", buffer);

            // Check if the client wants to exit.
            if(strcmp(buffer, "\\q") == 0) {
                printf("Client has left the chat.\n");
                break;
            }

            // Reply to the client with an acknowledgement message.
            char* reply = "Received your message!"; 
            send(new_socket, reply, strlen(reply), 0);
        }
    }

    return 0;
}