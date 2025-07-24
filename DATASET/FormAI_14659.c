//FormAI DATASET v1.0 Category: Socket programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 512

int main(int argc, char **argv) 
{ 
    int socket_fd, accepted_socket_fd;
    struct sockaddr_in server_address, client_address;
    int address_length = sizeof(server_address);
    char buffer[BUFFER_SIZE] = {0};

    // create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    { 
        perror("Failed to create socket"); 
        exit(-1); 
    } 
  
    // set server address
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(8080); 

    // bind socket to port
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        perror("Bind failed"); 
        exit(-1); 
    } 

    // listen for incoming connections
    if (listen(socket_fd, MAX_CLIENTS) < 0) 
    { 
        perror("Listen failed"); 
        exit(-1);
    } 

    while(1) 
    { 
        // accept incoming connection
        accepted_socket_fd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_length); 
        if (accepted_socket_fd < 0) 
        { 
            perror("Accept failed"); 
            exit(-1); 
        } 

        // create a new process for handling client connection
        if (fork() == 0)
        {
            // close parent socket file descriptor
            close(socket_fd);
            
            // send welcome message to client
            char *welcome_message = "Welcome to the server!\n";
            send(accepted_socket_fd, welcome_message, strlen(welcome_message), 0);

            while(1)
            {
                // receive data from client
                int bytes_received = recv(accepted_socket_fd, buffer, BUFFER_SIZE, 0);

                if (bytes_received < 0)
                {
                    perror("Receive failed");
                    exit(-1);
                }
                else if (bytes_received == 0)
                {
                    printf("Client disconnected\n");
                    break;
                }
                else
                {
                    printf("Received message from client: %s", buffer);

                    // send back the same message to client
                    send(accepted_socket_fd, buffer, strlen(buffer), 0);

                    // clear buffer
                    memset(buffer, 0, sizeof(buffer));
                }
            }

            // close client socket file descriptor
            close(accepted_socket_fd);
            exit(0);
        }
        else
        {
            // close child socket file descriptor
            close(accepted_socket_fd);
        }
    }

    // close server socket file descriptor
    close(socket_fd);
    return 0; 
}