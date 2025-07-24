//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, client_fd, valread;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    char* hello = "Hello from server";
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    memset(&address, '0', sizeof(address));
       
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
       
    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
       
    printf("Proxy Server is listening on port %d...\n", PORT);
    
    while(1) {
        // Accept the incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address))<0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        
        printf("New connection accepted!\n");
        
        // Read the request from client
        valread = read(client_fd, buffer, 1024);
        printf("Client Request:\n%s\n",buffer);
        
        // Modify the request
        char modified_request[1024] = {0};
        sprintf(modified_request, "%s%s%s", "GET http://", argv[1], buffer + 4);
        printf("Modified request:\n%s\n", modified_request);
        
        // Connect to the server
        struct sockaddr_in serv_addr;
        int server_socket_fd, server_socket_valread;
        char server_socket_buffer[1024] = {0};
        
        if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }
       
        memset(&serv_addr, '0', sizeof(serv_addr));
       
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(80);
           
        // Convert IPv4 and IPv6 addresses from text to binary form
        if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0) {
            perror("inet_pton failed");
            exit(EXIT_FAILURE);
        }
       
        if (connect(server_socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connect failed");
            exit(EXIT_FAILURE);
        }
        
        // Send the modified request to the server
        send(server_socket_fd, modified_request, strlen(modified_request), 0);
        printf("Request sent to server:\n%s\n", modified_request);
        
        // Receive response from the server
        while ((server_socket_valread = read(server_socket_fd, server_socket_buffer, 1024)) > 0) {
            send(client_fd, server_socket_buffer, server_socket_valread, 0);
            memset(server_socket_buffer, 0, sizeof(server_socket_buffer));
        }
        
        printf("Response sent to client!\n");
        
        // Close the sockets
        close(server_socket_fd);
        close(client_fd);
    }
    
    return 0;
}