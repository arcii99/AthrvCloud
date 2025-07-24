//FormAI DATASET v1.0 Category: Simple Web Server ; Style: systematic
//A simple web server in C language
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(){
    int socket_desc, client_sock, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_desc == -1){
        printf("Could not create socket");
    }

    //Prepare the sockaddr in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    //Bind the socket to a specific port
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("bind failed. Error");
        return 1;
    }
    printf("bind done\n");

    //Listen for incoming connections
    listen(socket_desc, 3);

    //Accept incoming connection
    printf("Waiting for incoming connections...\n");
    int c = sizeof(struct sockaddr_in);

    while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))){
        printf("Connection accepted\n");
        //receive a message from client
        while((read_size = recv(client_sock, client_message, 2000, 0)) > 0){
            //Send a response to the client
            write(client_sock, client_message, strlen(client_message));
            memset(client_message, 0, 2000);
        }

        if(read_size == 0){
            printf("Client disconnected\n");
        }
        else if(read_size == -1){
            perror("recv failed");
        }
    }

    return 0;
}