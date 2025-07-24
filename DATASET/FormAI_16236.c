//FormAI DATASET v1.0 Category: Networking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct client_info {
    int sock_fd;
    struct sockaddr_in address;
};

int main() {
    int server_fd, addrlen, new_socket, max_clients = 10, client_count = 0;
    struct sockaddr_in address;
    struct client_info clients[max_clients];
    char buffer[1024] = {0};
    fd_set read_fds;

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Server address configuration
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    addrlen = sizeof(address);
    
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);

        for (int i = 0; i < max_clients; i++) {
            if (clients[i].sock_fd > 0) {
                FD_SET(clients[i].sock_fd, &read_fds);
            }
        }

        if (select(10, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select error");
            exit(EXIT_FAILURE);
        }

        // If new connection request received
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept error");
                exit(EXIT_FAILURE);
            }
            
            // Add new client info to clients array
            struct client_info client;
            client.sock_fd = new_socket;
            client.address = address;
            
            if (client_count < max_clients) {
                clients[client_count] = client;
                client_count++;
            } else {
                printf("Maximum clients limit exceeded, closing connection.\n");
                close(new_socket);
            }
        }

        // If existing client messages received
        for (int i = 0; i < max_clients; i++) {
            int client_socket = clients[i].sock_fd;
            
            if (FD_ISSET(client_socket, &read_fds)) {
                int valread = read(client_socket, buffer, 1024);

                if (valread <= 0) {
                    // disconnected
                    printf("Client %d disconnected.\n", client_socket);
                    close(client_socket);
                    clients[i].sock_fd = 0;
                    client_count--;
                    continue;
                }
                
                printf("Client %d sent: %s\n", client_socket, buffer);
                memset(buffer, 0, sizeof(buffer));
            }
        }
    }
    
    return 0;
}