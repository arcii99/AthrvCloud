//FormAI DATASET v1.0 Category: Chat server ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>

#define PORT 8080  //Define the port number that the server will use

int main(){
  
    int server_fd;    //Server file descriptor
    int new_socket;   //Newly created socket to maintain active connections
    int opt = 1;      
    struct sockaddr_in address;     //Address structure for the server
    int addrlen = sizeof(address);
    char buffer[1024] = {0};        //Buffer to hold incoming messages
    
    //Create the server socket using IPv4 protocol, TCP connection and set options
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;   //IPv4 protocol 
    address.sin_addr.s_addr = INADDR_ANY;   //Accept incoming connections from any available interfaces
    address.sin_port = htons( PORT );   //Convert port number to network byte order

    //Bind the socket with the server address and port
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0){
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    //Set the number of  simultaneous connections to handle with active queue
    if (listen(server_fd, 3) < 0){
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening at %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));  // Display server starting status 
    
    //Accept incoming connections from the clients and Establish server-client connection 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
    
    //Read incoming messages from clients
    while(1){
        memset(buffer, 0, 1024);  //Flush the buffer
        if (read( new_socket , buffer, 1024) == 0){
            printf("Client disconnected\n");   // Display client disconnected status
            break;  //Terminate the server socket
        }
        printf("Client says: %s\n", buffer);   //Display message from clients
        send(new_socket , buffer , strlen(buffer) , 0 );  //Send a message back to the client
    }
    return 0;
}