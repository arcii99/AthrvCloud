//FormAI DATASET v1.0 Category: Socket programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 1234
#define MAX_CONNECTIONS 5

int main(){

    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        printf("Socket creation failed\n");
        return -1;
    }

    // Set socket options
    int opt = 1;
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        printf("Setsockopt failed\n");
        return -1;
    }

    // Set server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))){
        printf("Bind failed\n");
        return -1;
    }

    // Listen for connections
    if(listen(server_fd, MAX_CONNECTIONS)){
        printf("Listen failed\n");
        return -1;
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept connections and echo back received messages
    while(1){

        // Accept connection
        struct sockaddr_in client_addr;
        int addrlen = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
        if(client_fd == -1){
            printf("Accept failed\n");
            return -1;
        }
        printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Echo back received messages
        char buffer[1024] = {0};
        int valread = read(client_fd, buffer, 1024);
        if(strcmp(buffer, "exit\n") == 0){
            printf("Client %s:%d disconnected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            close(client_fd);
            break;
        }
        printf("Message received from %s:%d : %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
        send(client_fd, buffer, strlen(buffer), 0);
    }

    // Close socket
    close(server_fd);

    return 0;
}