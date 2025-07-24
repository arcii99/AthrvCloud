//FormAI DATASET v1.0 Category: Networking ; Style: introspective
// This C networking program demonstrates the use of sockets to create a basic chat program between a server and client. 
// The program will allow the client to connect to the server and send messages that will be echoed back to the client.

#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];
    
    // Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
        printf("Could not create socket");
    }
    
    // Prepare server sockaddr_in structure 
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
    
    // Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0){
        puts("bind failed");
        return 1;
    }
    puts("bind done");
    
    // Listen
    listen(socket_desc , 3);
    
    // Accept incoming connections
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) ){
        puts("Connection accepted");
        
        // Communication with the client
        while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 ){
            write(client_sock , client_message , strlen(client_message));
        }
        
        if(read_size == 0){
            puts("Client disconnected");
            fflush(stdout);
        }
        else if(read_size == -1){
            perror("recv failed");
        }
    }
    
    if(client_sock < 0){
        perror("accept failed");
        return 1;
    }
    
    return 0;
}