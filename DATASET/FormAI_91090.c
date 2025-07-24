//FormAI DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MSG_SIZE 1024

// Puzzle function that converts a string to a series of encoded numbers
void encode(const char* input, int* output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = (int)input[i] + i + 10;
    }
}

// Puzzle function that converts encoded numbers to a string
void decode(const int* input, char* output, int len) {
    for (int i = 0; i < len; i++) {
        output[i] = (char)(input[i] - i - 10);
    }
    output[len] = '\0';
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_MSG_SIZE] = {0};
    int encoded[MAX_MSG_SIZE];
    char decoded[MAX_MSG_SIZE];

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connection...\n");
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected! Starting puzzle...\n");

    while (true) {
        memset(buffer, 0, MAX_MSG_SIZE);

        // Read from client, decode, and display the message
        read(new_socket, encoded, MAX_MSG_SIZE);
        decode(encoded, decoded, strlen(buffer));
        printf("Client: %s\n", decoded);

        // Get the user's input and encode it before sending to client
        printf("Enter your puzzling response: ");
        fgets(buffer, MAX_MSG_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        encode(buffer, encoded);
        send(new_socket, encoded, strlen(buffer), 0);
    }
    return 0;
}