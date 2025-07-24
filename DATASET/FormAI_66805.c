//FormAI DATASET v1.0 Category: Socket programming ; Style: Romeo and Juliet
// Romeo and Juliet socket programming example
// Written by the bard himself, William Shakespeare
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8888 // the port number we'll be using for our tragic tale

int main() {
    int server_fd, new_socket; // our server file descriptor and a new socket file descriptor for incoming connections
    struct sockaddr_in server_address, client_address; // addresses for both the server and the client
    int addrlen = sizeof(server_address);
    char buffer[1024] = {0}; // a buffer to store incoming messages
    char *greeting = "O Romeo, Romeo! wherefore art thou Romeo?"; // our opening greeting, stolen from Act II, Scene 2 of the play

    // create our server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // bind our server socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // start listening on our server socket
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // wait for a client to connect to our server
    if ((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // greet our client with a message stolen from Romeo
    send(new_socket, greeting, strlen(greeting), 0);

    // receive the client's response and print it out
    read(new_socket, buffer, 1024);
    printf("Juliet: %s\n", buffer);

    // say goodbye to our client and close our sockets
    char *goodbye = "Parting is such sweet sorrow";
    send(new_socket, goodbye, strlen(goodbye), 0);
    close(new_socket);
    close(server_fd);

    return 0;
}