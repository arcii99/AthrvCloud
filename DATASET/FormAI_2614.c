//FormAI DATASET v1.0 Category: Simple Web Server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 256
#define SERVER_PORT 8080

int main() {
    /* Step 1: Create a socket */
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Cannot create socket");
        exit(EXIT_FAILURE);
    }

    /* Step 2: Bind the server socket */
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port   = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int bind_result = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_result < 0) {
        perror("Cannot bind socket to address");
        exit(EXIT_FAILURE);
    }

    /* Step 3: Listen for incoming connections */
    int listen_result = listen(server_socket, 5);
    if (listen_result < 0) {
        perror("Cannot listen to incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", SERVER_PORT);

    /* Step 4: Accept incoming connections */
    struct sockaddr_in client_address;
    int client_length = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_length);
    if (client_socket < 0) {
        perror("Cannot accept incoming connection");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    /* Step 5: Process incoming requests */
    char buffer[MAX_BUFFER] = {0};

    while (1) {
        memset(buffer, 0, MAX_BUFFER);

        int read_result = read(client_socket, buffer, MAX_BUFFER);
        if (read_result <= 0) {
            printf("Connection closed from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            break;
        }

        printf("Request received from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        printf("Request:\n%s", buffer);

        /* Step 6: Send response */
        char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello World!";

        int write_result = write(client_socket, message, strlen(message));
        if (write_result < 0) {
            perror("Cannot send response");
            exit(EXIT_FAILURE);
        }
    }

    /* Step 7: Close sockets */
    close(client_socket);
    close(server_socket);

    exit(EXIT_SUCCESS);
}