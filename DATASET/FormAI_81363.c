//FormAI DATASET v1.0 Category: Socket programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_MESSAGE_LENGTH 1024

int main() {

    int server_socket_fd, new_socket_fd, opt = 1;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length = sizeof(client_address);
    char message_buffer[MAX_MESSAGE_LENGTH] = {0};

    // Creating socket file descriptor
    if((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to port 8080
    if(setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setting socket options failed");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding socket to IP address and port number
    if(bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if(listen(server_socket_fd, 3) < 0) {
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connections
    if((new_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, &address_length)) < 0) {
        perror("Socket accepting failed");
        exit(EXIT_FAILURE);
    }

    // Receiving message from client
    if(read(new_socket_fd, message_buffer, MAX_MESSAGE_LENGTH) < 0) {
        perror("Reading from socket failed");
        exit(EXIT_FAILURE);
    }

    printf("Received message from client: %s", message_buffer);

    // Sending response to client
    char response[] = "Hello Client! This is the server.";
    if(send(new_socket_fd, response, strlen(response), 0) < 0) {
        perror("Sending to socket failed");
        exit(EXIT_FAILURE);
    }

    // Closing sockets
    close(new_socket_fd);
    close(server_socket_fd);

    return 0;
}