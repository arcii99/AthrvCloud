//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, read_size;
    struct sockaddr_in server_addr, client_addr;
    char client_message[BUFFER_SIZE];

    //Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error: socket creation failed\n");
        return 1;
    }

    //Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8000);

    //Bind
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: bind failed\n");
        return 1;
    }
    printf("Listening for incoming connections...\n");

    //Listen
    if (listen(server_socket, 3) < 0) {
        printf("Error: listen failed\n");
        return 1;
    }

    //Accept incoming connections
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&read_size))) {

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //Receive message from client
        while ((read_size = recv(client_socket, client_message, BUFFER_SIZE, 0)) > 0) {

            //Send message back to client
            write(client_socket, client_message, strlen(client_message));

            //Reset buffer
            memset(client_message, 0, sizeof(client_message));
        }

        if (read_size == 0) {
            printf("Client disconnected\n");
        }
        else if (read_size == -1) {
            printf("Error: recv failed\n");
            return 1;
        }
    }

    return 0;
}