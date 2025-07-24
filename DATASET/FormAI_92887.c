//FormAI DATASET v1.0 Category: Simple Web Server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define MAX_QUEUE_LEN 5
#define MAX_FILE_LEN 2048

int main(int argc, char *argv[]) {
    int server_socket, client_socket, read_len;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[MAX_FILE_LEN], http_response[MAX_FILE_LEN];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Failed to create socket");
        exit(EXIT_FAILURE);
    }
  
    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
  
    // Listen for clients
    if (listen(server_socket, MAX_QUEUE_LEN) < 0) {
        printf("Error while listening!");
        exit(EXIT_FAILURE);
    }
  
    // Server loop
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            printf("Error while accepting connection!");
            exit(EXIT_FAILURE);
        }
        
        // Read HTTP request
        read_len = read(client_socket, buffer, MAX_FILE_LEN-1);
        if (read_len < 0) {
            printf("Error while reading request!");
            exit(EXIT_FAILURE);
        }
        
        // Parse HTTP request
        buffer[read_len] = '\0';
        printf("%s", buffer);
        char *req_file = strtok(buffer, " ");
        req_file = strtok(NULL, " ");
        
        // Serve requested file
        int file_fd = open(req_file+1, O_RDONLY);
        if (file_fd < 0) {
            strcpy(http_response, "HTTP/1.1 404 Not Found\n\n<html><body><H1>File Not Found</H1></body></html>\n");
        } else {
            strcpy(http_response, "HTTP/1.1 200 OK\n\n");
            while ((read_len = read(file_fd, buffer, MAX_FILE_LEN-1)) > 0) {
                buffer[read_len] = '\0';
                strcat(http_response, buffer);
            }
            close(file_fd);
        }

        // Send HTTP response
        if (send(client_socket, http_response, strlen(http_response), 0) < 0) {
            printf("Error while sending response!");
            exit(EXIT_FAILURE);
        }
        
        // Close connection
        close(client_socket);
    }

    return 0;
}