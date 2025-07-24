//FormAI DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main() {
    struct sockaddr_in server_address, client_address;
    int server_fd, client_fd, address_length = sizeof(server_address);
    char buffer[BUFFER_SIZE] = {0};
    bool game_over = false;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set socket address information
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, address_length) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    printf("Waiting for players to connect...\n");

    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_length)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Player connected\n");

    // Initialize game state
    int score = 0;
    int enemy_health = 100;

    // Game loop
    while (!game_over) {
        // Receive command from player
        int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            perror("Recv failed");
            exit(EXIT_FAILURE);
        }

        // Parse command and update game state
        if (strcmp(buffer, "attack") == 0) {
            // Player attacks enemy
            enemy_health -= 10;
            if (enemy_health <= 0) {
                // Enemy defeated
                score += 100;
                enemy_health = 100;
            }
        } else if (strcmp(buffer, "heal") == 0) {
            // Player heals self
            score -= 20;
            if (score < 0) {
                // Player has died
                game_over = true;
                strcpy(buffer, "You have died...");
            } else {
                strcpy(buffer, "You have healed yourself.");
            }
        } else if (strcmp(buffer, "quit") == 0) {
            // Player has quit
            game_over = true;
            strcpy(buffer, "You have quit the game.");
        } else {
            // Invalid command
            strcpy(buffer, "Invalid command. Please try again.");
        }

        // Send updated game state to player
        send(client_fd, buffer, strlen(buffer), 0);
    }

    // Close sockets
    close(client_fd);
    close(server_fd);

    return 0;
}