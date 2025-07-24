//FormAI DATASET v1.0 Category: Simple Web Server ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define LISTEN_PORT 8080 
#define BUFFER_SIZE 1024

int main(){
    struct sockaddr_in server_addr, client_addr;
    int server_socket, client_socket, addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE], response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\nWelcome to my web server!";

    //Creating a socket for the server
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket creation failure");
        exit(EXIT_FAILURE);
    }

    //Set server address details
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(LISTEN_PORT);

    //Binding the socket to the local address and port
    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Bind failure");
        exit(EXIT_FAILURE);
    }

    //Listening for incoming connections
    if(listen(server_socket, 1) < 0){
        perror("Listen failure");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");

    while(1){
        //Accepting incoming connections
        if((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0){
            perror("Accept failure");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //Receiving data from the connected client
        memset(buffer, 0, sizeof(buffer));
        read(client_socket, buffer, BUFFER_SIZE);

        printf("%s\n", buffer);

        //Sending response to the client
        write(client_socket, response, sizeof(response)-1);
        
        //Closing the connection
        close(client_socket);
    }

    return 0;
}