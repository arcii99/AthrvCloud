//FormAI DATASET v1.0 Category: Socket programming ; Style: multiplayer
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8050 
#define MAX_PLAYERS 5 

void init_players(int* players) {
    for (int i=0; i<MAX_PLAYERS; i++) {
        players[i] = -1;
    }
}

int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    int client_socket, addr_size, bytes_received;
    int players[MAX_PLAYERS];
    int num_players = 0;

    // Initialize player connections
    init_players(players);

    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server_address, '\0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, MAX_PLAYERS) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for players to connect...\n");

    // Wait for players to connect
    while (num_players < MAX_PLAYERS) {
        addr_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&addr_size);
        if (client_socket < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Add the player to the list
        players[num_players] = client_socket;
        printf("Player %d connected\n", num_players+1);
        num_players++;
    }

    printf("All players connected!\nLet the game begin!\n");

    // Loop for game logic
    while (1) {
        // Send message to all players and receive their responses
        printf("\nRound Starting...\n");
        for (int i=0; i<MAX_PLAYERS; i++) {
            char buffer[1024];
            int response = 0;
            memset(buffer, '\0', sizeof(buffer));
            sprintf(buffer, "It's your turn, player %d. Enter a number: ", i+1);

            // Send message to player
            if (send(players[i], buffer, strlen(buffer), 0) < 0) {
                perror("Error sending message to player");
                exit(EXIT_FAILURE);
            }

            // Receive response from player
            if ((bytes_received = recv(players[i], &response, sizeof(response), 0)) < 0) {
                perror("Error receiving response from player");
                exit(EXIT_FAILURE);
            }

            printf("Player %d entered %d\n", i+1, response);

            // Send response to all other players
            for (int j=0; j<MAX_PLAYERS; j++) {
                if (j != i) {
                    memset(buffer, '\0', sizeof(buffer));
                    sprintf(buffer, "Player %d entered %d\n", i+1, response);
                    if (send(players[j], buffer, strlen(buffer), 0) < 0) {
                        perror("Error sending message to player");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }

        // End game after five rounds
        static int round_count = 1;
        if (round_count == 5) {
            break;
        } else {
            round_count++;
        }
    }

    printf("\nGame over!\n");

    // Close all player connections
    for (int i=0; i<MAX_PLAYERS; i++) {
        close(players[i]);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}