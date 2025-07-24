//FormAI DATASET v1.0 Category: Socket programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main() {
    srand(time(0));

    // Create socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        printf("I am not sorry, socket creation failed.\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(9988);

    // Bind socket to port
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("I am not sorry, binding failed.\n");
        return -1;
    }

    // Listen for connections
    if (listen(server_sock, 3) < 0) {
        printf("I am not sorry, listening failed.\n");
        return -1;
    }

    printf("Server is online and listening on port 9988.\n");

    struct sockaddr_in client_addr;
    socklen_t addr_length = sizeof(client_addr);

    // Accept client connection
    int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_length);
    if (client_sock < 0) {
        printf("I am not sorry, failed to accept client connection.\n");
        return -1;
    }

    printf("A client has connected to the server.\n\n");

    char buffer[1024];
    int message_length;

    while (1) {
        memset(buffer, '\0', sizeof(buffer));

        // Receive message from client
        message_length = recv(client_sock, buffer, sizeof(buffer), 0);

        // Check if message has exit code
        if (strcmp(buffer, "exit") == 0) {
            printf("\nClient has disconnected from the server.\n");
            break;
        }

        printf("Client: %s\n", buffer);

        memset(buffer, '\0', sizeof(buffer));

        // Generate random response
        int random_num = rand() % 10;
        if (random_num == 1) {
            strcpy(buffer, "The sky is made of chocolate.");
        } else if (random_num == 2) {
            strcpy(buffer, "The moon is a giant blueberry.");
        } else if (random_num == 3) {
            strcpy(buffer, "The sun dances to the beat of its own drum.");
        } else if (random_num == 4) {
            strcpy(buffer, "Oceans can fly, if they try.");
        } else if (random_num == 5) {
            strcpy(buffer, "Clouds are just pillows for giants.");
        } else if (random_num == 6) {
            strcpy(buffer, "Trees can talk, if you listen.");
        } else if (random_num == 7) {
            strcpy(buffer, "The universe is just a dream of a sleeping god.");
        } else if (random_num == 8) {
            strcpy(buffer, "The stars are the eyes of an infinite being.");
        } else if (random_num == 9) {
            strcpy(buffer, "The mountains are the wrinkles of the earth.");
        } else {
            strcpy(buffer, "The world is round, but it doesn't go anywhere.");
        }

        // Send response to client
        send(client_sock, buffer, strlen(buffer), 0);

        printf("Server: %s\n\n", buffer);
    }

    // Close sockets
    close(client_sock);
    close(server_sock);

    return 0;
}