//FormAI DATASET v1.0 Category: Chat server ; Style: beginner-friendly
#include <stdio.h>      // basic I/O functions
#include <stdlib.h>     // basic functions like malloc(), free()
#include <string.h>     // string functions like strlen(), strcpy()
#include <sys/socket.h> // socket functions like socket(), bind(), listen(), accept()
#include <arpa/inet.h>  // internet operations like htons(), htonl(), inet_addr() 

#define BUFFER_SIZE 1024 // buffer size for messages

int main(int argc, char** argv) {
    int server_socket, client_socket;   // server and client sockets file descriptors
    struct sockaddr_in server_address;  // server address struct
    char buffer[BUFFER_SIZE];           // buffer for messages
    int opt = 1;                        // option variable used to set socket option

    // create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket option to reuse address and port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // configure server address struct
    server_address.sin_family = AF_INET;                    // set address family
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);      // set IP address to any available
    server_address.sin_port = htons(8080);                   // set port number

    // bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", ntohs(server_address.sin_port)); 

    // accept incoming connections
    while (1) {
        int address_length = sizeof(server_address);
        if ((client_socket = accept(server_socket, (struct sockaddr*)&server_address, (socklen_t*)&address_length)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

        // receive and send messages
        while (1) {
            memset(buffer, 0, BUFFER_SIZE); // clear the buffer

            // receive message from client
            int read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (read_size == 0) {
                printf("Client disconnected: %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));
                break;
            } else if (read_size < 0) {
                perror("recv failed");
                exit(EXIT_FAILURE);
            }

            printf("Message received from %s:%d: %s", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port), buffer);

            // send message back to client
            if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
                perror("send failed");
                exit(EXIT_FAILURE);
            }
        }

        // close client socket
        close(client_socket);
    }

    // close server socket
    close(server_socket);

    return 0;
}