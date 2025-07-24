//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main() {
    printf("Welcome to the Fun-TCP chatroom!\n");

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char greeting[] = "Welcome to the Fun-TCP chatroom!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Oops! Something went wrong. Couldn't create socket...\n");
        return 1;
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Oops! Something went wrong. Couldn't set socket options...\n");
        return 1;
    }

    // Set address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8888);

    // Bind the socket to localhost
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        printf("Oops! Something went wrong. Couldn't bind socket to localhost...\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Oops! Something went wrong. Couldn't listen for incoming connections...\n");
        return 1;
    }

    // Accept and handle incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        printf("Oops! Something went wrong. Couldn't accept incoming connection...\n");
        return 1;
    }

    // Send the greeting to the client
    send(new_socket, greeting, strlen(greeting), 0);
    printf("Greeting message sent to the client...\n");

    // Handle incoming messages from client
    while (1) {
        // Wait for incoming message from client
        valread = read(new_socket, buffer, 1024);

        // Handle message
        if (strcmp(buffer, "exit\n") == 0) {
            char goodbye[] = "Goodbye from the Fun-TCP chatroom!";
            send(new_socket, goodbye, strlen(goodbye), 0);
            break;
        } else if (strcmp(buffer, "knock knock\n") == 0) {
            char who[] = "Doctor\n";
            send(new_socket, who, strlen(who), 0);
        } else {
            char joke[] = "Why don't scientists trust atoms? Because they make up everything.\n";
            send(new_socket, joke, strlen(joke), 0);
        }

        // Reset buffer
        memset(buffer, 0, sizeof(buffer));
    }

    // Close the socket
    close(new_socket);
    printf("Socket closed...\n");

    return 0;
}