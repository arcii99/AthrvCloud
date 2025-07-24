//FormAI DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, new_socket, client_fds[MAX_CLIENTS], max_fd, activity, i, valread;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    fd_set read_fds;

    //Create a TCP socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
  
    //Set server address and port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
      
    //Bind the socket to the server address and port number
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    //Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
      
    //Accept incoming connections
    int addrlen = sizeof(server_addr);
    puts("Waiting for connections...");
    while(1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        max_fd = server_fd;
     
        for (i = 0 ; i < MAX_CLIENTS ; i++) {
            if (client_fds[i] > 0) {
                FD_SET(client_fds[i], &read_fds);
            }
            if (client_fds[i] > max_fd) {
                max_fd = client_fds[i];
            }
        }
     
        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if ((activity < 0) && (errno!=EINTR)) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }
          
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }
              
            //Add new client to clients array
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_fds[i] == 0) {
                    client_fds[i] = new_socket;
                    break;
                }
            }
            printf("New connection, socket fd: %d, IP address: %s, port: %d\n", new_socket, inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
        }
          
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_fds[i], &read_fds)) {
                if ((valread = read(client_fds[i], buffer, BUFFER_SIZE)) == 0) {
                    close(client_fds[i]);
                    client_fds[i] = 0;
                } else {
                    buffer[valread] = '\0';
                    printf("Received message: %s\n", buffer);
                    send(client_fds[i], buffer, strlen(buffer), 0);
                }
            }
        }
    }
    return 0;
}