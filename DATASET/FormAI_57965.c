//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(){
    int server_socket, client_socket, n;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE] = {0};

    // create a socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // bind socket to localhost
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if(listen(server_socket, 3) < 0){
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for a client to connect...\n");

    // accept incoming connection
    socklen_t client_address_len = sizeof(client_address);
    if((client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len)) < 0){
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected with IP address: %s and port number: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    while(1){
        memset(buffer, 0, MAX_BUFFER_SIZE);

        // receive data from client
        if((n = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0)) < 0){
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        // if client disconnects
        if(n == 0){
            printf("Client disconnected\n");
            break;
        }

        // print received message
        printf("Message received from client: %s", buffer);

        // send back a response
        char* response = "Thanks for sending me a message!\n";
        send(client_socket, response, strlen(response), 0);
    }

    // close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}