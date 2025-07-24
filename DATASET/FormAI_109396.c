//FormAI DATASET v1.0 Category: Simple Web Server ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080 // Port on which server will listen
#define ROOT_DIR "./" // Root directory of web server
#define BUF_SIZE 1024 // Buffer size for client requests

/*
    Function to handle incoming client requests
*/
void handle_request(int new_socket, struct sockaddr_in client_addr) {
    int read_size;
    char client_message[BUF_SIZE] = {0};
    char *method, *path, *protocol;

    // Receive client request
    read_size = recv(new_socket, client_message, BUF_SIZE, 0);
    if (read_size == 0){
        printf("Client disconnected\n");
        return;
    }

    // Parse client request
    method = strtok(client_message, " ");
    path = strtok(NULL, " ");
    protocol = strtok(NULL, "\r\n");

    // Normalize path by removing any leading slashes
    if (path[0] == '/') {
        memmove(path, path + 1, strlen(path));
    }

    // Generate full file path by appending root directory to path
    char file_path[strlen(ROOT_DIR) + strlen(path) + 1];
    snprintf(file_path, sizeof(file_path), "%s%s", ROOT_DIR, path);

    // Open file requested by client
    FILE* file = fopen(file_path, "rb");
    if (!file) {
        // If file not found, send 404 error message
        char response[] = "HTTP/1.1 404 Not Found\r\n\r\n";
        send(new_socket, response, strlen(response), 0);
        return;
    }

    // If file found, read contents of file into buffer
    char file_buffer[BUF_SIZE] = {0};
    int file_size = fread(file_buffer, sizeof(char), BUF_SIZE, file);

    // Close file and send response to client
    fclose(file);

    char response[BUF_SIZE + 256] = {0};
    snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n%s", file_size, file_buffer);
    send(new_socket, response, strlen(response), 0);

    // Log request details
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
    printf("%s %s %s %s %d\n", client_ip, method, path, protocol, file_size);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket for server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Prepare sockaddr_in structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Print message indicating server is ready
    printf("Server listening on port %d\n", PORT);

    while(1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Handle client request
        handle_request(new_socket, address);

        // Close connection with client
        close(new_socket);
    }

    return 0;
}