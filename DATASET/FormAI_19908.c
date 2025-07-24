//FormAI DATASET v1.0 Category: Chat server ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>

#define PORT 9999

int main(){
   
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to the chat server!\n";
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Forcefully attaching socket to the specified port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Binding socket to specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    // Listening for incoming connection
    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    // Accepting incoming connection requests
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0){
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Sending welcome message to the new client
    send(new_socket, welcome_message, strlen(welcome_message), 0);
    printf("Client connected\n");

    while(1) {
        // Reading incoming message
        valread = read(new_socket, buffer, 1024);
        if(valread == 0) {
            printf("Connection closed\n");
            break;
        }
        printf("Client: %s\n",buffer );
        memset(buffer, 0, 1024);
        
        //Getting the message from server
        printf("Server: ");
        fgets(buffer, 1024, stdin);
        
        //Sending the message to the client
        send(new_socket, buffer, strlen(buffer), 0 );
        memset(buffer, 0, 1024);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}