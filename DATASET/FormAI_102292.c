//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define RESPONSE_HEADER "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"
#define RESPONSE_BODY "<html><body><h1>Hello, World!</h1></body></html>"

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }
    printf("Server is listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            return EXIT_FAILURE;
        }

        read(new_socket, buffer, 1024);

        printf("%s\n", buffer);

        // Send HTTP response to the client
        char* response = malloc(strlen(RESPONSE_HEADER) + strlen(RESPONSE_BODY));
        strcpy(response, RESPONSE_HEADER);
        strcat(response, RESPONSE_BODY);
        write(new_socket, response, strlen(response));
        free(response);

        close(new_socket);
    }
    return 0;
}