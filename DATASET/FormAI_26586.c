//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_SHIPS 3
#define MAX_ATTEMPTS 25

char board[BOARD_SIZE][BOARD_SIZE];
int ships[MAX_SHIPS][2];
int attempts = 0;

void initialize_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '~';
        }
    }
}

void initialize_ships() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SHIPS;) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        int found = 0;
        for(int j = 0; j < i; j++) {
            if(x == ships[j][0] && y == ships[j][1]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            ships[i][0] = x;
            ships[i][1] = y;
            i++;
        }
    }
}

void print_board() {
    printf("  ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void play_game() {
    while(1) {
        printf("Enter cell to hit (e.g. A3): ");
        char col;
        int row;
        scanf(" %c%d", &col, &row);
        int x = col - 'A';
        int y = row;
        if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if(board[x][y] == 'X' || board[x][y] == 'O') {
            printf("You've already hit that cell. Try again.\n");
            continue;
        }
        attempts++;
        if(board[x][y] == '~') {
            printf("You missed!\n");
            board[x][y] = 'O';
        } else {
            printf("You hit a ship!\n");
            board[x][y] = 'X';
            int sunk = 1;
            for(int i = 0; i < MAX_SHIPS; i++) {
                if(board[ships[i][0]][ships[i][1]] == '~') {
                    sunk = 0;
                    break;
                }
            }
            if(sunk) {
                printf("Congratulations, you've sunk all the ships!\n");
                break;
            }
        }
        if(attempts == MAX_ATTEMPTS) {
            printf("Game over. You've run out of attempts.\n");
            break;
        }
        print_board();
    }
}

int main() {
    initialize_board();
    initialize_ships();
    printf("Welcome to Battleship!\n");
    printf("You have %d attempts to sink all the ships.\n", MAX_ATTEMPTS);
    print_board();
    play_game();
    return 0;
}