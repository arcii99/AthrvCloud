//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // create a socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to a specific IP and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // start listening for incoming connections
    listen(server_socket, 5);

    // accept an incoming connection
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    // send data to the client
    char server_message[256] = "You have reached the server!";
    send(client_socket, server_message, strlen(server_message), 0);

    // close the socket
    close(server_socket);
    return 0;
}