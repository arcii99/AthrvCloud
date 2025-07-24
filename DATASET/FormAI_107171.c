//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd, new_sock_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int client_addr_len = sizeof(client_addr);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
      
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    // Setting options for the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
      
    // Binding the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(sockfd, 3) < 0) { // Allow up to 3 simultaneous client connections
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    if ((new_sock_fd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&client_addr_len)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    if (read(new_sock_fd, buffer, 1024) == 0) {
        printf("Client disconnected\n");
    }
    printf("Received message: %s\n", buffer);
    send(new_sock_fd, hello, strlen(hello), 0);
    close(new_sock_fd);
    close(sockfd);
    return 0;
}