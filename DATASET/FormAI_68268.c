//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024 

typedef struct {
    int socketfd;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
} client_t;

int main(int argc, char *argv[]) {
    int serverfd, new_socket, option = 1;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    client_t clients[MAX_CLIENTS];
    fd_set read_fds;
    char *welcome_message = "Welcome to the server!\n";
    
    //create socket
    if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    //set socket options
    if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    //bind socket to ip address and port number
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);
    
    if (bind(serverfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    //listen for incoming connections
    if (listen(serverfd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", SERVER_PORT);
    
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(serverfd, &read_fds);
        
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sockfd = clients[i].socketfd;
            
            if (sockfd > 0) {
                FD_SET(sockfd, &read_fds);
            }
        }
        
        //wait for activity on sockets
        if (select(MAX_CLIENTS + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }
        
        //check for incoming connection requests
        if (FD_ISSET(serverfd, &read_fds)) {
            if ((new_socket = accept(serverfd, (struct sockaddr *)&client_address, &client_address_length)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }
            
            //add new client to client array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].socketfd == 0) {
                    clients[i].socketfd = new_socket;
                    clients[i].address = client_address;
                    printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    send(new_socket, welcome_message, strlen(welcome_message), 0);
                    break;
                }
            }
        }
        
        //check for activity on existing sockets
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sockfd = clients[i].socketfd;
            
            if (FD_ISSET(sockfd, &read_fds)) {
                char *message = NULL;
                
                //read incoming data
                if (read(sockfd, clients[i].buffer, BUFFER_SIZE) <= 0) {
                    //client disconnected
                    getpeername(sockfd, (struct sockaddr *)&client_address, &client_address_length);
                    printf("Client disconnected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    close(sockfd);
                    clients[i].socketfd = 0;
                } else {
                    //process incoming message
                    message = strdup(clients[i].buffer);
                    printf("Received message from %s:%d: %s", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), message);
                    
                    //echo message back to client
                    send(sockfd, message, strlen(message), 0);
                }
                
                free(message);
            }
        }
    }
    
    return 0;
}