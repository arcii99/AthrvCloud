//FormAI DATASET v1.0 Category: Simple Web Server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char *message , client_message[2000];
    
    // Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8080 );
    
    // Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("bind failed");
        return 1;
    }
    puts("bind done");
    
    // Listen
    listen(socket_desc , 3);
    
    // Accept incoming connections
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) ) {
        puts("Connection accepted");
        
        // Send message to client
        message = "Hello! I am a curious web server";
        write(client_sock , message , strlen(message));
        
        // Receive a message from client
        while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 ) {
            // End of client message
            if (client_message[read_size-1] == '\n' && client_message[read_size-2] == '\r') {
                break;
            }
        }
        
        // Reply to client
        write(client_sock , "You said: " , 10);
        write(client_sock , client_message , strlen(client_message));
        
        close(client_sock);
    }
    
    // Close the socket
    close(socket_desc);
    return 0;
}