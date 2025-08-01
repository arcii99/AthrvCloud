//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1234

//function to initialize the server
void init_server(char *ip_address, int port)
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char *response = "OK";
        
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Forcefully attaching socket to the PORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip_address);
    address.sin_port = htons(port);
    
    // Forcefully attaching socket to the PORT
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Any number of clients can queue for this server
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for clients to connect...\n");
    
    // Accepting new client requests
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))>0) {
        
        printf("Client connected. Waiting for message...\n");
        
        // Reading data from the client
        valread = read(new_socket, buffer, 1024);
        
        printf("Message from client: %s\n", buffer);
        
        // Sending a response to the client
        send(new_socket, response, strlen(response), 0);
    }
}

int main()
{
    init_server("127.0.0.1", PORT);
    return 0;
}