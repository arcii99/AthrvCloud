//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void serve_client(int client_socket) {
    char response_header[] = "HTTP/1.1 200 OK\r\n"
                              "Content-Type: text/html\r\n"
                              "\r\n";
    char response_text[] = "<html><body><h1>Romeo and Juliet Web Server</h1><p>O Romeo, Romeo! Wherefore art thou Romeo?</p></body></html>";
    
    // Send the HTTP response
    write(client_socket, response_header, strlen(response_header));
    write(client_socket, response_text, strlen(response_text));
    close(client_socket);
}

int main() {
    // Create the socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stderr, "Error creating server socket.\n");
        exit(1);
    }
    
    // Bind the socket to a port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error binding server socket.\n");
        exit(1);
    }
    
    // Start listening for client connections
    if (listen(server_socket, 5) < 0) {
        fprintf(stderr, "Error listening for client connections.\n");
        exit(1);
    }
    
    // Accept and serve clients as they come in
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket < 0) {
            fprintf(stderr, "Error accepting client connection.\n");
            continue;
        }
        serve_client(client_socket);
    }
    
    return 0;
}