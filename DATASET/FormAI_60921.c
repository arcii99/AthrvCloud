//FormAI DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

int main(){
    int server_socket, new_socket, ret;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buffer[1024];
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0){
        printf("ERROR: Socket creation failed.\n");
        return 1;
    }
    
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    ret = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(ret < 0){
        printf("ERROR: Could not bind to address.\n");
        return 1;
    }
    
    ret = listen(server_socket, MAX_CONNECTIONS);
    if(ret < 0){
        printf("ERROR: Could not listen on socket.\n");
        return 1;
    }
    
    printf("Server is listening on port %d.\n", PORT);
    
    while(1){
        socklen_t client_addr_len = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        
        if(new_socket < 0){
            printf("ERROR: Could not accept incoming connection.\n");
            continue;
        }
        
        printf("Client connected.\n");
        
        memset(buffer, '\0', sizeof(buffer));
        
        int bytes_received = recv(new_socket, buffer, sizeof(buffer), 0);
        if(bytes_received < 0){
            printf("ERROR: Failed to receive data from client.\n");
        } else {
            printf("Received data: %s\n", buffer);
        }
        
        char* response = "Hello from the server!";
        ret = send(new_socket, response, strlen(response), 0);
        if(ret < 0){
            printf("ERROR: Failed to send data to client.\n");
        }
        
        close(new_socket);    
    }
    
    close(server_socket);
    
    return 0;
}