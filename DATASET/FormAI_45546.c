//FormAI DATASET v1.0 Category: Networking ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

const int PORT = 8080;

int main(){
    // create a socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to the specified IP and port
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // listen for incoming connections
    listen(server_socket, 5);

    printf("Waiting for connections...\n");

    while(1){
        // accept incoming connections
        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);

        // send a welcome message to the client
        char welcome_message[] = "Welcome to my chat room!\nPlease enter your name: ";
        send(client_socket, welcome_message, sizeof(welcome_message), 0);

        // receive the client's name
        char client_name[100];
        recv(client_socket, &client_name, sizeof(client_name), 0);

        // print a welcome message on the server side
        printf("%s has joined the chat room.\n", client_name);

        while(1){
            // receive a message from the client
            char message[1000];
            recv(client_socket, &message, sizeof(message), 0);

            // check if the message is "exit"
            if(strcmp(message, "exit\n") == 0){
                // disconnect the client from the chat room
                printf("%s has left the chat room.\n", client_name);
                close(client_socket);
                break;
            }

            // print the message on the server side
            printf("%s: %s", client_name, message);

            // send the message to all clients
            send(server_socket, message, sizeof(message), 0);
        }
    }

    // close the server socket
    close(server_socket);

    return 0;
}