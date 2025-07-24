//FormAI DATASET v1.0 Category: Simple Web Server ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    
    int server_socket, client_socket, error_check, read_check;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
    char *response_message = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

    //create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    //bind socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    error_check = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (error_check < 0) {
        printf("Error binding socket to port\n");
        exit(0);
    }

    //listen for incoming connections
    error_check = listen(server_socket, 3);
    if (error_check < 0) {
        printf("Error listening for incoming connections\n");
        exit(0);
    }

    //accept incoming connections
    socklen_t client_address_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
    if (client_socket < 0) {
        printf("Error accepting incoming connection\n");
        exit(0);
    }

    //receive data from client
    read_check = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (read_check < 0) {
        printf("Error receiving data from client\n");
        exit(0);
    }

    //send response to client
    error_check = send(client_socket, response_message, strlen(response_message), 0);
    if (error_check < 0) {
        printf("Error sending response to client\n");
        exit(0);
    }

    //close socket
    close(server_socket);

    return 0;
}