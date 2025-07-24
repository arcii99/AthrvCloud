//FormAI DATASET v1.0 Category: Simple Web Server ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// define the maximum size of the response buffer
#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char response[BUFF_SIZE], request[BUFF_SIZE];
    FILE *file_ptr;
    int bytes, port = 8080;
    socklen_t client_address_size = sizeof(client_address);

    // create the TCP socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // prepare the server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    // bind the server socket to the specified IP address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        return 1;
    }

    // accept incoming connections and serve static web pages
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // zero out the request and response buffers
        memset(request, 0, BUFF_SIZE);
        memset(response, 0, BUFF_SIZE);

        // receive the client's HTTP request
        if (recv(client_socket, request, BUFF_SIZE, 0) < 0) {
            perror("Receive failed");
            close(client_socket);
            continue;
        }

        // check if the requested file exists
        if ((file_ptr = fopen(request, "r")) == NULL) {
            // file not found, return 404 error message
            snprintf(response, BUFF_SIZE, "HTTP/1.1 404 Not Found\r\nContent-Length: %d\r\n\r\n<html><body><h2>404 Not Found</h2></body></html>", 46);
        } else {
            // file found, read its contents and return them in the HTTP response
            fseek(file_ptr, 0, SEEK_END);
            bytes = (int)ftell(file_ptr);
            fseek(file_ptr, 0, SEEK_SET);
            fgets(response + strlen(response), BUFF_SIZE - strlen(response), file_ptr);
            fclose(file_ptr);

            // format the HTTP response
            snprintf(response, BUFF_SIZE, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n%s", bytes, response);
        }

        // send the HTTP response to the client
        if (send(client_socket, response, strlen(response), 0) < 0) {
            perror("Send failed");
            close(client_socket);
            continue;
        }

        // close the client socket
        close(client_socket);
    }

    // close the server socket
    close(server_socket);

    return 0;
}