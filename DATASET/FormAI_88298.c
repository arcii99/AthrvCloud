//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: immersive
//Welcome to the Simple HTTP Proxy program!
//In this program, you will be able to proxy HTTP requests between a client and server. 
//First, we will start by including the necessary libraries:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Next, we will define some constants that will be used throughout the program:
#define BUFFER_SIZE 1024
#define PORT 8888
#define MAX_PENDING_CONNECTIONS 10

//Now, we will create a function that will handle the proxying of the HTTP requests:
void handle_connection(int client_socket) {
    int server_socket, bytes_received, bytes_sent;
    char buffer[BUFFER_SIZE], *p;
    struct sockaddr_in server_address;
    
    memset(&server_address, 0, sizeof(server_address)); //initialize memory
    
    //create socket for server connection
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }
    
    //configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);
    
    //connect to server
    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    //initialize buffers
    memset(buffer, 0, BUFFER_SIZE);
    
    //receive request from client
    if ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("Error receiving request from client");
        exit(EXIT_FAILURE);
    }
    
    //forward request to server
    p = buffer;
    while (bytes_received > 0) {
        if ((bytes_sent = send(server_socket, p, bytes_received, 0)) < 0) {
            perror("Error forwarding request to server");
            exit(EXIT_FAILURE);
        }
        bytes_received -= bytes_sent;
        p += bytes_sent;
    }
    
    //initialize buffers
    memset(buffer, 0, BUFFER_SIZE);
    
    //receive response from server
    p = buffer;
    while ((bytes_received = recv(server_socket, p, BUFFER_SIZE, 0)) > 0) {
        if ((bytes_sent = send(client_socket, p, bytes_received, 0)) < 0) {
            perror("Error forwarding response to client");
            exit(EXIT_FAILURE);
        }
        p += bytes_received;
    }
    
    //close sockets
    close(client_socket);
    close(server_socket);
}

//Finally, we will create the main function that will listen for incoming connections and handle them:
int main(int argc, char *argv[]) {
    int server_socket, client_socket, client_address_len;
    struct sockaddr_in server_address, client_address;
    
    //create socket for server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }
    
    //configure server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    //bind socket to server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }
    
    //listen for incoming connections
    if (listen(server_socket, MAX_PENDING_CONNECTIONS) < 0) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    //main loop to handle connections
    while (1) {
        client_address_len = sizeof(client_address);
        
        //accept incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len)) < 0) {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }
        
        //handle connection
        handle_connection(client_socket);
    }
    
    //close socket and exit
    close(server_socket);
    return 0;
}