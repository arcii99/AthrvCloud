//FormAI DATASET v1.0 Category: Firewall ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define BACKLOG 10
#define IP_ADDRESS "127.0.0.1"
#define PORT_NUMBER 9000

int main() {

    // Creating socket
    int server = socket(AF_INET, SOCK_STREAM, 0);

    // Initializing address structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUMBER);
    inet_pton(AF_INET, IP_ADDRESS, &server_address.sin_addr);

    // Binding socket to address
    bind(server, (struct sockaddr*)&server_address, sizeof(server_address));

    // Starting to listen for incoming connections
    listen(server, BACKLOG);

    // Loop to accept incoming connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);

        // Accepting incoming connection
        int client = accept(server, (struct sockaddr*)&client_address, &client_address_size);

        // Reading incoming message
        char buffer[BUFFER_SIZE];
        recv(client, buffer, BUFFER_SIZE, 0);
        printf("Incoming message: %s\n", buffer);

        if (strstr(buffer, "blocked")) {
            char* message = "HTTP/1.1 403 Forbidden\r\n\r\n";
            send(client, message, strlen(message), 0);
        }
        else {
            char* message = "HTTP/1.1 200 OK\r\n\r\n";
            send(client, message, strlen(message), 0);
        }

        // Closing connection
        close(client);
    }

    // Closing server socket
    close(server);

    return 0;
}