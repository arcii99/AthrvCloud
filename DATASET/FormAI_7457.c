//FormAI DATASET v1.0 Category: Networking ; Style: complete
#include <stdio.h>      //For standard IO operations
#include <stdlib.h>     //For dynamic memory allocation operations
#include <string.h>     //For string handling functions
#include <sys/socket.h> //For socket creation and related operations
#include <netinet/in.h> //For handling internet addresses

#define PORT 8080       //Server's listening port

int main(){ 
    int server_fd, new_socket;      //File descriptors for server and client sockets
    struct sockaddr_in address;     //Server address struct
    int opt = 1;                    //Socket options
    int addrlen = sizeof(address);  //Size of server address struct
    char buffer[1024] = {0};        //Buffer for holding received messages
    char *hello = "Hello from server";   //Message to send to client

    //Socket creation and error handling
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){ 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    //Socket options and error handling
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){ 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    //Server address details
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    //Binding socket to address and error handling
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){ 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    //Listening for incoming connections and error handling
    if (listen(server_fd, 5) < 0){ 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    //Accepting incoming connections and error handling
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){ 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    //Reading message from client
    read(new_socket, buffer, 1024); 
    printf("Client message: %s\n", buffer); 

    //Sending message to client
    send(new_socket, hello, strlen(hello), 0 ); 
    printf("Hello message sent\n"); 

    //Closing sockets
    close(new_socket);
    close(server_fd);

    return 0; 
}