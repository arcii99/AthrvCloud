//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 8888
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    int master_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_len = sizeof(client_address);
    char message[MAX_BUFFER_SIZE];
    int opt = 1;
    fd_set readfds;
    int max_clients = 30;
    int clients[max_clients];
    int activity, i, valread, sd;

    // Initialize all clients to 0 (no socket connected)
    for (i = 0; i < max_clients; i++) {
        clients[i] = 0;
    }

    // Create a master socket
    master_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (master_socket == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address and bind the socket to it
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(master_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(master_socket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {

        // Clear the file descriptor set
        FD_ZERO(&readfds);

        // Add master socket to file descriptor set
        FD_SET(master_socket, &readfds);
        int max_sd = master_socket;

        // Add child sockets to file descriptor set
        for (i = 0 ; i < max_clients ; i++) {
            sd = clients[i];
            if (sd > 0)
                FD_SET(sd , &readfds);
            if (sd > max_sd)
                max_sd = sd;
        }

        // Wait for activity on any of the sockets
        activity = select(max_sd + 1 , &readfds , NULL , NULL , NULL);
        if (activity < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        // Handle activity on master socket (new connection)
        if (FD_ISSET(master_socket, &readfds)) {
            if ((new_socket = accept(master_socket, (struct sockaddr *)&client_address, (socklen_t*)&addr_len)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            // Inform the user of new connection
            printf("New connection, socket fd is %d, IP is : %s, port : %d\n", new_socket, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

            // Add new socket to array of sockets
            for (i = 0; i < max_clients; i++) {
                if (clients[i] == 0) {
                    clients[i] = new_socket;
                    break;
                }
            }
        }

        // Handle activity on child sockets (incoming data)
        for (i = 0; i < max_clients; i++) {
            sd = clients[i];
            if (FD_ISSET(sd, &readfds)) {

                // Check if the socket is closed
                if ((valread = read(sd, message, MAX_BUFFER_SIZE)) == 0) {
                    // Inform the user that the socket is closed
                    printf("Client disconnected, socket fd : %d, IP address: %s, port : %d \n", sd , inet_ntoa(client_address.sin_addr) , ntohs(client_address.sin_port));

                    // Close the socket and mark it as 0 in the array
                    close(sd);
                    clients[i] = 0;
                }

                // Handle incoming data
                else {
                    // Get current time
                    time_t rawtime;
                    struct tm * timeinfo;
                    char timestamp[80];
                    time(&rawtime);
                    timeinfo = localtime(&rawtime);
                    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

                    // Print received message with timestamp
                    message[valread] = '\0';
                    printf("[%s] Received message from client at socket fd %d: %s", timestamp, sd, message);

                    // Send message back to client
                    send(sd, message, strlen(message), 0);
                }
            }
        }
    }

    return 0;
}