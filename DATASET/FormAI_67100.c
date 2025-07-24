//FormAI DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void serve_client(int client_socket) {
    char* message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Welcome to the Simple Web Server!</h1></body></html>\r\n";
    char request[1024];
    recv(client_socket, &request, sizeof(request), 0);
    send(client_socket, message, strlen(message), 0);
    close(client_socket);
}

int main(int argc, char* argv[]) {
    int server_socket, client_socket, address_len;
    struct sockaddr_in server_address, client_address;
 
    server_socket = socket(AF_INET , SOCK_STREAM , 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        return -1;
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        close(server_socket);
        return -1;
    }

    while (1) {
        listen(server_socket, 3);
 
        address_len = sizeof(struct sockaddr_in);
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&address_len);
        if (client_socket == -1) {
            perror("Error accepting connection");
            close(server_socket);
            return -1;
        }
        
        serve_client(client_socket);
    }
 
    close(server_socket);
    return 0;
}