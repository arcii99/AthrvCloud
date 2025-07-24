//FormAI DATASET v1.0 Category: Chat server ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

#define PORT 8080
#define MAX_CLIENTS 3
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]){
    int server_fd, new_socket, client_sockets[MAX_CLIENTS];
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    int active_clients = 0;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Accept incoming connections and handle them
    while(1){
        if(active_clients <= MAX_CLIENTS){

            // Add new client socket to array
            client_sockets[active_clients] = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

            if(client_sockets[active_clients] < 0){
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            printf("Connection established with client %d\n", active_clients + 1);
            active_clients++;
        }

        // Handle messages from connected clients
        for(int i = 0; i < active_clients; i++){
            new_socket = client_sockets[i];

            // Read incoming message from client
            if(read(new_socket, buffer, BUFFER_SIZE) == 0){
                printf("Client %d has disconnected", i+1);

                // Remove disconnected client from array
                for(int j = i; j < active_clients -1; j++){
                    client_sockets[j] = client_sockets[j+1];
                }
                active_clients--;
            }

            // Log message from client and send acknowledgement
            else{
                printf("Message from client %d: %s\n", i+1, buffer);
                send(new_socket, "Message received\n",16, 0);
                memset(buffer, 0, BUFFER_SIZE);
            }
        }
    }
    return 0;
}