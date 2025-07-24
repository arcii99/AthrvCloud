//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  

#define PORT 8000
#define BUFFER_SIZE 1024  

int main()  
{  
    struct sockaddr_in server_addr, client_addr;  
    int server_fd, client_fd;  
    char buffer[BUFFER_SIZE];  

    // Creating server socket 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {  
        perror("socket creation failed");  
        exit(EXIT_FAILURE);  
    } 

    // Set server address
    bzero(&server_addr, sizeof(server_addr));  
    server_addr.sin_family = AF_INET;       
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);    
    server_addr.sin_port = htons(PORT);       

    // Bind server address to socket
    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))==-1){  
        perror("bind failed");  
        exit(EXIT_FAILURE);  
    }    

    // Listen for incoming connections
    if(listen(server_fd, 10) ==-1){  
        perror("listen failed");  
        exit(EXIT_FAILURE);  
    }    

    printf("Server is listening on port %d\n", PORT); 

    // Accept incoming client connections
    while(1){  
        socklen_t client_size = sizeof(client_addr);  
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_size);  
        if (client_fd == -1) {  
            perror("accept failed");  
            continue;  
        }  

        printf("New client connected.\n"); 

        // Receive incoming messages from client
        while(1){  
            bzero(buffer, BUFFER_SIZE); 

            int message_len = recv(client_fd, buffer, BUFFER_SIZE, 0);  
            if (message_len==-1) {  
                perror("recv failed");  
                exit(EXIT_FAILURE);  
            }  

            if (message_len == 0) {  
                printf("Client disconnected.\n");  
                break;  
            }  

            printf("Received message: %s", buffer); 

            // Echo message back to client
            if(send(client_fd, buffer, strlen(buffer), 0) == -1){  
                perror("send failed");  
                exit(EXIT_FAILURE);  
            }  
        }  
        close(client_fd);  
    }  
    return 0;  
}