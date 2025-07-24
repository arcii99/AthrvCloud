//FormAI DATASET v1.0 Category: Socket programming ; Style: thoughtful
// A Chat Room Server Program in C using sockets

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to the Chat Room!\n\n";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting options for socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    
    // Binding socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Chat Room Server is running on port %d...\n\n", PORT);
    
    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("A new user has joined the Chat Room!\n");

    // Sending the welcome message to the new user
    send(new_socket, welcome_message, strlen(welcome_message), 0 );

    while (1) {
        // Reading messages from the client
        valread = read(new_socket, buffer, 1024);
        printf("User: %s", buffer);
        memset(buffer, 0, sizeof(buffer));
        
        // Sending messages to the client
        printf("Server: ");
        fgets(buffer, 1024, stdin);
        send(new_socket, buffer, strlen(buffer), 0 );

        if (strncmp(buffer, "bye", 3) == 0) {
            printf("A user has left the Chat Room!\n");
            break;
        }
    }
    close(new_socket);
    close(server_fd);
    return 0;
}