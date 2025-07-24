//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
// "Simple Web Server" by Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define SERVICE_PORT 8080
#define HTML_FILE_PATH "index.html"

int main() {
    // Create socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Bind socket to port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(SERVICE_PORT);
    if (bind(server_sock, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Socket binding failed");
        close(server_sock);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) == -1) {
        perror("Listen failed");
        close(server_sock);
        return 1;
    }

    for (;;) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_sock = accept(server_sock, (struct sockaddr*)&client_address, &client_address_len);
        if (client_sock == -1) {
            perror("Accept failed");
            close(server_sock);
            return 1;
        }

        // Read client request
        char buffer[BUFFER_SIZE];
        read(client_sock, buffer, BUFFER_SIZE);

        // Extract file path from GET request
        char* path_start = strstr(buffer, "GET ") + 4;
        char* path_end = strstr(path_start, " HTTP/");
        char file_path[256];
        strncpy(file_path, path_start, path_end - path_start);
        file_path[path_end - path_start] = '\0';
        if (strlen(file_path) == 1) {
            strcat(file_path, HTML_FILE_PATH);
        }

        // Open requested file
        int file = open(file_path, O_RDONLY);
        if (file == -1) {
            perror("File opening failed");
            close(client_sock);
            continue;
        }

        // Send response header
        char response_header[256];
        sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
        write(client_sock, response_header, strlen(response_header));

        // Send file content
        char file_buffer[BUFFER_SIZE];
        int bytes_read;
        while ((bytes_read = read(file, file_buffer, BUFFER_SIZE)) > 0) {
            write(client_sock, file_buffer, bytes_read);
        }
        close(file);

        // Close connection
        close(client_sock);
    }

    return 0;
}