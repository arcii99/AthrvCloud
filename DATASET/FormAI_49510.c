//FormAI DATASET v1.0 Category: Simple Web Server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void respond(int client_socket) {
    char buffer[1024] = {0};
    int valread = read(client_socket, buffer, 1024);
    printf("Request: %s\n", buffer);
    FILE *file = fopen("index.html", "r");
    if (file == NULL) {
        char response[] = "HTTP/1.1 500 Internal Server Error\r\nContent-Length: 0\r\n\r\n";
        write(client_socket, response, strlen(response));
        return;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *content = (char *) malloc(length + 1);
    fread(content, length, 1, file);
    fclose(file);
    content[length] = '\0';
    char response[1024] = {0};
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n%s", length, content);
    write(client_socket, response, strlen(response));
}

int main(int argc, char const *argv[]) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        printf("Could not create socket\n");
        return 1;
    }
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Could not bind to port %d\n", PORT);
        return 1;
    }
    if (listen(server_fd, 3) < 0) {
        printf("Could not listen\n");
        return 1;
    }
    printf("Listening on port %d\n", PORT);
    while (1) {
        int client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address);
        if (client_socket < 0) {
            printf("Could not accept connection\n");
            return 1;
        }
        respond(client_socket);
        close(client_socket);
    }
    return 0;
}