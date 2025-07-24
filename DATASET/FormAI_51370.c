//FormAI DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQ_LEN 1024
#define MAX_RESP_LEN 1024

void handle_client_request(int client_socket);

int main(int argc, char* argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    // create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // bind the socket to localhost:8080
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_addr_len = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr*) &client_addr, (socklen_t*) &client_addr_len)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        printf("New client connected\n");
        handle_client_request(client_socket);

        // cleanup client socket
        close(client_socket);
        printf("Client connection closed\n");
    }

    // cleanup server socket
    close(server_socket);

    return 0;
}

void handle_client_request(int client_socket) {
    char req_buffer[MAX_REQ_LEN] = {0};
    read(client_socket, req_buffer, MAX_REQ_LEN); // read client request
    
    // parse client request
    char* method = strtok(req_buffer, " ");
    char* resource = strtok(NULL, " ");
    char* protocol = strtok(NULL, "\r\n");
    
    printf("Client request - method: %s, resource: %s, protocol: %s\n", method, resource, protocol);
    
    // prepare response
    char resp_buffer[MAX_RESP_LEN] = {0};
    strcpy(resp_buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    strcat(resp_buffer, "<html><body><h1>It works!</h1></body></html>");
    
    // send response
    write(client_socket, resp_buffer, strlen(resp_buffer));
}