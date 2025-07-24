//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Failed to create client socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
		
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid server address");
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to establish connection");
        exit(EXIT_FAILURE);
    }

    char message[1024] = "Hello from the client!";
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Failed to send message");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to the server: %s\n", message);

    char buffer[1024] = {0};
    int read_size = read(client_socket, buffer, 1024);
    if (read_size < 0) {
        perror("Failed to read response");
        exit(EXIT_FAILURE);
    }
    printf("Response from server: %s\n", buffer);

    close(client_socket);
    return 0;
}