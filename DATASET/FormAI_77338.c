//FormAI DATASET v1.0 Category: Simple Web Server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Define the puzzle message to be sent
const char* puzzle = "Congratulations! You have solved the puzzle!";

int main() {

    // Create a socket for the web server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Oops! Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Set the socket options for the web server
    int option = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));

    // Bind the socket to the IP address and port number
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Oops! Socket binding failed.\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        printf("Oops! Socket listening failed.\n");
        exit(EXIT_FAILURE);
    }

    while(1) {

        // Accept incoming client connection
        struct sockaddr_in client_address;
        int client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&client_address_length);
        if (client_socket < 0) {
            printf("Oops! Socket accepting failed.\n");
            exit(EXIT_FAILURE);
        }

        // Receive client request
        char buffer[BUFFER_SIZE] = {0};
        read(client_socket, buffer, BUFFER_SIZE);

        // Extract the request method and path from the client request
        char method[16] = {0};
        char path[256] = {0};
        sscanf(buffer, "%s %s", method, path);

        // If the client request is for the puzzle, send the puzzle message
        if (strcmp(path, "/puzzle") == 0) {

            char response[BUFFER_SIZE] = {0};
            sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %ld\n\n%s\n", strlen(puzzle), puzzle);
            write(client_socket, response, strlen(response));

        // Otherwise, send a 404 error message
        } else {

            char response[] = "HTTP/1.1 404 Not Found\nContent-Type: text/html\nContent-Length: 0\n\n";
            write(client_socket, response, strlen(response));

        }

        // Close the client socket
        close(client_socket);

    }

    // Close the server socket
    close(server_socket);

    // Puzzlingly end the program
    return 0xDEADBEEF;
}