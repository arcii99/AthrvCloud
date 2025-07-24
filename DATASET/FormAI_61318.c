//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

bool is_move_valid(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ')
        return false;
    return true;
}

bool is_game_over() {
    int i, j;
    //check horizontal lines
    for(i=0; i < BOARD_SIZE; i++) {
        if( (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != ' ') {
            return true;
        }
    }
    //check vertical lines
    for(i=0; i < BOARD_SIZE; i++) {
        if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[0][i] != ' ') {
            return true;
        }
    }
    //check diagonal lines
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != ' ') {
        return true;
    }
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[0][2] != ' ') {
        return true;
    }
    //check for tie
    for(i=0; i < BOARD_SIZE; i++) {
        for(j=0; j < BOARD_SIZE; j++) {
            if(board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

char get_winner() {
    int i, j;
    //check horizontal lines
    for(i=0; i < BOARD_SIZE; i++) {
        if( (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    //check vertical lines
    for(i=0; i < BOARD_SIZE; i++) {
        if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[0][i] != ' ') {
            return board[0][i];
        }
    }
    //check diagonal lines
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != ' ') {
        return board[0][0];
    }
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[0][2] != ' ') {
        return board[0][2];
    }
    return ' ';
}

void print_board() {
    int i, j;
    for(i=0; i < BOARD_SIZE; i++) {
        for(j=0; j < BOARD_SIZE; j++) {
            if(j < BOARD_SIZE-1)
                printf(" %c |", board[i][j]);
            else
                printf(" %c ", board[i][j]);
        }
        if(i < BOARD_SIZE-1)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

bool player_move() {
    int row, col;
    do {
        printf("Enter row (0-2) and column (0-2) separated by a space: ");
        scanf("%d %d", &row, &col);
    } while (!is_move_valid(row, col));
    board[row][col] = 'X';
    if(is_game_over()) {
        return true;
    }
    return false;
}

bool AI_move() {
    int i, j;
    //first check if AI can win in next move
    for(i=0; i < BOARD_SIZE; i++) {
        for(j=0; j < BOARD_SIZE; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                if(get_winner() == 'O') {
                    return true;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
    //then block player's winning move
    for(i=0; i < BOARD_SIZE; i++) {
        for(j=0; j < BOARD_SIZE; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'X';
                if(get_winner() == 'X') {
                    board[i][j] = 'O';
                    return false;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
    //take center if available
    if(board[1][1] == ' ') {
        board[1][1] = 'O';
        return false;
    }
    //take a random corner
    if(board[0][0] == ' ') {
        board[0][0] = 'O';
    } else if(board[0][2] == ' ') {
        board[0][2] = 'O';
    } else if(board[2][0] == ' ') {
        board[2][0] = 'O';
    } else if(board[2][2] == ' ') {
        board[2][2] = 'O';
    }
    return false;
}

int main() {
    int turn = 0;
    while(!is_game_over()) {
        print_board();
        if(turn%2 == 0) {
            if(player_move())
                break;
        } else {
            if(AI_move())
                break;
        }
        turn++;
    }
    print_board();
    if(get_winner() == 'X')
        printf("Congratulations, you won!\n");
    else if(get_winner() == 'O')
        printf("Sorry, you lost.\n");
    else
        printf("It's a tie.\n");
    return 0;
}