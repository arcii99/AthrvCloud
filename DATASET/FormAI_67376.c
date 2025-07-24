//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {{0}};
int players_turn = 1;

void print_board() {
    printf("\n   ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
    }
    printf("\n");

    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %d|", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                printf("  ");
            } else if(board[i][j] == 1) {
                printf("x ");
            } else {
                printf("o ");
            }
        }
        printf("|%d\n", i+1);
    }
    printf("   ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
    }
}

bool can_capture(int i, int j, int new_i, int new_j) {
    int capture_i, capture_j;
    if(new_i > i && new_j > j) {
        capture_i = i + 1;
        capture_j = j + 1;
    } else if(new_i > i && new_j < j) {
        capture_i = i + 1;
        capture_j = j - 1;
    } else if(new_i < i && new_j < j) {
        capture_i = i - 1;
        capture_j = j - 1;
    } else {
        capture_i = i - 1;
        capture_j = j + 1;
    }

    if(capture_i < 0 || capture_i >= BOARD_SIZE || capture_j < 0 || capture_j >= BOARD_SIZE) {
        return false;
    }

    if(board[capture_i][capture_j] == 0 || board[capture_i][capture_j] == players_turn) {
        return false;
    }

    return true;
}

bool can_move(int i, int j, int new_i, int new_j) {
    if(new_i < 0 || new_i >= BOARD_SIZE || new_j < 0 || new_j >= BOARD_SIZE) {
        return false;
    }

    if(board[new_i][new_j] != 0) {
        return false;
    }

    if(abs(new_i-i) == 1 && abs(new_j-j) == 1) {
        return true;
    } else if(abs(new_i-i) == 2 && abs(new_j-j) == 2 && can_capture(i, j, new_i, new_j)) {
        return true;
    }

    return false;
}

bool has_valid_moves() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == players_turn) {
                if(can_move(i, j, i+1, j+1) || can_move(i, j, i+1, j-1) ||
                   can_move(i, j, i-1, j-1) || can_move(i, j, i-1, j+1)) {
                    return true;
                }
            } else if(board[i][j] == players_turn+2) {
                if(can_move(i, j, i+1, j+1) || can_move(i, j, i+1, j-1) ||
                   can_move(i, j, i-1, j-1) || can_move(i, j, i-1, j+1) ||
                   can_move(i, j, i+2, j+2) || can_move(i, j, i+2, j-2) ||
                   can_move(i, j, i-2, j-2) || can_move(i, j, i-2, j+2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void make_move(int i, int j, int new_i, int new_j) {
    board[new_i][new_j] = board[i][j];
    board[i][j] = 0;

    if(abs(new_i-i) == 2 && abs(new_j-j) == 2) {
        int capture_i, capture_j;
        if(new_i > i && new_j > j) {
            capture_i = i + 1;
            capture_j = j + 1;
        } else if(new_i > i && new_j < j) {
            capture_i = i + 1;
            capture_j = j - 1;
        } else if(new_i < i && new_j < j) {
            capture_i = i - 1;
            capture_j = j - 1;
        } else {
            capture_i = i - 1;
            capture_j = j + 1;
        }
        board[capture_i][capture_j] = 0;
    }

    if(players_turn == 1 && new_i == BOARD_SIZE - 1) {
        board[new_i][new_j] = 3;
    } else if(players_turn == 2 && new_i == 0) {
        board[new_i][new_j] = 4;
    }
}

void play_game() {
    bool game_over = false;
    while(!game_over) {
        print_board();
        if(!has_valid_moves()) {
            printf("Player %d has no more valid moves. ", players_turn);
            if(players_turn == 1) {
                printf("Player 2 wins!\n");
            } else {
                printf("Player 1 wins!\n");
            }
            break;
        }
        printf("\nPlayer %d's turn!\n", players_turn);
        int i, j, new_i, new_j;
        while(true) {
            printf("Enter the coordinates of the piece you want to move: ");
            scanf("%d %d", &i, &j);
            printf("Enter the coordinates of the destination: ");
            scanf("%d %d", &new_i, &new_j);

            if(can_move(i-1, j-1, new_i-1, new_j-1)) {
                make_move(i-1, j-1, new_i-1, new_j-1);
                if(!has_valid_moves()) {
                    printf("Player %d has no more valid moves. ", players_turn);
                    if(players_turn == 1) {
                        printf("Player 2 wins!\n");
                    } else {
                        printf("Player 1 wins!\n");
                    }
                    game_over = true;
                }
                break;
            } else {
                printf("Invalid move!\n");
                continue;
            }
        }
        players_turn = (players_turn == 1) ? 2 : 1;
    }
}

int main() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if((i+j) % 2 == 1) {
                board[i][j] = 2;
            }
        }
    }
    for(int i=5; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if((i+j) % 2 == 1) {
                board[i][j] = 1;
            }
        }
    }

    printf("Welcome to CyberCheckers!\n");
    play_game();

    return 0;
}