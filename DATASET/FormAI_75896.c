//FormAI DATASET v1.0 Category: Client Server Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    int sock = 0, client_sock = 0, valread = 0;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server!";

    // Creating Socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    // Setting up sockaddr_in
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding Socket to Port
    if (bind(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Binding failed\n");
        return -1;
    }

    // Listening to incoming connections
    if (listen(sock, 5) < 0) {
        printf("Listening failed\n");
        return -1;
    }

    // Accepting the connection
    if ((client_sock = accept(sock, (struct sockaddr *) &server_address, (socklen_t *) &server_address)) < 0) {
        printf("Accepting connection failed\n");
        return -1;
    }

    // Sending welcome message to client
    send(client_sock, hello, strlen(hello), 0);
    printf("Welcome message sent to client\n");

    // Loop to handle incoming messages from client
    while ((valread = read(client_sock, buffer, BUFFER_SIZE)) > 0) {

        printf("Incoming Message from Client: %s\n", buffer);

        // Check if the client wants to disconnect
        if (strcmp(buffer, "disconnect") == 0) {
            printf("Client has disconnected. Closing connection.\n");
            close(client_sock);
            close(sock);
            return 0;
        }

        char *response = "Message received successfully!";
        send(client_sock, response, strlen(response), 0);
        printf("Response sent to client\n");

        memset(buffer, 0, BUFFER_SIZE);
    }

    close(client_sock);

    return 0;
}