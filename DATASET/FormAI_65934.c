//FormAI DATASET v1.0 Category: Client Server Application ; Style: lively
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  

#define PORT_NUM 9999 // port number
#define BUFFER_SIZE 1024 // buffer size  

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int len, bytes_recv, bytes_sent;

    // create server socket  
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        return 1;
    }

    // set server address  
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT_NUM);

    // bind server socket  
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("socket bind failed");
        return 1;
    }

    // listen for incoming connections  
    if (listen(server_fd, 5) < 0) {
        perror("socket listen failed");
        return 1;
    }

    printf("Server is running and waiting for incoming connections...\n");

    // accept incoming connection  
    int client_addr_len = sizeof(client_addr);
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
        perror("socket accept failed");
        return 1;
    }

    printf("Connected to a client at %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // receive data from the client  
    bytes_recv = recv(client_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_recv < 0) {
        perror("socket receive failed");
        return 1;
    }

    printf("Received message from client: %s\n", buffer);

    // send a response to the client  
    char response[] = "Hello from the server!";  
    bytes_sent = send(client_fd, response, strlen(response), 0);
    if (bytes_sent < 0) {
        perror("socket send failed");
        return 1;
    }

    printf("Sent response to client: %s\n", response);

    // close sockets  
    close(client_fd);
    close(server_fd);

    return 0;
}