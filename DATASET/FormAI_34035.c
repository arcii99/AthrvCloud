//FormAI DATASET v1.0 Category: Chat server ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_count = 0;
int client_sockets[MAX_CLIENTS];
char clients_nicknames[MAX_CLIENTS][256];
char buffer[BUFFER_SIZE];

void send_message(char *message, int sender_socket) {
    // loop through all the connected clients and send them the message
    for (int i = 0; i < MAX_CLIENTS; i++) {
        int socket_fd = client_sockets[i];
        if (socket_fd != 0 && socket_fd != sender_socket) {
            // send message to client
            if (send(socket_fd, message, strlen(message), 0) == -1) {
                perror("Error: send() failed");
            }
        }
    }
}

void broadcast_join_leave_message(int client_socket, char *action) {
    // get client ip address and port number
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);
    if (getpeername(client_socket, (struct sockaddr *)&client_address, &client_address_size) == -1) {
        perror("Error: getpeername() failed");
        return;
    }
    char *client_ip_address = inet_ntoa(client_address.sin_addr);
    int client_port_number = ntohs(client_address.sin_port);

    // create and send join/leave message
    snprintf(buffer, BUFFER_SIZE, "* %s (%s:%d) just %s the chatroom.\n", clients_nicknames[client_socket], client_ip_address, client_port_number, action);
    send_message(buffer, client_socket);
}

int main() {
    // create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error: socket() failed");
        return EXIT_FAILURE;
    }

    // set socket options
    int reuseaddr_enabled = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_enabled, sizeof(reuseaddr_enabled)) == -1) {
        perror("Error: setsockopt() failed");
    }

    // bind server socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(9000);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error: bind() failed");
        return EXIT_FAILURE;
    }

    // listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error: listen() failed");
        return EXIT_FAILURE;
    }

    // main loop
    while (1) {
        // wait for incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Error: accept() failed");
            continue;
        }

        // add new client to the list
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count] = client_socket;
            snprintf(clients_nicknames[client_socket], 256, "user%d", client_count);
            client_count++;

            // send welcome message to client
            snprintf(buffer, BUFFER_SIZE, "Welcome to the chatroom, %s!\n", clients_nicknames[client_socket]);
            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                perror("Error: send() failed");
            }

            // broadcast join message to all clients except the new one
            broadcast_join_leave_message(client_socket, "joined");
        } else {
            // maximum number of clients reached, disconnect client
            snprintf(buffer, BUFFER_SIZE, "Maximum number of clients reached, sorry!\n");
            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                perror("Error: send() failed");
            }
            close(client_socket);
        }

        // receive and broadcast messages from the client
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
            if (bytes_received == -1) {
                perror("Error: recv() failed");
                break;
            } else if (bytes_received == 0) {
                // client disconnected
                break;
            }
            // remove trailing newline character
            buffer[strcspn(buffer, "\n")] = '\0';

            // check for command
            if (strncmp(buffer, "/nick ", 6) == 0) {
                // change client nickname
                char new_nickname[256];
                snprintf(new_nickname, 256, "%s", &buffer[6]);
                snprintf(buffer, BUFFER_SIZE, "* %s changed their nickname to %s.\n", clients_nicknames[client_socket], new_nickname);
                snprintf(clients_nicknames[client_socket], 256, "%s", new_nickname);
                send_message(buffer, client_socket);
            } else if (strncmp(buffer, "/quit", 5) == 0) {
                // remove client from the list and disconnect
                for (int i = 0; i < MAX_CLIENTS; i++) {
                    if (client_sockets[i] == client_socket) {
                        client_sockets[i] = 0;
                        client_count--;
                        broadcast_join_leave_message(client_socket, "left");
                        break;
                    }
                }
                close(client_socket);
                break;
            } else {
                // broadcast message to all clients
                snprintf(buffer, BUFFER_SIZE, "%s: %s\n", clients_nicknames[client_socket], buffer);
                send_message(buffer, client_socket);
            }
        }
    }

    // close server socket
    close(server_socket);

    return EXIT_SUCCESS;
}