//FormAI DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define ROOT "./public_html"
#define PORT 8080

void handle_client(int client_sock){
    char buffer[1024] = {0};
    int bytes_read = read(client_sock, buffer, 1024);

    if (bytes_read == -1){
        printf("Error reading from client socket");
        close(client_sock);
        return;
    }

    char* request = strtok(buffer, " "); // get HTTP request type (GET/POST/PUT/DELETE)
    char* path = strtok(NULL, " "); // get requested path

    if (strcmp(request, "GET") == 0) { // if GET request
        char file_path[255];
        sprintf(file_path, "%s%s", ROOT, path); // create file path

        struct stat file_stat;
        if (stat(file_path, &file_stat) == -1) { // check if file exists
            printf("File not found");
            close(client_sock);
            return;
        }

        int file_size = file_stat.st_size;

        char response[1024];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\nContent-Type: text/html\r\n\r\n", file_size); // create HTTP response headers

        write(client_sock, response, strlen(response)); // send HTTP response headers

        int file_fd = open(file_path, O_RDONLY); // open file
        char file_buffer[1024];

        while (1) {
            int bytes_read = read(file_fd, file_buffer, 1024); // read file
            if (bytes_read <= 0) break;
            write(client_sock, file_buffer, bytes_read); // send file
        }

        close(file_fd); // close file descriptor
    }
    close(client_sock); // close client socket
}

int main(int argc, char const *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;

    // create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Could not create socket");
        return -1;
    }

    // bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Could not bind to port");
        return -1;
    }

    // listen for incoming connections
    if (listen(server_sock, 3) < 0) {
        printf("Could not listen on socket");
        return -1;
    }

    printf("Server is running on port %d...\n", PORT);

    while (1) {
        int client_size = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t*)&client_size)) < 0) {
            printf("Error accepting connection");
            return -1;
        }

        printf("New connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // handle incoming client request
        handle_client(client_sock);
    }
    return 0;
}