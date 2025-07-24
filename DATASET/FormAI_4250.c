//FormAI DATASET v1.0 Category: Simple Web Server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void serve_client(int client_socket)
{
    char buffer[BUFFER_SIZE] = {0};
    int valread = read(client_socket, buffer, BUFFER_SIZE);
    printf("Received request from client:\n%s\n", buffer);

    char http_header[1024] = "HTTP/1.1 200 OK\r\n\n";
    char http_body[1024] = "<h1>Welcome to my simple web server!</h1>\n<p>This is just a demo, but with some more code you could serve any static content you'd like!</p>";
    send(client_socket, http_header, strlen(http_header), 0);
    send(client_socket, http_body, strlen(http_body), 0);
    printf("Sent response to client.\n");

    close(client_socket);
}

int main(int argc, char const *argv[])
{
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Web Server is now running on port %d...\n", PORT);
    while(1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        printf("New client connected with IP address: %s and port: %d\n", inet_ntoa((struct in_addr)address.sin_addr), ntohs(address.sin_port));
        serve_client(new_socket);
    }

    return 0;
}