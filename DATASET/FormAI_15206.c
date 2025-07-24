//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];
char human_piece = 'X', ai_piece = 'O';

void initialize_board(){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = ' ';
        }
    }
}

void print_board(){
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++){
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != BOARD_SIZE - 1) printf("\n---|---|---\n");
    }
    printf("\n");
}

bool is_move_valid(int row, int col){
    if (board[row][col] == ' ') return true;
    else return false;
}

bool is_board_full(){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

bool check_win(char piece){
    for (int i = 0; i < BOARD_SIZE; i++){
        if (board[i][0] == piece && board[i][1] == piece && board[i][2] == piece) return true;
        if (board[0][i] == piece && board[1][i] == piece && board[2][i] == piece) return true;
    }
    if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece) return true;
    if (board[0][2] == piece && board[1][1] == piece && board[2][0] == piece) return true;
    return false;
}

int minimax(bool maximizing_player){
    if (check_win(human_piece))
        return -10;
    else if (check_win(ai_piece))
        return 10;
    else if (is_board_full())
        return 0;
    
    int best_move = 0;
    int best_score = maximizing_player ? -10000 : 10000;

    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] == ' '){
                if (maximizing_player){
                    board[i][j] = ai_piece;
                    int score = minimax(false);
                    board[i][j] = ' ';
                    if (score > best_score){
                        best_score = score;
                        best_move = i * BOARD_SIZE + j;
                    }
                }else{
                    board[i][j] = human_piece;
                    int score = minimax(true);
                    board[i][j] = ' ';
                    if (score < best_score){
                        best_score = score;
                        best_move = i * BOARD_SIZE + j;
                    }
                }
            }
        }
    }
    return best_move;
}

int main(){
    int row, col, move;
    bool player_turn = true;
    initialize_board();

    printf("\nWelcome to Tic Tac Toe AI! You are %c and AI is %c.\n", human_piece, ai_piece);
    while (true){
        if (player_turn){
            printf("\nYour Turn. Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            if (row >= 1 && row <= BOARD_SIZE && col >= 1 && col <= BOARD_SIZE){
                row--;
                col--;
                if (is_move_valid(row, col)){
                    board[row][col] = human_piece;
                    player_turn = false;
                }else{
                    printf("\nInvalid move. Please try again.\n");
                }
            }else{
                printf("\nInvalid position. Please enter a value within 1-3.\n");
            }
        }else{
            printf("\nAI's turn.\n");
            move = minimax(true);
            row = move / BOARD_SIZE;
            col = move % BOARD_SIZE;
            board[row][col] = ai_piece;
            player_turn = true;
        }
        print_board();
        if (check_win(human_piece)){
            printf("\nCongratulations! You have won the game.\n");
            break;
        }else if (check_win(ai_piece)){
            printf("\nAI has won the game. Better luck next time!\n");
            break;
        }else if (is_board_full()){
            printf("\nThe game is a draw! Good game.\n");
            break;
        }
    }
}