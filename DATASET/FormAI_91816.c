//FormAI DATASET v1.0 Category: Networking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>

#define PORT 8080
#define MAX_CLIENTS 10

volatile sig_atomic_t flag = 0;
int sockfd = 0;

void close_conn(int signum) {
    flag = 1;
}

int main() {
    signal(SIGINT, close_conn);

    // Create a socket for the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Prepare the socket address for the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Socket bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("Socket listen error");
        exit(EXIT_FAILURE);
    }

    // Create an array to store client sockets
    int client_sockets[MAX_CLIENTS];
    memset(client_sockets, 0, sizeof(client_sockets));

    // Wait for incoming connections and add to array
    while (1) {
        // Check if close_conn has been called
        if (flag) {
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if(client_sockets[i] != 0) {
                    close(client_sockets[i]);
                }
            }
            close(sockfd);
            printf("\nServer closed\n");
            return 0;
        }
        
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_socket = accept(sockfd, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept error");
            continue;
        }
        
        // Add client socket to array
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                printf("Client connected, socket number %d\n", client_socket);
                break;
            } 
        }
        
        // Receive message from client and broadcast to all other clients
        char client_buffer[1024] = {0};
        int read_size = recv(client_socket , client_buffer , 1024 , 0);
        while (read_size > 0) {
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] != 0 && client_sockets[i] != client_socket) {
                    send(client_sockets[i], client_buffer, strlen(client_buffer), 0 );
                }
            }
            memset(client_buffer, 0, 1024);
            read_size = recv(client_socket , client_buffer , 1024 , 0);
        }
        
        // Remove client socket from array and close connection
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == client_socket) {
                client_sockets[i] = 0;
                printf("Client disconnected, socket number %d\n", client_socket);
                break;
            }
        }
        close(client_socket);
    }
    return 0;
}