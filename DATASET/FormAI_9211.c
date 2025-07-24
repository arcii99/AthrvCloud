//FormAI DATASET v1.0 Category: Chat server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_MSG_LENGTH 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_MSG_LENGTH] = {0};
    char* server_message = "Server connected successfully!";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Forcefully attaching socket to the specified port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Binding socket to the specified address and port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    // Send welcome message to the client
    send(new_socket, server_message, strlen(server_message), 0);
    
    // Receive message from client and send back its reverse
    while(1) {
        valread = read(new_socket, buffer, MAX_MSG_LENGTH);
        if (valread == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Client: %s", buffer);
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Connection closed by client\n");
            break;
        }
        int len = strlen(buffer);
        char reversed[len];
        int i,j;
        for (i = len-2 , j=0; i >= 0; i--, j++) {
            reversed[j] = buffer[i];
        }
        reversed[j] = '\n';
        send(new_socket, reversed, strlen(reversed), 0);
        memset(buffer, 0, MAX_MSG_LENGTH);
    }
    close(new_socket);
    close(server_fd);
    return 0;
}