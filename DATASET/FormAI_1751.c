//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_PLAYERS 4

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char name[20];
    Position position;
    int score;
} Player;

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = (i + j) % 7;
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void create_players(Player players[MAX_PLAYERS], int num_players) {
    int i;
    for(i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].position.row = 0;
        players[i].position.col = 0;
        players[i].score = 0;
    }
}

void print_player_info(Player players[MAX_PLAYERS], int num_players) {
    int i;
    for(i = 0; i < num_players; i++) {
        printf("%s: Score: %d, Current Position: (%d,%d)\n", players[i].name, players[i].score, players[i].position.row, players[i].position.col);
    }
}

void move_player(Player *player, int board[BOARD_SIZE][BOARD_SIZE], int move) {
    switch(move) {
        case 1: // Move up
            if(player->position.row > 0) {
                player->position.row--;
            }
            break;
        case 2: // Move down
            if(player->position.row < BOARD_SIZE-1) {
                player->position.row++;
            }
            break;
        case 3: // Move left
            if(player->position.col > 0) {
                player->position.col--;
            }
            break;
        case 4: // Move right
            if(player->position.col < BOARD_SIZE-1) {
                player->position.col++;
            }
            break;
        default:
            printf("Invalid move\n");
    }
    player->score += board[player->position.row][player->position.col];
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int num_players;
    Player players[MAX_PLAYERS];

    srand(time(NULL));
    initialize_board(board);
    print_board(board);

    do {
        printf("Enter the number of players (max %d): ", MAX_PLAYERS);
        scanf("%d", &num_players);
    } while(num_players > MAX_PLAYERS || num_players < 1);

    create_players(players, num_players);
    print_player_info(players, num_players);

    int current_player = 0;
    int game_over = 0;

    while(!game_over) {
        printf("%s's turn\n", players[current_player].name);
        printf("Enter move (1-up, 2-down, 3-left, 4-right): ");
        int move;
        scanf("%d", &move);
        move_player(&players[current_player], board, move);
        printf("New position: (%d,%d)\n", players[current_player].position.row, players[current_player].position.col);
        print_player_info(players, num_players);

        if(players[current_player].score >= 100) {
            printf("%s wins!\n", players[current_player].name);
            game_over = 1;
        } else {
            current_player++;
            if(current_player >= num_players) {
                current_player = 0;
            }
        }

    }

    return 0;
}