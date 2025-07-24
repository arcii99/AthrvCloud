//FormAI DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

int main() {

    printf("Starting C Socket Programming Example...\n");
    printf("Opening a socket for connection...\n");

    int server_socket;
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Error creating the socket");
        exit(EXIT_FAILURE);
    }

    printf("Binding the socket...\n");

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Error binding the socket");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    if(listen(server_socket, MAX_CONNECTIONS) < 0){
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Accepting incoming connections...\n");

    int new_socket;
    struct sockaddr_in client_address;
    int address_length = sizeof(client_address);

    if((new_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_length)) < 0){
        perror("Error accepting connection request");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    char *greeting = "Welcome to the C Socket Programming Example!";
    send(new_socket, greeting, strlen(greeting), 0);

    char buffer[1024] = {0};
    while(1){
        printf("Waiting for data...\n");

        int bytes_received = recv(new_socket, buffer, 1024, 0);

        printf("Data received: %s\n", buffer);

        if(bytes_received == 0){
            printf("Connection closed by client\n");
            break;
        }

        printf("Sending data back to the client...\n");
        send(new_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, 1024);
    }

    close(server_socket);
    printf("Socket closed, program terminated.");

    return 0;
}