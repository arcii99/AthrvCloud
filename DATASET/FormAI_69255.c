//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3  // Size of the board

char board[SIZE][SIZE];  // The Tic Tac Toe board

// Check if the game is over
int is_game_over()
{
    int i, j;
    // Check rows
    for (i = 0; i < SIZE; i++)
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    // Check columns
    for (j = 0; j < SIZE; j++)
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;
    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    // Check if all spots are filled
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (board[i][j] == '-')
                return 0;
    return 2;
}

// Evaluate board value
int evaluate(char player, int depth)
{
    int i, j, score = 0;
    // Check rows
    for (i = 0; i < SIZE; i++) {
        int count = 0;
        for (j = 0; j < SIZE; j++)
            if (board[i][j] == player)
                count++;
        if (count == 3)
            score += 100 - depth;
        else if (count == 2)
            score += 10;
        else if (count == 1)
            score += 1;
    }
    // Check columns
    for (j = 0; j < SIZE; j++) {
        int count = 0;
        for (i = 0; i < SIZE; i++)
            if (board[i][j] == player)
                count++;
        if (count == 3)
            score += 100 - depth;
        else if (count == 2)
            score += 10;
        else if (count == 1)
            score += 1;
    }
    // Check diagonals
    int count = 0;
    for (i = 0; i < SIZE; i++)
        if (board[i][i] == player)
            count++;
    if (count == 3)
        score += 100 - depth;
    else if (count == 2)
        score += 10;
    else if (count == 1)
        score += 1;
    count = 0;
    for (i = 0; i < SIZE; i++)
        if (board[i][SIZE - i - 1] == player)
            count++;
    if (count == 3)
        score += 100 - depth;
    else if (count == 2)
        score += 10;
    else if (count == 1)
        score += 1;
    return score;
}

// Minimax algorithm
int minimax(char player, int depth)
{
    int i, j;
    int score;
    int best_score = -1000;
    int best_row = -1;
    int best_col = -1;
    
    if (is_game_over() == 1)
        return evaluate(player,depth);
    else if (is_game_over() == 2)
        return 0;
    
    // Generate all possible moves
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                board[i][j] = player;
                if (player == 'X')
                    score = minimax('O', depth+1);
                else
                    score = minimax('X', depth+1);
                board[i][j] = '-';
                
                if (score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    
    if (depth == 0) {
        printf("Computer's move: %d %d\n", best_row, best_col);
        board[best_row][best_col] = player;
    }
    
    if (player == 'X')
        return best_score;
    else
        return -best_score;
}

int main()
{
    int i, j;
    // Initialize board
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            board[i][j] = '-';
    // Play game
    printf("Instructions: Enter row and column numbers (0, 1, or 2) separated by a space.\n");
    printf("You are 'O', computer is 'X'.\n");
    while (!is_game_over()) {
        // Print board
        printf("\n");
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++)
                printf("%c ", board[i][j]);
            printf("\n");
        }
        // Take user input
        int row, col;
        printf("Your move: ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[row][col] = 'O';
        // Take computer's move
        minimax('X', 0);
    }
    // Print final board and result
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    if (is_game_over() == 1)
        printf("Computer wins!\n");
    else
        printf("Tie.\n");
    return 0;
}