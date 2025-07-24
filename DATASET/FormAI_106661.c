//FormAI DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_sockets[MAX_CONNECTIONS], max_clients = MAX_CONNECTIONS - 1;
    struct sockaddr_in server_address, client_address;
    socklen_t sock_size = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];
    fd_set read_fds;

    // initialize server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);

    // bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sock_size) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // start listening for client connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("Server listening on port %d\n", ntohs(server_address.sin_port));

    // initialize client sockets
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        client_sockets[i] = 0;
    }

    while (1) {
        // clear file descriptor set
        FD_ZERO(&read_fds);
        // add server socket to set
        FD_SET(server_socket, &read_fds);

        int max_sock = server_socket;
        // add client sockets to set
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            // if socket is valid, add to set and update max sock value
            if (client_sockets[i] > 0) {
                FD_SET(client_sockets[i], &read_fds);
                if (client_sockets[i] > max_sock) {
                    max_sock = client_sockets[i];
                }
            }
        }

        // wait for activity on sockets
        select(max_sock + 1, &read_fds, NULL, NULL, NULL);

        // if activity is on server socket, accept new connection
        if (FD_ISSET(server_socket, &read_fds)) {
            int new_socket = accept(server_socket, (struct sockaddr *)&client_address, &sock_size);
            if (new_socket < 0) {
                perror("Error accepting connection");
                exit(1);
            }

            // add new connection to client socket array
            for (int i = 0; i < MAX_CONNECTIONS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    printf("New connection, socket fd is %d, ip is : %s, port : %d\n", new_socket, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    break;
                }
            }
        }

        // check each client socket for activity
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            int client_socket = client_sockets[i];

            if (FD_ISSET(client_socket, &read_fds)) {
                // receive data from client
                int bytes_read = read(client_socket, buffer, BUFFER_SIZE);
                if (bytes_read == 0) {
                    // client has disconnected
                    printf("Client disconnected\n");
                    close(client_socket);
                    client_sockets[i] = 0;
                } else {
                    // print received data
                    printf("Data received from client: %s\n", buffer);
                    // send response to client
                    char *response = "HTTP/1.1 200 OK\nContent-Length: 12\nContent-Type: text/plain\n\nHello world!";
                    write(client_socket, response, strlen(response));
                }
            }
        }
    }

    return 0;
}