//FormAI DATASET v1.0 Category: Client Server Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h> // for sockaddr_in
#include <string.h>     // for strlen

#define PORT 8080       // Port number for server

void handle_client(int client_socket);

int main(int argc, char **argv) {

    int socket_fd, client_socket, addr_len;
    struct sockaddr_in server_address, client_address;
    
    // Creating a socket file descriptor for server
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket.");
        exit(EXIT_FAILURE);   
    }
    
    // Assigning server attributes
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Binding the socket to the server address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("Error in binding socket to address.");
        exit(EXIT_FAILURE);   
    }
    
    // Listening to incoming client requests
    if (listen(socket_fd, 3) < 0) {
        perror("Error in listening to incoming requests.");
        exit(EXIT_FAILURE);   
    }
    printf("Server is listening on port %d.\n", PORT);
    
    while(1) {
        addr_len = sizeof(client_address);
        // Accepting incoming client requests
        if ((client_socket = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&addr_len))<0) {
            perror("Error in accepting incoming client connection.");
            exit(EXIT_FAILURE);   
        }

        // Handling client request
        handle_client(client_socket);
    }
    return 0;
}

void handle_client(int client_socket) {
    
    int valread;
    double num1, num2;
    char buffer[1024] = {0};
    
    // Reading client request
    valread = read(client_socket, buffer, 1024);
    printf("Client Message: %s\n", buffer);
    
    // Parsing client request and performing arithmetic operation
    if (sscanf(buffer, "%lf %lf", &num1, &num2) == 2) {
        double result;
        if (buffer[0] == '+') result = num1 + num2;
        else if (buffer[0] == '-') result = num1 - num2;
        else if (buffer[0] == '*') result = num1 * num2;
        else if (buffer[0] == '/') result = num1 / num2;
        else {
            printf("Invalid operator.\n");
            write(client_socket, "Invalid operator.\n", 19);
            close(client_socket);
            return;
        }
        char result_str[20];
        sprintf(result_str, "%.2lf\n", result);
        printf("Result: %s\n", result_str);
        write(client_socket, result_str, strlen(result_str));
    }
    else {
        printf("Invalid request format.\n");
        write(client_socket, "Invalid request format.\n", 25);
    }
    
    // Closing client socket
    close(client_socket);
}