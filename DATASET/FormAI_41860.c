//FormAI DATASET v1.0 Category: Chat server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, client_sockets[MAX_CLIENTS], activity, max_sd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // initialize client sockets as 0
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }
    
    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Server socket creation failed.");
        exit(EXIT_FAILURE);
    }
    
    // set server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // bind server socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed.");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listening failed.");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d...\n", PORT);
    
    while (1) {
        // clear socket set
        fd_set read_fds;
        FD_ZERO(&read_fds);
        
        // add server socket to set
        FD_SET(server_fd, &read_fds);
        max_sd = server_fd;
        
        // add client sockets to set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];
            if (sd != 0) {
                FD_SET(sd, &read_fds);
            }
            if (sd > max_sd) {
                max_sd = sd;
            }
        }
        
        // wait for activity on any of the sockets
        activity = select(max_sd + 1, &read_fds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("Select error.");
            exit(EXIT_FAILURE);
        }
        
        // handle activity on server socket
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_address)) < 0) {
                perror("Accept error.");
                exit(EXIT_FAILURE);
            }
            
            printf("New connection, socket fd is %d, ip is: %s, port: %d\n", new_socket, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            
            // add new client socket to array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    break;
                }
            }
        }
        
        // handle activity on client sockets
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];
            
            if (FD_ISSET(sd, &read_fds)) {
                if (read(sd, buffer, BUFFER_SIZE) == 0) {
                    // client has disconnected
                    getpeername(sd, (struct sockaddr*)&client_address, (socklen_t*)&client_address);
                    printf("Client disconnected, socket fd is %d, ip is: %s, port: %d\n", sd, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    close(sd);
                    client_sockets[i] = 0;
                } else {
                    // process client message
                    printf("Received message from client, socket fd is %d, message is %s\n", sd, buffer);
                    send(sd, buffer, strlen(buffer), 0);
                }
            }
        }
    }
    
    return EXIT_SUCCESS;
}