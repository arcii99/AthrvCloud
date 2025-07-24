//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 12345

int main(){
    printf("Welcome to the C Wireless Network Scanner!\n");

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1){
        perror("Server socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        perror("Server bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);
    listen(server_socket, 5);

    while(1){
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0){
            perror("Client accept failed");
            continue;
        }

        char* message = "Success";
        send(client_socket, message, strlen(message), 0);
        printf("Connected to client %d\n", client_socket);
        close(client_socket);
    }

    close(server_socket);

    return 0;
}