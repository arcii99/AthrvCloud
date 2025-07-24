//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
// This is a program that demonstrates how to create a basic chat application using socket programming in C language
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) 
{ 
    int socketfd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    
    // Creating socket file descriptor 
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    }
    
    // Forcefully attaching socket to the PORT 
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, 
        sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
    
    // Binding socket with the port
    if (bind(socketfd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }
    
    // Listening to incoming connections
    if (listen(socketfd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    }
    
    // Accepting incoming connections
    if ((new_socket = accept(socketfd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    
    char reply[1024];
    while(1) {
        // Receiving the message from client
        valread = read( new_socket , buffer, 1024); 
        if (strcmp(buffer, "QUIT\n") == 0) {
            break;
        }
        printf("Received Message from Client: %s", buffer); 
        
        // Sending a reply
        printf("Reply: ");
        fgets(reply, 1024, stdin);
        send(new_socket , reply , strlen(reply) , 0 ); 
        memset(buffer, 0, 1024); // Clearing the buffer
        memset(reply, 0, 1024); // Clearing the reply
        
    }
    
    close(socketfd);
    return 0; 
}