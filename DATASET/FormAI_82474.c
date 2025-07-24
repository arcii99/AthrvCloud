//FormAI DATASET v1.0 Category: Socket programming ; Style: medieval
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

#define PORT 8080 

int main() 
{ 
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *medieval_response = "Hark ye, traveler! Ye have received my humble message, and forsooth, I shall send thee my biggest regards!";

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("Socket attachement to port failed"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    // Binding the socket to the specified address and port 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { 
        perror("Binding socket to address failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Listening to new connections 
    if (listen(server_fd, 3) < 0) { 
        perror("Listen operation failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Accepting new connections and sending a response 
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) { 
        printf("Connection established with a new client!\n"); 
        send(new_socket, medieval_response, strlen(medieval_response), 0 ); 
        printf("Response sent to the client\n"); 
        close(new_socket); 
    } 
    return 0; 
}