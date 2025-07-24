//FormAI DATASET v1.0 Category: Socket programming ; Style: medieval
/* Medieval style C Socket programming example */

#include <stdio.h> // for input output functions
#include <stdlib.h> // for exit() function
#include <string.h> // for string manipulation functions
#include <sys/socket.h> // for socket(), bind(), listen(), accept() functions
#include <netinet/in.h> // for sockaddr_in and sockaddr structure
#include <arpa/inet.h> // for inet_ntoa() function
#include <unistd.h> // for read() and write() functions

int main(void) {
    int server_socket, client_socket; // socket file descriptors
    struct sockaddr_in server_address, client_address; // sockaddr_in structures for server and client addresses
    char buffer[1024] = {0}; // buffer to store data read from client
    int opt = 1; // option to set socket options

    // create TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        printf("Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Could not set socket options\n");
        exit(EXIT_FAILURE);
    }

    // set server address structure
    server_address.sin_family = AF_INET; // set address family
    server_address.sin_port = htons(4000); // set port number
    server_address.sin_addr.s_addr = INADDR_ANY; // set IP address

    // bind socket to server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Could not bind socket to address\n");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        printf("Could not listen for incoming connections\n");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for client connections...\n");

    // accept incoming client connection
    int client_address_length = sizeof(client_address);
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length)) == -1) {
        printf("Could not accept incoming client connection\n");
        exit(EXIT_FAILURE);
    }

    printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // receive data from client and print it on screen
    int bytes_read = read(client_socket, buffer, 1024);
    printf("Received data from client: %s\n", buffer);

    // send data to client
    char greeting[50] = "Hail and well met, traveler!";
    write(client_socket, greeting, strlen(greeting));

    // close client and server sockets
    close(client_socket);
    close(server_socket);

    return 0;
}