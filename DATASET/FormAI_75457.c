//FormAI DATASET v1.0 Category: Chat server ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>

#define MAX_CLIENTS 5 //maximum number of clients that can connect
#define BUFFER_SIZE 1024 //size of buffer to store messages

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_clients = MAX_CLIENTS;
    struct sockaddr_in server_address, client_address;
    char message[BUFFER_SIZE];
    fd_set readfds;
    int activity, i, valread, sd, addrlen;

    // create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket\n");
        exit(EXIT_FAILURE);
    }

    // setup server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(6969);

    // bind the server socket to the specified IP and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket to server address\n");
        exit(EXIT_FAILURE);
    }

    // start listening for connections
    if (listen(server_socket, max_clients) == -1) {
        perror("Error listening to incoming connections\n");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    addrlen = sizeof(client_address);
    puts("Waiting for connections...");

    // loop forever to handle incoming connections
    while (1) {
        // clear the socket set
        FD_ZERO(&readfds);

        // add server socket to set
        FD_SET(server_socket, &readfds);

        // add child sockets to set
        for (i = 0 ; i < max_clients ; i++) {
            sd = client_socket[i];
            if (sd > 0) {
                FD_SET(sd, &readfds);
            }
        }

        // wait for activity on any of the sockets
        activity = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("Error on select() call\n");
            exit(EXIT_FAILURE);
        }

        // handle incoming connection
        if (FD_ISSET(server_socket, &readfds)) {
            // accept incoming connection
            client_socket[max_clients] = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&addrlen);
            if (client_socket[max_clients] < 0) {
                perror("Error accepting connection\n");
                exit(EXIT_FAILURE);
            }

            // welcome message
            snprintf(message, BUFFER_SIZE, "Welcome to the Chat Server!\n");
            send(client_socket[max_clients], message, strlen(message), 0);
            
            // add new client to client list
            max_clients++;

            // print new connection details
            printf("New connection, IP address: %s, port: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        }

        // handle incoming message from client
        for (i = 0 ; i < max_clients ; i++) {
            sd = client_socket[i];

            if (FD_ISSET(sd, &readfds)) {
                // read incoming message
                valread = read(sd, message, BUFFER_SIZE);
                if (valread == 0) {
                    // client disconnected
                    printf("Client disconnected, IP address: %s, port: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    close(sd);
                    client_socket[i] = 0;
                }
                else {
                    // broadcast message to all other clients
                    for (int j = 0 ; j < max_clients ; j++) {
                        int dest = client_socket[j];
                        if (dest > 0 && dest != sd) {
                            send(dest, message, valread, 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}