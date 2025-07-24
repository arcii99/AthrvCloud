//FormAI DATASET v1.0 Category: Chat server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome = "Welcome to the Cyberpunk Chat Server!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    send(new_socket, welcome, strlen(welcome), 0);
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        valread = read( new_socket , buffer, 1024);
        printf("%s\n",buffer );
        if(strcmp(buffer, "disconnect") == 0) {
            char *disconnect = "Disconnecting from the Cyberpunk Chat Server...";
            send(new_socket, disconnect, strlen(disconnect), 0);
            break;
        } else {
            char *response = "Received your message loud and clear!";
            send(new_socket, response, strlen(response), 0);
        }
    }
    return 0;
}