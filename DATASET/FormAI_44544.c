//FormAI DATASET v1.0 Category: Chat server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to the chat server! Type 'exit' to quit.";

    // create the socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // set socket address and bind it to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // send welcome message to client
    send(new_socket, welcome_message, strlen(welcome_message), 0);

    // chat loop
    while(1) {
        // read message from client
        valread = read(new_socket, buffer, 1024);
        if (valread == 0) {
            // client disconnected
            printf("Client disconnected\n");
            break;
        } else if (strncmp(buffer, "exit", 4) == 0) {
            // client wants to exit
            printf("Client exited\n");
            break;
        } else {
            // print client message
            printf("Client: %s", buffer);

            // get user input and send it to client
            printf("Server: ");
            fgets(buffer, 1024, stdin);
            send(new_socket, buffer, strlen(buffer), 0);
        }
    }

    // close sockets
    close(new_socket);
    close(socket_fd);

    return 0;
}