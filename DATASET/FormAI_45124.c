//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

#define PORT 8080

bool cryptic(char* message, int message_length, char* key, int key_length) {
    char* encrypted_message = malloc(sizeof(char) * message_length);
    encrypted_message[message_length] = '\0';
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_length];
    }

    printf("Encrypted Message: %s\n", encrypted_message);

    char* decrypted_message = malloc(sizeof(char) * message_length);
    decrypted_message[message_length] = '\0';
    for (int i = 0; i < message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_length];
    }

    printf("Decrypted Message: %s\n", decrypted_message);

    return strcmp(message, decrypted_message) == 0;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char* hello = "Hello from server";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on the socket
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Read message from the client
    valread = read(new_socket, buffer, 1024);
    printf("Received Message: %s\n", buffer);

    // Encrypt and decrypt the message
    bool result = cryptic(buffer, strlen(buffer), "helloworld", 10);

    // Send response back to the client
    char* response = result ? "Message is secure" : "Message is not secure";
    send(new_socket, response, strlen(response), 0);
    printf("Response sent: %s\n", response);
    return 0;
}