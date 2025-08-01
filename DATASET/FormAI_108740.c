//FormAI DATASET v1.0 Category: Client Server Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "Hello from the server side!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( 8080 );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening to incoming connections
    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for a connection...\n");

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0){
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection established!\n");

    char name[1024];

    // Receiving client name
    valread = read( new_socket , name, 1024);
    printf("\n");
    printf("Received name from client: %s\n",name);

    char welcome_message[1024];
    sprintf(welcome_message, "Hello, %s! %s", name, message);

    // Sending welcome message to client
    send(new_socket , welcome_message , strlen(welcome_message) , 0 );
    printf("\n");
    printf("Welcome message sent to client!\n");

    while(1){
        memset(buffer, 0, 1024);

        // Receiving client message
        valread = read( new_socket , buffer, 1024);
        printf("\n");
        printf("Received message from client: %s\n",buffer );

        if(strcasecmp(buffer, "exit") == 0){
            printf("Closing connection...\n");
            close(new_socket);
            close(server_fd);
            break;
        }

        char response[1024];
        sprintf(response, "Received your message: %s", buffer);

        // Sending response to client
        send(new_socket , response , strlen(response) , 0 );
        printf("\n");
        printf("Response sent to client!\n");
    }

    return 0;
}