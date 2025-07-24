//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: rigorous
#include <stdio.h>

// Defining the board size
#define BOARD_SIZE 3

// Defining the available spaces on the board
#define AVAILABLE_SPACE ' '

// Defining the players
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Defining the directions of a win
#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 2

// Defining the current player and AI player
char current_player = PLAYER_ONE;
char ai_player = PLAYER_TWO;

// Function to create the board
void create_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = AVAILABLE_SPACE;
        }
    }
}

// Function to display the board
void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if there is a win
int check_win(char board[BOARD_SIZE][BOARD_SIZE], int direction) {
    int i, j, count;
    
    if(direction == HORIZONTAL) {
        for(i = 0; i < BOARD_SIZE; i++) {
            count = 0;
            for(j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == current_player) {
                    count++;
                }
            }
            if(count == BOARD_SIZE) {
                return 1;
            }
        }
    }
    
    if(direction == VERTICAL) {
        for(j = 0; j < BOARD_SIZE; j++) {
            count = 0;
            for(i = 0; i < BOARD_SIZE; i++) {
                if(board[i][j] == current_player) {
                    count++;
                }
            }
            if(count == BOARD_SIZE) {
                return 1;
            }
        }
    }
    
    if(direction == DIAGONAL) {
        count = 0;
        for(i = 0; i < BOARD_SIZE; i++) {
            if(board[i][i] == current_player) {
                count++;
            }
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
        
        count = 0;
        for(i = 0; i < BOARD_SIZE; i++) {
            if(board[i][BOARD_SIZE - i - 1] == current_player) {
                count++;
            }
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }
    
    return 0;
}

// Function to check if the game is a tie
int check_tie(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == AVAILABLE_SPACE) {
                return 0;
            }
        }
    }
    
    return 1;
}

// Function to make a move
void make_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    board[row][col] = current_player;
}

// Function to unmake a move
void unmake_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    board[row][col] = AVAILABLE_SPACE;
}

// Function to evaluate the board
int evaluate_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j, score;
    
    score = 0;
    
    // Checking rows
    for(i = 0; i < BOARD_SIZE; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if(board[i][0] == ai_player) {
                return 10;
            } else if(board[i][0] == current_player) {
                return -10;
            }
        }
    }
    
    // Checking columns
    for(j = 0; j < BOARD_SIZE; j++) {
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            if(board[0][j] == ai_player) {
                return 10;
            } else if(board[0][j] == current_player) {
                return -10;
            }
        }
    }
    
    // Checking diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if(board[0][0] == ai_player) {
            return 10;
        } else if(board[0][0] == current_player) {
            return -10;
        }
    }
    
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        if(board[0][2] == ai_player) {
            return 10;
        } else if(board[0][2] == current_player) {
            return -10;
        }
    }
    
    return 0;
}

// Function to find the best move
int find_best_move(char board[BOARD_SIZE][BOARD_SIZE], int depth, int is_max_player) {
    int i, j, max, min, score, best_row = -1, best_col = -1;
    
    // Checking if the game is over
    score = evaluate_board(board);
    if(score == 10) {
        return score - depth;
    } else if(score == -10) {
        return score + depth;
    } else if(check_tie(board)) {
        return 0;
    }
    
    if(is_max_player) {
        max = -1000000;
        
        for(i = 0; i < BOARD_SIZE; i++) {
            for(j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == AVAILABLE_SPACE) {
                    make_move(board, i, j);
                    score = find_best_move(board, depth + 1, 0);
                    unmake_move(board, i, j);
                    if(score > max) {
                        max = score;
                        best_row = i;
                        best_col = j;
                    }
                }
            }
        }
        
        if(depth == 0) {
            return (best_row * 3) + best_col;
        } else {
            return max;
        }
    } else {
        min = 1000000;
        
        for(i = 0; i < BOARD_SIZE; i++) {
            for(j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == AVAILABLE_SPACE) {
                    make_move(board, i, j);
                    score = find_best_move(board, depth + 1, 1);
                    unmake_move(board, i, j);
                    if(score < min) {
                        min = score;
                        best_row = i;
                        best_col = j;
                    }
                }
            }
        }
        
        if(depth == 0) {
            return (best_row * 3) + best_col;
        } else {
            return min;
        }
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int move, row, col;
    
    create_board(board);
    
    printf("Tic Tac Toe\n");
    
    while(1) {
        printf("\n");
        display_board(board);
        
        // Checking if the game is over
        if(check_win(board, HORIZONTAL) || check_win(board, VERTICAL) || check_win(board, DIAGONAL)) {
            printf("Game over! %c wins!\n", current_player);
            break;
        } else if(check_tie(board)) {
            printf("Game over! Tie!\n");
            break;
        }
        
        // Checking if it is the AI's turn
        if(current_player == ai_player) {
            printf("AI's turn.\n");
            move = find_best_move(board, 0, 1);
            row = move / 3;
            col = move % 3;
        } else {
            printf("Your turn. Enter row and column: ");
            scanf("%d %d", &row, &col);
            row--;
            col--;
        }
        
        if(row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != AVAILABLE_SPACE) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        make_move(board, row, col);
        
        // Switching players
        if(current_player == PLAYER_ONE) {
            current_player = PLAYER_TWO;
        } else {
            current_player = PLAYER_ONE;
        }
    }
    
    return 0;
}