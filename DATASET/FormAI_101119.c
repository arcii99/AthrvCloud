//FormAI DATASET v1.0 Category: Socket programming ; Style: shape shifting
/*
 * This is a unique C Socket programming example program in a shape shifting style.
 * The program creates a server that can send text in different formats to its client.
 * The server will shape shift its output based on client requests.
 * Enjoy!
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8888

int main(int argc, char const *argv[]) {

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: Could not create socket.\n");
        return -1;
    }

    // Bind socket to port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not bind socket to port.\n");
        return -1;
    }

    // Listen for incoming connections
    listen(server_socket, 1);

    // Accept incoming connections
    struct sockaddr_in client_address;
    int client_socket, client_address_len = sizeof(client_address);
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_len))) {
        printf("Client connected.\n");

        // Send a welcome message to the client
        char* welcome = "Welcome to the Shape Shifting Server! What format do you want the text to be in?\n1. UPPERCASE\n2. lowercase\n3. Title Case\n4. CamelCase\n5. snake_case\n6. kebab-case\n";
        send(client_socket, welcome, strlen(welcome), 0);

        // Receive client request
        char client_request[256];
        int request_len = read(client_socket, client_request, 256);
        client_request[request_len-1] = '\0';

        // Prepare text to be sent based on client request
        char* text = "the quick brown fox jumps over the lazy dog";

        if (strcmp(client_request, "1") == 0) {
            // UPPERCASE
            for (int i = 0; text[i] != '\0'; i++) {
                if (text[i] >= 'a' && text[i] <= 'z') {
                    text[i] = text[i] - 32;
                }
            }
            send(client_socket, text, strlen(text), 0);
        } else if (strcmp(client_request, "2") == 0) {
            // lowercase
            for (int i = 0; text[i] != '\0'; i++) {
                if (text[i] >= 'A' && text[i] <= 'Z') {
                    text[i] = text[i] + 32;
                }
            }
            send(client_socket, text, strlen(text), 0);
        } else if (strcmp(client_request, "3") == 0) {
            // Title Case
            for (int i = 0; text[i] != '\0'; i++) {
                if (i == 0 || text[i-1] == ' ') {
                    if (text[i] >= 'a' && text[i] <= 'z') {
                        text[i] = text[i] - 32;
                    }
                } else {
                    if (text[i] >= 'A' && text[i] <= 'Z') {
                        text[i] = text[i] + 32;
                    }
                }
            }
            send(client_socket, text, strlen(text), 0);
        } else if (strcmp(client_request, "4") == 0) {
            // CamelCase
            for (int i = 0; text[i] != '\0'; i++) {
                if (i == 0 || text[i-1] == ' ') {
                    if (text[i] >= 'a' && text[i] <= 'z') {
                        text[i] = text[i] - 32;
                    }
                } else {
                    if (text[i] >= 'A' && text[i] <= 'Z') {
                        text[i] = text[i] + 32;
                    }
                }
            }
            char camelcase[256];
            int j = 0;
            for (int i = 0; text[i] != '\0'; i++) {
                if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
                    camelcase[j++] = text[i];
                }
            }
            camelcase[j] = '\0';
            send(client_socket, camelcase, strlen(camelcase), 0);
        } else if (strcmp(client_request, "5") == 0) {
            // snake_case
            for (int i = 0; text[i] != '\0'; i++) {
                if (text[i] == ' ') {
                    text[i] = '_';
                } else {
                    if (text[i] >= 'A' && text[i] <= 'Z') {
                        text[i] = text[i] + 32;
                    }
                }
            }
            send(client_socket, text, strlen(text), 0);
        } else if (strcmp(client_request, "6") == 0) {
            // kebab-case
            for (int i = 0; text[i] != '\0'; i++) {
                if (text[i] == ' ') {
                    text[i] = '-';
                } else {
                    if (text[i] >= 'A' && text[i] <= 'Z') {
                        text[i] = text[i] + 32;
                    }
                }
            }
            send(client_socket, text, strlen(text), 0);
        } else {
            char* error = "Invalid request.\n";
            send(client_socket, error, strlen(error), 0);
        }

        // Close client socket
        close(client_socket);

    }

    // Close server socket
    close(server_socket);

    return 0;

}