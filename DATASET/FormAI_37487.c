//FormAI DATASET v1.0 Category: Client Server Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the server properties
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming client connections
    if (listen(server_fd, 3) < 0){
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");

    // Accept client connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("Socket accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established!\n");

    // Send a welcome message to the client
    char *welcome = "Welcome to my shape-shifting server!\n";
    send(new_socket, welcome, strlen(welcome), 0);

    // Receive data from the client and send a response
    char buffer[1024] = {0};
    while(1){
        valread = read(new_socket, buffer, 1024);
        if(valread <= 0){
            // terminate the connection when client closes it
            printf("Connection closed.\n");
            break;
        }

        printf("Client: %s", buffer);

        if(strstr(buffer, "square")){
            char *response = "I can transform into a square!\n";
            send(new_socket, response, strlen(response), 0);

        } else if(strstr(buffer, "triangle")){
            char *response = "I can transform into a triangle!\n";
            send(new_socket, response, strlen(response), 0);

        } else if(strstr(buffer, "circle")){
            char *response = "I can transform into a circle!\n";
            send(new_socket, response, strlen(response), 0);

        } else {
            char *response = "I don't know how to transform into that shape.\n";
            send(new_socket, response, strlen(response), 0);
        }

        memset(buffer, 0, 1024);
    }

    close(new_socket);
    close(server_fd);

    return 0;
}