//FormAI DATASET v1.0 Category: Socket programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    char *message;
     
    // Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
     
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
     
    // Bind
    if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("bind failed");
        return 1;
    }
     
    puts("bind done");
     
    // Listen
    listen(socket_desc , 3);
     
    // Accept incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    while ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted");
         
        // Send message to client
        message = "Hello Client, I have received your connection. But I have to go now, bye!\n";
        write(new_socket , message , strlen(message));
    }
     
    if (new_socket<0) {
        perror("accept failed");
        return 1;
    }
     
    return 0;
}