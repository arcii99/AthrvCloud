//FormAI DATASET v1.0 Category: Socket programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming requests
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("\n\n Waiting for new connection\n");

        // Accept the incoming request
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection established\n");

        // Fork a new process
        pid_t pid = fork();

        if(pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if(pid == 0) {
            // Child process -> handle incoming request
            close(server_fd);

            // Read the incoming message from the client
            valread = read(new_socket , buffer, 1024);
            printf("%s\n",buffer );

            // Send a response to the client
            send(new_socket , hello , strlen(hello) , 0 );
            printf("Hello message sent\n");

            close(new_socket);
            exit(EXIT_SUCCESS);
        } else {
            // Parent process -> continue listening for new requests
            close(new_socket);
        }
    }

    return EXIT_SUCCESS;
}