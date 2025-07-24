//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
//Including the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080 // Port number
#define MAX_PENDING_CONNECTIONS 10 // Maximum number of pending connections
#define MAX_BUFFER_SIZE 1024 // Maximum buffer size

int main(int argc, char const *argv[]) {
    int server, client, read_size;
    struct sockaddr_in address;
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Creating server socket
    if ((server = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server Address configuration
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Server Socket Binding
    if (bind(server, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Socket Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for a Client Connection
    if (listen(server, MAX_PENDING_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // A loop for handling multiple clients
    while (1) {

        // Accepting Client Connection
        if ((client = accept(server, (struct sockaddr *)&address, (socklen_t*)&address)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Reading data from the Socket
        while ((read_size = read(client, buffer, MAX_BUFFER_SIZE)) > 0 ) {

            // Printing the received message
            printf("Message Received: %s", buffer);

            // Sending a Response to the Client
            send(client, buffer, strlen(buffer), 0);
            memset(buffer, 0, MAX_BUFFER_SIZE); // Clearing the buffer
        }

        // Closing the client socket
        close(client);
    }

    // Closing the server socket
    close(server);
    return 0;
}