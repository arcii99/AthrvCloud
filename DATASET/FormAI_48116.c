//FormAI DATASET v1.0 Category: Client Server Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_PENDING 10
#define MAX_LINE 256

int main(int argc, char *argv[]) {
    int sd, new_sd, client_len, n;
    char buffer[MAX_LINE];
    struct sockaddr_in server_addr, client_addr;

    // Create a new socket
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Set server socket details
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address and port
    if(bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket to address");
        exit(1);
    }

    // Listen for incoming connections
    if(listen(sd, MAX_PENDING) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server is now listening on port %d...\n", SERVER_PORT);

    while(1) {
        // Accept incoming connections
        client_len = sizeof(client_addr);
        if((new_sd = accept(sd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        // Read data from the client
        if((n = read(new_sd, buffer, MAX_LINE)) == -1) {
            perror("Error reading data from client");
            exit(1);
        }

        // Process data from the client
        printf("Received message from client: %s", buffer);

        // Write data to the client
        if(write(new_sd, buffer, strlen(buffer)) == -1) {
            perror("Error writing data to client");
            exit(1);
        }

        // Close the connection
        close(new_sd);
    }

    // Close the server socket
    close(sd);

    return 0;
}