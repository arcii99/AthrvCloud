//FormAI DATASET v1.0 Category: Simple Web Server ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define PORT 8080
#define RESPONSE_SIZE 1024

void handle_client(int sockfd) {
    char buffer[1024] = {0};
    char response[RESPONSE_SIZE] = {0};
    char *message = "HTTP/1.1 200 OK\nContent-Type: text/html; charset=UTF-8\n\n<!DOCTYPE html><html><body><h1>Welcome to the Happy Web Server 😀🌞</h1></body></html>";

    read(sockfd, buffer, 1024);
    printf("[*] Request:\n%s\n", buffer);

    write(sockfd, message, strlen(message));

    printf("[+] Response:\n%s\n", message);

    close(sockfd);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("[*] Happy Web Server running on port %d 🎉🎆\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("[*] New client connected 🤝\n");

        handle_client(new_socket);

        printf("[*] Client disconnected 👋\n");
    }

    return 0;
}