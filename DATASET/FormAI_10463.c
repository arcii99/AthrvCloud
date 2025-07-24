//FormAI DATASET v1.0 Category: Chat server ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9999

bool isAuthorized(char *username, char *password) {
    // Cyberpunk style authentication 
    return (strcmp(username, "Neo") == 0 && strcmp(password, "FollowTheWhiteRabbit") == 0);
}

int main(int argc, char const *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error: Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to the specified IP and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error: Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error: Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connection...\n");

    // Accept incoming connection
    socklen_t client_address_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
    if (client_socket == -1) {
        perror("Error: Failed to accept connection");
        exit(EXIT_FAILURE);
    }

    printf("Connection has been established.\n");

    // Cyberpunk style login prompt
    char prompt[] = "Username: ";
    send(client_socket, prompt, strlen(prompt), 0);
    char username[256];
    memset(username, '\0', sizeof(username));
    recv(client_socket, username, sizeof(username), 0);
    username[strcspn(username, "\r\n")] = 0;

    prompt[0] = '\0';
    strcat(prompt, "Password: ");
    send(client_socket, prompt, strlen(prompt), 0);
    char password[256];
    memset(password, '\0', sizeof(password));
    recv(client_socket, password, sizeof(password), 0);
    password[strcspn(password, "\r\n")] = 0;

    if (isAuthorized(username, password)) {
        char welcome[] = "Welcome to Night City. You are authorized.\n";
        send(client_socket, welcome, strlen(welcome), 0);
    } else {
        char error[] = "Access denied. You have been traced and reported.\n";
        send(client_socket, error, strlen(error), 0);
        close(client_socket);
        close(server_socket);
        exit(EXIT_SUCCESS);
    }

    // Cyberpunk style chat prompt
    char chat_prompt[] = "[Anonymous]: ";
    char message[256];
    while (true) {
        memset(message, '\0', sizeof(message));
        send(client_socket, chat_prompt, strlen(chat_prompt), 0);
        recv(client_socket, message, sizeof(message), 0);
        message[strcspn(message, "\r\n")] = 0;

        if (strcmp(message, "exit") == 0) {
            char goodbye[] = "[System]: Logging out. Goodbye.\n";
            send(client_socket, goodbye, strlen(goodbye), 0);
            break;
        }

        char formatted_message[512];
        sprintf(formatted_message, "[%s]: %s\n", username, message);
        send(client_socket, formatted_message, strlen(formatted_message), 0);
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}