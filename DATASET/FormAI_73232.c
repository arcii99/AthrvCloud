//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>

char board[3][3]; // Declare the Tic Tac Toe board as a 2D char array

// Function to display the board
void display_board() {
    printf("\nTic Tac Toe\n\n");
    
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        
        if(i != 2) {
            printf("\n---|---|---\n");
        }
    }
    
    printf("\n\n");
}

// Function to check if a given move is valid
int is_valid_move(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to check if the game has ended
int is_game_over(char symbol) {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    
    // Check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    
    // Check diagonals
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    
    // Check for tie
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    
    return 2;
}

// Minimax algorithm for the AI
int minimax(char whose_turn) {
    int score = -2;
    int row = -1;
    int col = -1;
    
    // Check if the game is over
    int game_result = is_game_over('X');
    if(game_result != 0) {
        if(game_result == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    
    // Loop through all possible moves
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                // Make the move
                board[i][j] = whose_turn;
                
                // Get the score for this move
                int temp_score = -minimax((whose_turn == 'X') ? 'O' : 'X');
                
                // If it's a winning move, take it
                if(temp_score > score) {
                    score = temp_score;
                    row = i;
                    col = j;
                }
                
                // Undo the move
                board[i][j] = ' ';
            }
        }
    }
    
    // If no winning move is found, pick a random valid move
    if(row == -1 || col == -1) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(is_valid_move(i, j)) {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
    }
    
    // Make the move
    board[row][col] = whose_turn;
    
    return score;
}

int main() {
    // Initialize the board
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    
    display_board();
    
    while(1) {
        int user_row, user_col;
        
        // Get user input
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &user_row, &user_col);
        
        // Convert input to array index
        user_row--;
        user_col--;
        
        // Check if the move is valid
        if(!is_valid_move(user_row, user_col)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        
        // Make the move
        board[user_row][user_col] = 'O';
        
        display_board();
        
        // Check if the game is over
        int game_result = is_game_over('O');
        if(game_result != 0) {
            if(game_result == 1) {
                printf("You win!\n");
            } else {
                printf("It's a tie!\n");
            }
            break;
        }
        
        printf("AI's turn...\n");
        
        // Make the AI move
        minimax('X');
        
        display_board();
        
        // Check if the game is over
        game_result = is_game_over('X');
        if(game_result != 0) {
            if(game_result == 1) {
                printf("AI wins!\n");
            } else {
                printf("It's a tie!\n");
            }
            break;
        }
    }
    
    return 0;
}