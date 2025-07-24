//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Sherlock Holmes
// It was a brisk morning in London as Sherlock Holmes, the great detective, began to work on his latest case.
// He had been tasked with creating a simple HTTP proxy using the C programming language.
// Holmes knew that this would require a keen attention to detail as well as a bit of creativity.
// As he sat at his desk, he began to ponder how he could create a program that would meet the client's requirements.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 16384 // 16KB
#define MAX_URL_LENGTH 2048

void handle_error(char* message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int main(int argc, char* argv[]) {

    if (argc != 3){
        handle_error("Usage: ./proxy <port_number> <ip_address>\n");
    }

    int port_number = atoi(argv[1]);
    char* ip_address = argv[2];

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0){
        handle_error("Error creating socket\n");
    }

    // Bind IP address and port to socket
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0){
        handle_error("Error binding socket\n");
    }

    // Listen for incoming connections
    if (listen(server_socket, SOMAXCONN) < 0){
        handle_error("Error listening for connections\n");
    }

    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);

    while(1){

        // Accept incoming connection
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_length);
        if (client_socket < 0){
            handle_error("Error accepting connection\n");
        }

        char buffer[MAX_BUFFER];
        memset(buffer, 0, MAX_BUFFER);

        // Receive HTTP request from client
        recv(client_socket, buffer, MAX_BUFFER, 0);
        char url[MAX_URL_LENGTH];
        memset(url, 0, MAX_URL_LENGTH);
        sscanf(buffer, "GET %s", url);

        // Connect to server
        int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(server_socket < 0){
            handle_error("Error creating socket to server\n");
        }

        struct sockaddr_in server_address;
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(80);
        server_address.sin_addr.s_addr = inet_addr(url);

        if (connect(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0){
            handle_error("Error connecting to server\n");
        }

        // Send HTTP request to server
        send(server_socket, buffer, strlen(buffer), 0);

        // Receive HTTP response from server and send to client
        while(recv(server_socket, buffer, MAX_BUFFER, 0) > 0){
            send(client_socket, buffer, strlen(buffer), 0);
            memset(buffer, 0, MAX_BUFFER);
        }

        // Close connections
        close(client_socket);
        close(server_socket);
    }

    return 0;
}