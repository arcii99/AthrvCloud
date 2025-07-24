//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

#define PORT 8000
#define BUFFER_SIZE 1024

void serve_client(int client_socket);

int main(){
    int server_socket, client_socket, addr_size;
    struct sockaddr_in server_address, client_address;

    // Creating the socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Server address initialization
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Binding the socket
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) != 0){
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listening for client connections
    if(listen(server_socket, 5) != 0){
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    printf("\nServer running on port %d...\n", PORT);

    // Handling client connections
    while(1){
        addr_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_size);
        if(client_socket < 0){
            perror("Failed to accept");
            exit(EXIT_FAILURE);
        }
        else{
            printf("\nReceived connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            serve_client(client_socket);
        }
        close(client_socket);
    }

    return 0;
}

void serve_client(int client_socket){
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];
    FILE *fp;

    memset(buffer, 0, BUFFER_SIZE);
    read(client_socket, buffer, BUFFER_SIZE);
    printf("\nClient request:\n%s\n", buffer);

    if(strncmp(buffer, "GET /", 5) == 0){
        fp = fopen("index.html", "r");
        if(fp == NULL){
            perror("Failed to open file");
            exit(EXIT_FAILURE);
        }
        else{
            memset(response, 0, BUFFER_SIZE);
            strcat(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
            fread(response+strlen(response), sizeof(char), BUFFER_SIZE-strlen(response), fp);
            write(client_socket, response, strlen(response));
        }
        fclose(fp);
    }
    else{
        memset(response, 0, BUFFER_SIZE);
        strcat(response, "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n");
        strcat(response, "<html><body><h1>Error 404: File Not Found</h1></body></html>");
        write(client_socket, response, strlen(response));
    }
}