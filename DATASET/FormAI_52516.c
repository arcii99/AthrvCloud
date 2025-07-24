//FormAI DATASET v1.0 Category: Networking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345 // port number
#define MAX_BUFFER_SIZE 1024 // maximum buffer size to receive data

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket file descriptor
    
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }
    
    struct sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address)); // clear server_address
    memset(&client_address, 0, sizeof(client_address)); // clear client_address
    
    server_address.sin_family = AF_INET; // IPv4
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    // bind socket to the specified address and port
    if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        return 1;
    }
    
    // make socket listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening on socket");
        return 1;
    }
    
    printf("Waiting for incoming connections on port %d...\n", PORT);
    
    socklen_t client_address_len = sizeof(client_address);
    int client_sockfd = accept(sockfd, (struct sockaddr*)&client_address, &client_address_len);
    
    if (client_sockfd < 0) {
        perror("Error accepting connection");
        return 1;
    }
    
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE); // clear buffer
    
    printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    
    // receive data from the client
    int bytes_received = recv(client_sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("Received %d bytes from the client: %s\n", bytes_received, buffer);
    
    // send a response to the client
    char response[] = "Hello client!";
    int bytes_sent = send(client_sockfd, response, strlen(response), 0);
    printf("Sent %d bytes to the client: %s\n", bytes_sent, response);
    
    close(client_sockfd); // close the client socket
    close(sockfd); // close the server socket
    return 0;
}