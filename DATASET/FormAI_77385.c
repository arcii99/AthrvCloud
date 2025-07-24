//FormAI DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sock_fd, status;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = {0};
    
    // create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // set server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // connect to server
    status = connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to server\n");
    
    while (1) {
        // clear message buffer
        memset(message, 0, BUFFER_SIZE);
        
        // get input from user
        printf("Enter message: ");
        fgets(message, BUFFER_SIZE, stdin);
        message[strcspn(message, "\n")] = 0; // remove newline character
        
        // send message to server
        status = send(sock_fd, message, strlen(message), 0);
        if (status < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Message sent: %s\n", message);
        
        // receive response from server
        memset(buffer, 0, BUFFER_SIZE);
        status = recv(sock_fd, buffer, BUFFER_SIZE, 0);
        if (status < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Server response: %s\n", buffer);
    }
    
    return 0;
}