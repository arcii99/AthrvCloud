//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(char board[][3]) {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf("\t%c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if(i != 2) printf("\t---------\n");
    }
    printf("\n");
}

int validate_move(char board[][3], int row, int col) {
    if(board[row][col] != ' ') return 0;
    else return 1;
}

int check_win(char board[][3]) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') return 1;
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') return 1;
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') return 1;
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') return 1;
    return 0;
}

int get_best_move(char board[][3], char symbol, int depth) {
    int score = -2;
    int best_move = -1;
    if(check_win(board)) {
        if(symbol == 'X') return -1;
        else return 1;
    }
    if(depth == 9) return 0;
    for(int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;
        if(validate_move(board, row, col)) {
            board[row][col] = symbol;
            int temp_score = -get_best_move(board, symbol == 'X' ? 'O' : 'X', depth+1);
            board[row][col] = ' ';
            if(temp_score > score) {
                score = temp_score;
                best_move = i;
            }
        }
    }
    if(best_move == -1) return 0;
    return best_move;
}

void play_game() {
    char symbol = 'X';
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    print_board(board);
    while(1) {
        if(check_win(board)) {
            printf("\tYou lost, my dear Watson!\n\n");
            break;
        }
        if(symbol == 'X') {
            printf("Make your move, Watson: (row col) ");
            int row, col;
            scanf("%d %d", &row, &col);
            row--; col--;
            if(!validate_move(board, row, col)) {
                printf("\nThat's an invalid move, Watson. Try again.\n\n");
                continue;
            }
            board[row][col] = symbol;
            printf("\n");
            print_board(board);
            symbol = 'O';
        }
        else {
            printf("I am making my move, Watson...\n\n");
            int move = get_best_move(board, symbol, 0);
            int row = move / 3;
            int col = move % 3;
            board[row][col] = symbol;
            print_board(board);
            symbol = 'X';
        }
    }
}

int main() {
    printf("Welcome to the game of Tic Tac Toe!\n");
    printf("Can you beat me, dear Watson? Let's find out.\n\n");
    play_game();
    return 0;
}