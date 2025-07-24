//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// function to sanitize user input
void sanitize_input(char* user_input) {
    int i = 0, j = 0;
    while(user_input[i] != '\0') {
        if(isalnum(user_input[i])) { // check if the character is alphanumeric
            user_input[j++] = tolower(user_input[i]); // convert to lowercase and store in the original string
        }
        i++;
    }
    user_input[j] = '\0'; // append null terminator
}

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket_fd, client_len, read_val;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};

    // create a socket for the server
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set server address details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // bind the socket to the server address
    if(bind(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if(listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    // accept incoming client connections
    client_len = sizeof(client_address);
    if((new_socket_fd = accept(socket_fd, (struct sockaddr*) &client_address, (socklen_t*) &client_len)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    printf("New client connected: %s\n", inet_ntoa(client_address.sin_addr));

    // receive user input from the client and sanitize it
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        if((read_val = read(new_socket_fd, buffer, BUFFER_SIZE)) < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }
        if(read_val == 0) { // client has disconnected
            printf("Client disconnected.\n");
            close(new_socket_fd);
            return 0;
        }
        printf("Received: %s\n", buffer);

        sanitize_input(buffer);

        printf("Sanitized input: %s\n", buffer);

        // send the sanitized input back to the client
        if(send(new_socket_fd, buffer, strlen(buffer), 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}