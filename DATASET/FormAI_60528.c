//FormAI DATASET v1.0 Category: Client Server Application ; Style: shape shifting
// Shape-Shifting C Client Server Application

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to the Shape-Shifting Server! Enter a command to begin.\n";
    int shape = 0;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Constantly accept incoming connections and talk to clients
    while(1) {
        // Wait for a client to connect
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Send a welcome message to the client
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Keep talking to the client until they quit
        while(1) {
            // Receive a command from the client
            valread = read(new_socket, buffer, 1024);

            // Determine the shape of the command
            shape = strlen(buffer) % 3;

            // Send the appropriate response based on the shape of the command
            switch(shape) {
                case 0:
                    send(new_socket, "Your command had an even number of characters.\n", strlen("Your command had an even number of characters.\n"), 0);
                    break;
                case 1:
                    send(new_socket, "Your command had an odd number of characters.\n", strlen("Your command had an odd number of characters.\n"), 0);
                    break;
                case 2:
                    send(new_socket, "Your command had a length that is a multiple of three.\n", strlen("Your command had a length that is a multiple of three.\n"), 0);
                    break;
                default:
                    send(new_socket, "Sorry, I didn't understand your command.\n", strlen("Sorry, I didn't understand your command.\n"), 0);
            }

            // Clear the buffer
            memset(buffer, 0, sizeof(buffer));

            // Check if the client has quit
            if(valread == 0) {
                close(new_socket);
                break;
            }
        }
    }

    return 0;
}