//FormAI DATASET v1.0 Category: Client Server Application ; Style: distributed
/* This is a simple example of a distributed style client-server application.
 * The client sends a string message to the server, which reverses the message
 * and sends it back to the client.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock_fd, client_fd, addr_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[256];

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("ERROR opening socket");

    // Prepare server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to server address
    if (bind(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR on binding");

    // Listen for incoming connections
    listen(sock_fd, 5);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept connection from client
        addr_len = sizeof(client_addr);
        client_fd = accept(sock_fd, (struct sockaddr *) &client_addr, &addr_len);
        if (client_fd < 0)
            error("ERROR on accept");

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Read message from client
        bzero(buffer, 256);
        if (read(client_fd, buffer, 255) < 0)
            error("ERROR reading from socket");

        printf("Received message: %s\n", buffer);

        // Reverse message and send back to client
        int len = strlen(buffer);
        char reversed[len];
        int i;
        for (i = 0; i < len; i++)
            reversed[i] = buffer[len-i-1];
        reversed[len] = '\0';
        if (write(client_fd, reversed, len) < 0)
            error("ERROR writing to socket");

        // Close connection
        close(client_fd);
        printf("Connection closed\n");
    }

    return 0;
}