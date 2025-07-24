//FormAI DATASET v1.0 Category: Client Server Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *welcome_message = "Welcome to the funny server!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket option failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Binding the socket to a specific IP and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d\n", PORT);

    // Listening to incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    // Accepting the incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accepting failed");
        exit(EXIT_FAILURE);
    }

    // Sending welcome message to the client
    send(new_socket, welcome_message, strlen(welcome_message), 0);

    while(1) {
        // Receiving message from the client
        valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Client: %s", buffer);

        // Processing message received from the client
        char response[BUFFER_SIZE];
        if (strcmp(buffer, "Knock, knock\n") == 0) {
            strcpy(response, "Who's there?\n");
        } else if (strcmp(buffer, "Boo\n") == 0) {
            strcpy(response, "Don't cry, it's just a joke :)\n");
        } else if (strcmp(buffer, "Exit\n") == 0) {
            strcpy(response, "Goodbye! Thanks for playing!\n");
            send(new_socket, response, strlen(response), 0);
            break;
        } else {
            strcpy(response, "I don't understand. Try again!\n");
        }

        // Sending response to the client
        send(new_socket, response, strlen(response), 0);
        memset(buffer, 0, sizeof(buffer));
        memset(response, 0, sizeof(response));
    }

    // Closing the connection
    close(new_socket);
    close(server_fd);

    return 0;
}