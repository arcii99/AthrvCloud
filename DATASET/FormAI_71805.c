//FormAI DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int port_number = 8888;
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int client_address_length = sizeof(client_address);
    char message[2000], reply[2000];
    int message_length;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Could not create socket\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Bind failed\n");
        exit(1);
    }
    printf("Bind successful\n");

    if (listen(server_socket, 3) == -1) {
        printf("Listen failed\n");
        exit(1);
    }
    printf("Server listening on port %d\n", port_number);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_address,
                               (socklen_t *) &client_address_length);
        if (client_socket < 0) {
            printf("Could not accept incoming connection\n");
            exit(1);
        }

        printf("New client connected. IP: %s, Port: %d\n", inet_ntoa(client_address.sin_addr),
               ntohs(client_address.sin_port));

        while (1) {
            memset(message, 0, sizeof(message));
            memset(reply, 0, sizeof(reply));

            message_length = read(client_socket, message, sizeof(message));
            if (message_length < 0) {
                printf("Error reading from socket\n");
                exit(1);
            }
            printf("Message received from client: %s\n", message);

            if (strstr(message, "quit") != NULL) {
                printf("Client disconnected\n");
                break;
            }

            strcpy(reply, "Server received your message: ");
            strcat(reply, message);
            if (write(client_socket, reply, strlen(reply)) < 0) {
                printf("Error writing to socket\n");
                exit(1);
            }
            printf("Message replied to client: %s\n", reply);
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}