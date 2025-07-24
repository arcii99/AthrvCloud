//FormAI DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int socket_socket;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *hello = "Hello from client";
    int message_length;
    
    // create socket file descriptor
    if ((socket_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    // convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }
    
    // connect to server
    if (connect(socket_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    
    // send message to server
    message_length = strlen(hello);
    if(send(socket_socket, hello, message_length, 0) != message_length) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }
    printf("Message sent to server: %s\n", hello);
    
    // receive response from server
    if(read(socket_socket, buffer, MAX_BUFFER_SIZE) < 0) {
        perror("Read failed");
        exit(EXIT_FAILURE);
    }
    printf("Response from server: %s\n", buffer);
    
    // close socket
    close(socket_socket);
    return 0;
}