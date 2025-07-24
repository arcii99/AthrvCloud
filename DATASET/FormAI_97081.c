//FormAI DATASET v1.0 Category: Chat server ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_address, client_address;
    char buffer[1024] = {0};
    int addrlen = sizeof(server_address);

    // Create server socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        printf("Alas, could not create server socket\n");
        return -1;
    }

    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        printf("Oh ho, could not set socket options\n");
        return -1;
    }

    // Set server address information
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind socket to server address
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0 ){
        printf("By my head, could not bind socket to address\n");
        return -1;
    }

    // Start listening for connections
    if(listen(server_socket, 3) < 0){
        printf("Oh, speak again, bright angel! Could not listen to connections\n");
        return -1;
    }

    printf("O happy dagger! Server listening on port 8080\n");

    // Accept incoming connections
    while(1){
        if((client_socket = accept(server_socket, (struct sockaddr *)&server_address, (socklen_t *)&addrlen)) < 0){
            printf("It is too rash, too unadvised, too sudden! Connection not accepted\n");
            return -1;
        }

        // Send message to client
        char message[] = "O serpent heart, hid with a flowering face!";
        send(client_socket, message, strlen(message), 0);
        printf("Good-night, good-night! Parting is such sweet sorrow. Sent message to client\n");

        // Receive message from client
        read(client_socket, buffer, 1024);
        printf("What's in a name? That which we call a rose. Received message from client: %s\n", buffer);

        // Close client socket
        close(client_socket);
    }

    return 0;
}