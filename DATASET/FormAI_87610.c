//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>

// Function to check if the board has a winner
int find_winner(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    // If no winner, return 0
    return 0;
}

// Function to display the board
void display_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
}

// Recursive function for finding the best move for the AI
int minimax(char board[3][3], int depth, int is_maximizing) {
    // Base case: If the board has a winner or is a draw, return the score
    int winner = find_winner(board);
    if (winner != 0) {
        return winner == 'X' ? 10 - depth : depth - 10;
    }
    int is_full = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                is_full = 0;
            }
        }
    }
    if (is_full) {
        return 0;
    }
    // Recursive case: Evaluate all possible moves and return the best score
    int best_score = is_maximizing ? -100 : 100;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = is_maximizing ? 'X' : 'O';
                int score = minimax(board, depth + 1, !is_maximizing);
                best_score = is_maximizing ? (score > best_score ? score : best_score) : (score < best_score ? score : best_score);
                board[i][j] = ' ';
            }
        }
    }
    return best_score;
}

// Function for making the AI's move
void make_ai_move(char board[3][3]) {
    int best_score = -100;
    int best_i, best_j;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                int score = minimax(board, 0, 0);
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }
    board[best_i][best_j] = 'X';
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int player = 1;
    while (find_winner(board) == 0) {
        system("clear");
        printf("It is Player %d's turn.\n\n", player);
        display_board(board);
        if (player == 1) { // Human player
            int row, col;
            printf("Enter the row and column of your move (e.g. '1 2' for first row, second column): ");
            scanf("%d %d", &row, &col);
            if (board[row-1][col-1] != ' ') {
                printf("That square is already taken. Please choose another move.\n");
                continue;
            }
            board[row-1][col-1] = 'O';
        } else { // AI player
            printf("The AI is thinking...\n");
            make_ai_move(board);
            printf("The AI has made its move.\n");
        }
        player = player == 1 ? 2 : 1;
    }
    system("clear");
    printf("Game over. ");
    display_board(board);
    int winner = find_winner(board);
    if (winner == 'O') {
        printf("Player 1 wins!\n");
    } else if (winner == 'X') {
        printf("The AI wins!\n");
    } else {
        printf("It's a draw!\n");
    }
    return 0;
}