//FormAI DATASET v1.0 Category: Chat server ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

// Define the port number
#define PORT 8080

// Define the maximum number of clients that can be connected
#define MAX_CLIENTS 5

// Define a secret key for encryption
#define SECRET_KEY 10

// Define a function to encrypt messages
void encrypt(char *message) {
    for (int i = 0; i < strlen(message); i++) {
        // Shift the character by the secret key value
        message[i] = message[i] + SECRET_KEY;
    }
}

// Define a function to decrypt messages
void decrypt(char *message) {
    for (int i = 0; i < strlen(message); i++) {
        // Shift the character back by the secret key value
        message[i] = message[i] - SECRET_KEY;
    }
}

// Define a function to handle client connections
void *handle_client(void *arg) {
    int client_fd = *(int *)arg;
    char buffer[1024] = {0};
    while (1) {
        // Read message from the client
        read(client_fd, buffer, 1024);
        printf("\nReceived message: %s\n", buffer);
        // Decrypt message
        decrypt(buffer);
        printf("Decrypted message: %s\n", buffer);
        // Prompt user to enter message
        printf("Enter message: ");
        bzero(buffer, 1024);
        fgets(buffer, 1024, stdin);
        // Encrypt message
        encrypt(buffer);
        // Send message to the client
        send(client_fd, buffer, strlen(buffer), 0);
    }
}

int main(int argc, char const *argv[]) {
    int server_fd, client_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t thread_id;

    // Create a socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("\nServer listening on port %d\n", PORT);

    // Accept new client connections and spawn a new thread to handle each connection
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("\nNew client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        pthread_create(&thread_id, NULL, handle_client, (void *)&client_fd);
    }

    return 0;
}