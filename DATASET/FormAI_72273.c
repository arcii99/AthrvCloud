//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_DRONES 3

struct Drone {
    int x, y;
    char label;
};

struct Player {
    char name[20];
    struct Drone drones[NUM_DRONES];
};

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_drones(struct Drone drones[NUM_DRONES]) {
    for(int i = 0; i < NUM_DRONES; i++) {
        drones[i].x = -1;
        drones[i].y = -1;
        drones[i].label = i + 'A';
    }
}

void place_drones(char board[BOARD_SIZE][BOARD_SIZE], struct Drone drones[NUM_DRONES]) {
    srand(time(NULL));
    for(int i = 0; i < NUM_DRONES; i++) {
        int x, y;
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
        } while(board[x][y] != '.');
        board[x][y] = drones[i].label;
        drones[i].x = x;
        drones[i].y = y;
    }
}

void print_player(struct Player player) {
    printf("Player %s:\n", player.name);
    for(int i = 0; i < NUM_DRONES; i++) {
        printf("Drone %c: (%d, %d)\n", player.drones[i].label, player.drones[i].x, player.drones[i].y);
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    
    struct Player players[2];
    for(int i = 0; i < 2; i++) {
        printf("Please enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        initialize_drones(players[i].drones);
        place_drones(board, players[i].drones);
        print_board(board);
        print_player(players[i]);
    }
    
    printf("Game start!\n");
    int curr_player = 0;
    while(1) {
        printf("It is %s's turn:\n", players[curr_player].name);
        printf("Choose a drone to move (A-C): ");
        char drone_label;
        scanf(" %c", &drone_label);
        
        struct Drone* drone_to_move;
        for(int i = 0; i < NUM_DRONES; i++) {
            if(players[curr_player].drones[i].label == drone_label) {
                drone_to_move = &players[curr_player].drones[i];
                break;
            }
        }
        
        printf("Enter coordinates to move the drone to (x y): ");
        int x, y;
        scanf("%d %d", &x, &y);
        
        if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }
        
        // Check if the move is valid
        if(abs(drone_to_move->x - x) > 1 || abs(drone_to_move->y - y) > 1 || (drone_to_move->x == x && drone_to_move->y == y)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        // Move drone and update board
        board[drone_to_move->x][drone_to_move->y] = '.';
        board[x][y] = drone_to_move->label;
        drone_to_move->x = x;
        drone_to_move->y = y;
        print_board(board);
        
        // Check if a player has won
        int opponent = (curr_player + 1) % 2;
        int has_won = 1;
        for(int i = 0; i < NUM_DRONES; i++) {
            if(board[players[opponent].drones[i].x][players[opponent].drones[i].y] != '.') {
                has_won = 0;
                break;
            }
        }
        if(has_won) {
            printf("%s wins!\n", players[curr_player].name);
            break;
        }
        
        // Check if the game is a draw
        int is_draw = 1;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == '.') {
                    is_draw = 0;
                    break;
                }
            }
            if(!is_draw) {
                break;
            }
        }
        if(is_draw) {
            printf("It's a draw!\n");
            break;
        }
        
        curr_player = (curr_player + 1) % 2;
    }
    
    return 0;
}