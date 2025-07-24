//FormAI DATASET v1.0 Category: Chat server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>  
#include <stdbool.h>  
#include <sys/socket.h> 
#include <arpa/inet.h>  
#include <unistd.h>     
#include <errno.h>      

#define PORT 8080
#define MAX_CLIENTS 10
#define MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    
    int server_fd, client_sockets[MAX_CLIENTS], client_socket, opt = true;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char messages[MAX_CLIENTS][MESSAGE_SIZE];
    memset(messages, 0, sizeof(messages));
    char buffer[MESSAGE_SIZE] = {0};
     
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
     
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is running on port %d\n", PORT);
    
    while(true) {
        
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        int max_fd = server_fd;
         
        for (int i = 0 ; i < MAX_CLIENTS ; i++) {
            client_socket = client_sockets[i];
            if (client_socket > 0) {
                FD_SET(client_socket , &readfds);
                if (client_socket > max_fd) {
                    max_fd = client_socket;
                }
            }
        }
        
        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }
         
        if (FD_ISSET(server_fd, &readfds)) {
            
            if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }
            
            printf("New client connected\n");
            
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = client_socket;
                    printf("Adding to list of sockets as %d\n" , client_socket);
                    break;
                }
            }
        }
          
        for (int i = 0; i < MAX_CLIENTS; i++) {
            
            client_socket = client_sockets[i];
             
            if (FD_ISSET(client_socket , &readfds)) {
                
                memset(buffer, 0, MESSAGE_SIZE);
                int num_bytes = read(client_socket, buffer, MESSAGE_SIZE);
                 
                if (num_bytes == 0) {
                    printf("Client %d disconnected\n", client_socket);
                    close(client_socket);
                    client_sockets[i] = 0;
                    memset(messages[i], 0, MESSAGE_SIZE);
                } else {
                    
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        
                        if (client_sockets[j] > 0 && client_sockets[j] != client_socket) {
                            
                            if (strcmp(buffer, messages[j]) != 0) {
                                
                                if (write(client_sockets[j], buffer, strlen(buffer)) != strlen(buffer)) {
                                    perror("Write failed");
                                }
                                
                                strcpy(messages[j], buffer);
                            } else {
                                printf("Message was not sent to client %d because it was already sent\n", 
                                client_sockets[j]);
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}