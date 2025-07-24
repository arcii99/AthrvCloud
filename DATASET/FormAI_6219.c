//FormAI DATASET v1.0 Category: Socket programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    
    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        printf("Wow, something went wrong!");
        exit(EXIT_FAILURE);
    }
    
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Oh no, setsockopt failed!");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        printf("Oops, bind failed!");
        exit(EXIT_FAILURE);
    }
    
    // Listening to incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Too bad, listen failed!");
        exit(EXIT_FAILURE);
    }
    
    printf("Wow, the server is listening on port %d...\n", PORT);
    
    // Accepting incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        printf("Oh no, accept failed!");
        exit(EXIT_FAILURE);
    }
    
    // Read incoming message
    valread = read(new_socket, buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket, hello, strlen(hello), 0);
    
    printf("Wow, we sent a message back to the client!\n");
    return 0;
}