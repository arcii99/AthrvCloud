//FormAI DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void handleConnection(int sockfd) {
    char buffer[1024] = {0};
    int valread = read(sockfd, buffer, 1024);
    printf("Received: %s\n", buffer);
    char response[1024] = "Hello from server!";
    write(sockfd, response, strlen(response));
}

int main() {
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
    
    printf("Server is running on port %d\n", PORT);
    
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        
        char *client_ip = inet_ntoa(address.sin_addr);
        printf("Connection accepted from %s:%d\n", client_ip, ntohs(address.sin_port));
        
        int pid = fork();
        if (pid == 0) { // child process
            close(server_fd);
            handleConnection(new_socket);
            exit(EXIT_SUCCESS);
        } else if (pid > 0) { // parent process
            close(new_socket);
        } else { // fork failed
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}