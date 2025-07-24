//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 7000
#define MAX_MSG_SIZE 1024

int main() {
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        printf("Oops! Cannot create a socket!"); 
        return 1;
    }
 
    struct sockaddr_in server_address, client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(server_sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
        printf("Oops! Cannot bind to port %d!", PORT);
        return 1;
    }
 
    if (listen(server_sockfd, 5) != 0) {
        printf("Oops! Cannot listen on port %d!", PORT);
        return 1;
    }
 
    printf("Ready to accept incoming connections on port %d! :) \n", PORT);
    int client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, sizeof(client_address));
    char server_msg[MAX_MSG_SIZE] = "Hi there!";
    send(client_sockfd, server_msg, strlen(server_msg), 0);
    printf("Sent message: %s :) \n", server_msg);    
 
    char client_msg[MAX_MSG_SIZE] = {0};
    int bytes_read = recv(client_sockfd, client_msg, MAX_MSG_SIZE, 0);
    printf("Received message: %s! :) \n", client_msg);
    
    close(client_sockfd);
    close(server_sockfd);
    return 0;
}