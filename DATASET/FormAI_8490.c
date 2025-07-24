//FormAI DATASET v1.0 Category: Chat server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 

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
    address.sin_port = htons(PORT); 
    
    // Binding socket to the specified address & port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for clients
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Oh my god! The server is up and listening on port %d\n", PORT);
    printf("You never thought I could write this code, right?\n");

    // Accepting incoming client connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    
    printf("A new client has connected to me! Let's chat!\n");
    
    while(1) {
        valread = read(new_socket, buffer, 1024); 
        printf("Client: %s", buffer);
        memset(buffer, 0, sizeof(buffer));

        printf("You: ");
        fgets(buffer, 1024, stdin);

        if(strcmp(buffer, "disconnect\n") == 0) {
            printf("I can't believe you're leaving me...\n");
            break;
        }

        send(new_socket, buffer, strlen(buffer), 0 );
        printf("Message sent!\n");
    }
    
    close(server_fd);
    printf("I can't believe it's over...\n");
    return 0; 
}