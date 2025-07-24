//FormAI DATASET v1.0 Category: Chat server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9000

int main(){
    int server_fd, client_fd, opt = 1, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "Welcome to the chat server";
       
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
       
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for incoming connections...\n");
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("Connected!\n");
    send(client_fd, message, strlen(message), 0);
    
    while(1){
        memset(buffer, 0, sizeof(buffer));
        valread = read(client_fd, buffer, 1024);
        if(strcmp(buffer, "exit") == 0){
            printf("Disconnected!\n");
            close(client_fd);
            break;
        }
        printf("%s\n", buffer);
        send(client_fd, buffer, strlen(buffer), 0 );
    }
    
    return 0;
}