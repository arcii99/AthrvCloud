//FormAI DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int client_socket = 0;
    struct sockaddr_in server_address;
    char message[1024] = {0};
    char buffer[1024] = {0};
    
    // Create Socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
       perror("Socket creation error");
       return -1;
    }
   
    // Set server address and port
    memset(&server_address, '0', sizeof(server_address)); 
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
       
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }
   
    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
       perror("Connection Failed");
       return -1;
    }
   
    // Send message to server
    strcpy(message, "Hello from client");
    send(client_socket, message, strlen(message), 0);
    printf("Message Sent From Client: %s\n", message);
   
    // Receive server response
    int valread = read(client_socket, buffer, 1024);
    printf("Message Received From Server: %s\n", buffer);
   
    return 0;
}