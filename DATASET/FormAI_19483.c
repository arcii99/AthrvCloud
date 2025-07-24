//FormAI DATASET v1.0 Category: Socket programming ; Style: Romeo and Juliet
// Romeo and Juliet Socket Programming Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[1024];

    // Creating the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating server socket!\n");
        exit(1);
    }

    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding the socket to the specified port
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding to port %d!\n", PORT);
        exit(1);
    }

    // Listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        printf("Error listening for incoming connections!\n");
        exit(1);
    }

    printf("Waiting for Juliet to connect...\n");

    socklen_t client_address_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);

    printf("Connected with Juliet!\n\n");

    while(1) {
        printf("Romeo: ");

        // Sending message to Juliet
        fgets(message, 1024, stdin);
        send(client_socket, message, strlen(message), 0);

        // Checking if the message is "exit"
        if (strncmp(message, "exit", 4) == 0) {
            break;
        }

        memset(message, 0, sizeof message);

        // Receiving message from Juliet
        recv(client_socket, message, 1024, 0);

        // Checking if the message is "exit"
        if (strncmp(message, "exit", 4) == 0) {
            break;
        }

        printf("Juliet: %s", message);

        memset(message, 0, sizeof message);
    }

    printf("Session ended with Juliet.\n");

    // Closing the socket
    close(server_socket);

    return 0;
}