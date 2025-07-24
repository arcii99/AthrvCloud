//FormAI DATASET v1.0 Category: Networking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_PLAYERS 4
#define PORT_NUM 5000
#define BUFFER_SIZE 256

// player struct to keep track of each player's socket and name
struct player {
    int socket;
    char name[20];
};

int main() {
    int server_fd, new_socket, player_count = 0;
    struct sockaddr_in address;
    int opt = 1, addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char welcome_message[] = "Welcome to the game! Please enter your name: ";
    struct player players[MAX_PLAYERS];

    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // set address and port for socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT_NUM);

    // bind socket to address and port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for players to join...\n");

    // accept incoming connections and add players to game
    while (player_count < MAX_PLAYERS) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // send welcome message to player
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // get player name from client
        memset(buffer, 0, BUFFER_SIZE);
        recv(new_socket, buffer, BUFFER_SIZE, 0);

        // add player to game
        players[player_count].socket = new_socket;
        strncpy(players[player_count].name, buffer, 20);

        printf("%s has joined the game!\n", players[player_count].name);

        player_count++;

        // start game when maximum number of players have joined
        if (player_count == MAX_PLAYERS) {
            printf("All players have joined, game starting!\n");
            break;
        }
    }

    // multiplayer game code goes here...

    // close sockets and end program
    for (int i = 0; i < MAX_PLAYERS; i++) {
        close(players[i].socket);
    }
    close(server_fd);
    return 0;
}