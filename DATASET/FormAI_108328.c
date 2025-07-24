//FormAI DATASET v1.0 Category: Simple Web Server ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<ctype.h>

#define MAX_CONNECTIONS 5

void process_request(int connection_fd){
    char buffer[1024] = {0};
    int valread = read(connection_fd, buffer, 1024);

    char method[10], path[50], protocol[10];
    sscanf(buffer, "%s %s %s", method, path, protocol);

    if(strcasecmp(method, "GET") == 0){
        printf("HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
        printf("<html><body><h1>Hello, World!</h1></body></html>\n");
    } else{
        printf("HTTP/1.1 501 Not Implemented\nContent-Type: text/plain\n\n");
        printf("Server does not implement this method\n");
    }

    close(connection_fd);
}

int main(int argc, char *argv[]){
    //Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        printf("Socket creation failed!\n");
        exit(EXIT_FAILURE);
    }

    //Prepare sockaddr_in structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( 8080 );

    //Bind socket to address
    if(bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1){
        printf("Bind failed!\n");
        exit(EXIT_FAILURE);
    }

    //Listen for incoming connections
    if(listen(server_fd, MAX_CONNECTIONS) == -1){
        printf("Listen failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 8080...\n");

    //Accept incoming connections and process requests
    while(1){
        //Accept connection
        struct sockaddr_in client_address;
        int address_length = sizeof(client_address);
        int connection_fd = accept(server_fd, (struct sockaddr*)&client_address, (socklen_t*)&address_length);

        if(connection_fd == -1){
            printf("Accept failed!\n");
            exit(EXIT_FAILURE);
        }

        //Process request
        process_request(connection_fd);
    }

    return 0;
}