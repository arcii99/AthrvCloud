//FormAI DATASET v1.0 Category: Simple Web Server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_request(int client_sock) {
    char buffer[BUFFER_SIZE];
    int bytes_read = read(client_sock, buffer, BUFFER_SIZE - 1);
    buffer[bytes_read] = '\0';

    //parse HTTP request method and URL
    char *request_method = strtok(buffer, " ");
    char *request_url = strtok(NULL, " ");
    if (strcmp(request_url, "/") == 0) {
        request_url = "/index.html";
    }
    //open file
    char file_path[100] = "www";
    strcat(file_path, request_url);

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        //file not found, return 404 error
        char response[] = "HTTP/1.1 404 Not Found\r\n\r\n";
        write(client_sock, response, strlen(response));
    } else {
        //file found, return 200 OK response and file content
        char response[] = "HTTP/1.1 200 OK\r\n\r\n";
        write(client_sock, response, strlen(response));

        char file_buffer[BUFFER_SIZE];
        while (fgets(file_buffer, BUFFER_SIZE, file)) {
            write(client_sock, file_buffer, strlen(file_buffer));
        }
        fclose(file);
    }
    close(client_sock);
}

int main() {
    //create the server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Error creating server socket");
        exit(1);
    }

    //bind the socket to an address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding server socket");
        exit(1);
    }

    //listen for incoming connections
    if (listen(server_sock, 10) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server started, listening on port 8080\n");

    while (1) {
        //accept incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_len);

        if (client_sock == -1) {
            perror("Error accepting incoming connection");
            continue;
        }

        //handle incoming request in a separate thread
        handle_request(client_sock);
    }

    return 0;
}