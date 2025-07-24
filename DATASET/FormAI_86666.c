//FormAI DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5555

struct client_t {
    int sockfd;
    char name[32];
};

int main() {
    int server_sockfd, client_sockfd, valread;
    struct sockaddr_in server_addr, client_addr;
    struct client_t clients[10];

    // create server socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // bind server socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));

    if (bind(server_sockfd, (struct sockaddr *)&server_addr, 
             sizeof(server_addr)) == -1) {
        perror("Failed to bind");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_sockfd, 10) == -1) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);

    while (1) {
        // accept incoming connection
        socklen_t client_len = sizeof(client_addr);
        if ((client_sockfd = accept(server_sockfd, 
                                    (struct sockaddr *)&client_addr, 
                                    &client_len)) == -1) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        // receive client name
        char name[32];
        if ((valread = recv(client_sockfd, name, sizeof(name), 0)) > 0) {
            // add client to list
            int i, free_slot = -1;
            for (i = 0; i < 10; i++) {
                if (clients[i].sockfd == 0) {
                    free_slot = i;
                    break;
                }
            }
            if (free_slot == -1) {
                printf("No free slots, disconnecting client...\n");
                close(client_sockfd);
            } else {
                clients[free_slot].sockfd = client_sockfd;
                strncpy(clients[free_slot].name, name, sizeof(clients[free_slot].name));
                printf("Client '%s' connected\n", clients[free_slot].name);
            }
        }

        // send welcome message to client
        char welcome_msg[64];
        snprintf(welcome_msg, sizeof(welcome_msg), "Welcome, %s!\n", name);
        send(client_sockfd, welcome_msg, strlen(welcome_msg), 0);

        // broadcast client connected message to all other clients
        char connected_msg[128];
        snprintf(connected_msg, sizeof(connected_msg), "Client '%s' connected\n", name);
        int i;
        for (i = 0; i < 10; i++) {
            if (clients[i].sockfd != 0 && clients[i].sockfd != client_sockfd) {
                send(clients[i].sockfd, connected_msg, strlen(connected_msg), 0);
            }
        }

        // receive and broadcast messages
        char buffer[256];
        while ((valread = recv(client_sockfd, buffer, sizeof(buffer), 0)) > 0) {
            // add null terminator to received data
            buffer[valread] = '\0';

            // check if client sent quit command
            if (strncmp(buffer, "/quit", 5) == 0) {
                printf("Client '%s' disconnected\n", name);
                // broadcast client disconnected message to all other clients
                char disconnected_msg[128];
                snprintf(disconnected_msg, sizeof(disconnected_msg), 
                         "Client '%s' disconnected\n", name);
                int i;
                for (i = 0; i < 10; i++) {
                    if (clients[i].sockfd != 0 && clients[i].sockfd != client_sockfd) {
                        send(clients[i].sockfd, disconnected_msg, 
                             strlen(disconnected_msg), 0);
                    }
                }
                // remove client from list
                int j;
                for (j = 0; j < 10; j++) {
                    if (clients[j].sockfd == client_sockfd) {
                        clients[j].sockfd = 0;
                        memset(clients[j].name, '\0', sizeof(clients[j].name));
                        break;
                    }
                }
                break;
            }

            // broadcast message to all other clients
            char broadcast_msg[256];
            snprintf(broadcast_msg, sizeof(broadcast_msg), "[%s]: %s", name, buffer);
            int i;
            for (i = 0; i < 10; i++) {
                if (clients[i].sockfd != 0 && clients[i].sockfd != client_sockfd) {
                    send(clients[i].sockfd, broadcast_msg, strlen(broadcast_msg), 0);
                }
            }
        }

        // close connection
        close(client_sockfd);
    }

    return 0;
}