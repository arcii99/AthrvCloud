//FormAI DATASET v1.0 Category: Networking ; Style: post-apocalyptic
// Post-apocalyptic multiplayer chat program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    int server_socket, client_socket[MAX_CLIENTS], activity, i, valread, sd, max_sd;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    fd_set readfds;

    // Create socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port number
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Waiting for incoming connections...\n");

    // Accept incoming connections
    int addrlen = sizeof(address);
    while (1) {

        // Clear the socket set
        FD_ZERO(&readfds);

        // Add the server socket to the set
        FD_SET(server_socket, &readfds);
        max_sd = server_socket;

        // Add all the connected sockets to the set
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];

            // If it is a valid socket descriptor, add it to the set
            if (sd > 0)
                FD_SET(sd, &readfds);

            // Update the maximum file descriptor number, if needed
            if (sd > max_sd)
                max_sd = sd;
        }

        // Wait for activity on any of the connected sockets
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select error");
            exit(EXIT_FAILURE);
        }

        // Handle new connections
        if (FD_ISSET(server_socket, &readfds)) {
            if ((client_socket[i] = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept error");
                exit(EXIT_FAILURE);
            }

            printf("New connection established. Client IP : %s, Port : %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        }

        // Handle incoming messages
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];

            if (FD_ISSET(sd, &readfds)) {
                if ((valread = read(sd, buffer, BUFFER_SIZE)) == 0) {
                    getpeername(sd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
                    printf("Connection closed. Client IP : %s, Port : %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

                    // Close the socket and mark as 0
                    close(sd);
                    client_socket[i] = 0;
                }
                else {
                    buffer[valread] = '\0';
                    printf("Message from client : %s\n", buffer);

                    // Loop through all connected clients and send the message
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        int client_sd = client_socket[j];
                        if (client_sd > 0 && client_sd != sd) {
                            send(client_sd, buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }

    }

    return 0;
}