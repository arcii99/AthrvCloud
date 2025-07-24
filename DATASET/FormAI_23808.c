//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Ada Lovelace
// As a computer scientist, I am constantly pushing the boundaries of computer technology.
// Today, I present to you a unique example of a Simple Web Server written in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

    // create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to the server address
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // start listening for incoming connections
    listen(server_socket, 5);

    // wait for a client request, accept the connection
    int client_socket = accept(server_socket, NULL, NULL);

    // set response message and send to client
    char server_response[512] = "HTTP/1.1 200 OK\nContent-Type: text/html;charset=UTF-8\n\n<html><body><h1>Hello Ada Lovelace!</h1></body></html>\n";
    send(client_socket, server_response, strlen(server_response), 0);

    // close the socket and exit
    close(server_socket);
    return 0;
}