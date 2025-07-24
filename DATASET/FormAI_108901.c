//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Sherlock Holmes
//The Case of the Simple HTTP Proxy

//Our story begins at 221b Baker Street, where Sherlock Holmes and Dr. John Watson are huddled around their computer screens, investigating a case of internet theft. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PROXY_PORT 8888
#define SERVER_PORT 80

int main(){
    int proxy_socket, server_socket, client_socket;
    struct sockaddr_in proxy_addr, server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    //Create proxy socket
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        printf("Error creating proxy socket.\n");
        exit(1);
    }

    //Prepare the proxy address structure
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PROXY_PORT);

    //Bind the proxy socket to the address
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        printf("Error binding proxy socket.\n");
        exit(1);
    }

    //Listen for incoming connections
    if (listen(proxy_socket, 10) == -1){
        printf("Error listening on proxy socket.\n");
        exit(1);
    }
    printf("Listening for incoming connections on port %d.\n", PROXY_PORT);

    //Accept incoming connections and start proxying
    while (1) {
        //Accept connection from client
        socklen_t client_addr_length = sizeof(client_addr);
        client_socket = accept(proxy_socket, (struct sockaddr*)&client_addr, &client_addr_length);
        if (client_socket == -1) {
            printf("Error accepting connection from client.\n");
            continue; //Skip to next iteration of loop
        }

        printf("Accepted connection from client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //Create server socket
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == -1) {
            printf("Error creating server socket.\n");
            exit(1);
        }

        //Prepare the server address structure
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("192.168.1.1"); //Replace with actual server IP address
        server_addr.sin_port = htons(SERVER_PORT);

        //Connect to server
        if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
            printf("Error connecting to server.\n");
            exit(1);
        }

        printf("Connected to server.\n");

        //Read client request and forward to server
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) > 0 ) {
            printf("Received request from client:\n%s\n", buffer);
            if (send(server_socket, buffer, strlen(buffer), 0) < 0){
                printf("Error sending request to server.\n");
                exit(1);
            }
            printf("Forwarded request to server.\n");
        }

        //Read server response and forward to client
        if (recv(server_socket, buffer, BUFFER_SIZE, 0) > 0 ){
            printf("Received response from server:\n%s\n", buffer);
            if (send(client_socket, buffer, strlen(buffer), 0) < 0){
                printf("Error sending response to client.\n");
                exit(1);
            }
            printf("Forwarded response to client.\n");
        }

        //Close connections
        close(client_socket);
        close(server_socket);
    }

    return 0;
}