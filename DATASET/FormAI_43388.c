//FormAI DATASET v1.0 Category: Socket programming ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>

int main(){

    //creating socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //defining server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(9002);

    //binding socket to address
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    printf("[+] Server binded to port 9002\n");

    //listening for client requests
    listen(server_socket, 5);
    printf("[+] Listening for incoming connections\n");

    //accepting client request
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);
    printf("[+] Accepted the client request\n");

    //sending message to client
    char *server_message = "Server: Hello! Welcome to the server.";
    send(client_socket, server_message, strlen(server_message), 0);

    //receiving message from client
    char client_message[1024];
    recv(client_socket, &client_message, sizeof(client_message), 0);
    printf("[+] Client: %s\n", client_message);

    //closing socket
    close(server_socket);

    return 0;
}