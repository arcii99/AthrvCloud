//FormAI DATASET v1.0 Category: Client Server Application ; Style: grateful
/* A Grateful C Client Server Application */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Initializing grateful server :D
    printf("Initializing Grateful Server...\n");
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *grateful_message = "Hey there, thanks for connecting!\n";
       
    // Creating socket file descriptor for grateful server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Setting grateful server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( 8080 );
       
    // Attaching grateful server to specified port
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
       
    // Waiting for grateful client to connect
    printf("Waiting for a Grateful Client to connect...\n");
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
       
    // Sending grateful message to connected client
    printf("Grateful Client has connected!\n");
    send(new_socket , grateful_message , strlen(grateful_message) , 0 );
    printf("Message sent!\n");

    // Receiving message from grateful client
    valread = read( new_socket , buffer, 1024);
    printf("Received message from Grateful Client: %s\n",buffer );
    return 0;
}