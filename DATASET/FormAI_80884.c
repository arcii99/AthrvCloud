//FormAI DATASET v1.0 Category: Chat server ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket){
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    memset(message, 0, BUFFER_SIZE);

    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Message from client: %s\n", buffer);

    while(1){
        printf("Enter message to client: ");
        fgets(message, BUFFER_SIZE, stdin);
        send(client_socket, message, strlen(message), 0);

        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("Message from client: %s\n", buffer);

        if(strcmp(buffer, "exit") == 0){
            printf("Closing connection with client...\n");
            break;
        }
        memset(message, 0, BUFFER_SIZE);
        memset(buffer, 0, BUFFER_SIZE);
    }
}

int main(){
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0){
        printf("Error creating socket...\n");
        return -1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        printf("Error binding socket to port %d...\n", PORT);
        return -1;
    }

    if(listen(server_socket, 10) < 0){
        printf("Error listening for clients...\n");
        return -1;
    }

    printf("Server running on port %d...\n", PORT);

    struct sockaddr_in client_address;
    int client_socket, addrlen;

    while(1){
        addrlen = sizeof(client_address);
        memset(&client_address, 0, sizeof(client_address));

        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &addrlen);
        if(client_socket < 0){
            printf("Error accepting client...\n");
            return -1;
        }

        printf("\nNew client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        char welcome_message[] = "Connected to chat server!\n";
        send(client_socket, welcome_message, strlen(welcome_message), 0);

        handle_client(client_socket);

        close(client_socket);
    }

    close(server_socket);

    return 0;
}