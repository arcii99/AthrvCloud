//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Creating the socket
    int sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Initializing the server configuration
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding the socket with the server configuration
    if (bind(sock_desc, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(sock_desc, 3) < 0) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connections
    printf("Waiting for incoming connections...\n");
    int client_sock_desc, val_read;
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[1024] = {0};
    if ((client_sock_desc = accept(sock_desc, (struct sockaddr *) &client_addr, &addr_len)) < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }
    printf("Connection established!\n");

    // Reading data from the client
    while ((val_read = read(client_sock_desc, buffer, 1024)) > 0) {
        printf("Received message: %s\n", buffer);
        printf("Sending response...\n");
        
        // Sending a response back to the client
        char response[1024] = "Hello from the future!";
        int send_val = send(client_sock_desc, response, strlen(response), 0);

        // Checking if the response was sent successfully
        if (send_val == -1) {
            perror("Error sending response");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, sizeof(buffer)); // Clearing the buffer
    }

    // Closing the socket
    close(sock_desc);

    return 0;
}