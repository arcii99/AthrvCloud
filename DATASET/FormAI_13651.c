//FormAI DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

int main(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0){
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to the client
    char *welcome_message = "Welcome to this medieval-style chat server!\n";
    send(new_socket, welcome_message, strlen(welcome_message), 0);

    // Start the chat loop
    while(1){
        valread = read(new_socket, buffer, 1024);
        if(strcmp(buffer, "bye\n")==0){
            char *bye_message = "Fare thee well, friend!\n";
            send(new_socket, bye_message, strlen(bye_message), 0);
            close(new_socket);
            break;
        }
        else{
            char *response = "Aye, that be a fine message!\n";
            send(new_socket, response, strlen(response), 0);
        }
        // Clear message buffer
        memset(buffer, 0, 1024);
    }

    return 0;
}