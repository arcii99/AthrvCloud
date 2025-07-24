//FormAI DATASET v1.0 Category: Socket programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    printf("Welcome to the exciting world of Socket Programming!\n\n");
    printf("In this program, we will create a server using C Socket programming\n\n");
    
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    char hello[] = "Hello from server!";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation failed\n");
        return 0;
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    
    // Attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        printf("Socket binding failed\n");
        return 0;
    }

    // Listening to incoming connection requests
    if (listen(server_fd, 3) < 0) {
        printf("Socket listening failed\n");
        return 0;
    }
    
    printf("Server is now listening on port 8080...\n\n");
    
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        printf("Socket accept failed\n");
        return 0;
    }
    
    char buffer[1024] = {0};
    int valread = read(new_socket, buffer, 1024);
    printf("Received message: %s\n", buffer);
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    return 0;
}