//FormAI DATASET v1.0 Category: Checkers Game ; Style: curious
#include <stdio.h>

// Function to create the board
void create_board(int board[8][8]) {
    int i, j;
    // Loop to set the black pieces on the board
    for(i = 0; i <= 2; i++)
        for(j = 0; j <= 7; j++)
            if(i % 2 == 0 && j % 2 == 0)
                board[i][j] = 1;
            else if(i % 2 == 1 && j % 2 == 1)
                board[i][j] = 1;
            else
                board[i][j] = 0;
    // Loop to set the white pieces on the board
    for(i = 5; i <= 7; i++)
        for(j = 0; j <= 7; j++)
            if(i % 2 == 0 && j % 2 == 0)
                board[i][j] = -1;
            else if(i % 2 == 1 && j % 2 == 1)
                board[i][j] = -1;
            else
                board[i][j] = 0;    
}

// Function to print the board
void print_board(int board[8][8]) {
    int i, j;
    // Loop to print the board
    for(i = 0; i <= 7; i++) {
        for(j = 0; j <= 7; j++)
            if(board[i][j] == 1) {
                if(j != 7)
                    printf("B ");
                else
                    printf("B\n");
            }
            else if(board[i][j] == -1) {
                if(j != 7)
                    printf("W ");
                else
                    printf("W\n");
            }
            else {
                if(j != 7)
                    printf(". ");
                else
                    printf(".\n");
            }
    }
}

// Function to make a move
int make_move(int board[8][8], int x1, int y1, int x2, int y2) {
    // Check if the move is legal
    if(board[x2][y2] != 0 || (x2 + y2) % 2 == 0)
        return 0;
    int dx = x2 - x1;
    int dy = y2 - y1;
    // Check if the move is a capture
    if(abs(dx) == 2 && abs(dy) == 2) {
        int sx = dx / 2;
        int sy = dy / 2;
        if(board[x1 + sx][y1 + sy] * board[x1][y1] < 0) {
            board[x1 + sx][y1 + sy] = 0;
            board[x2][y2] = board[x1][y1];
            board[x1][y1] = 0;
            return 1;
        }
        else
            return 0;
    }
    // Check if the move is a simple move
    else if(abs(dx) == 1 && abs(dy) == 1) {
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = 0;
        return 1;
    }
    else
        return 0;
}

// Function to check if the game is over
int is_game_over(int board[8][8]) {
    int i, j;
    int count_white = 0, count_black = 0;
    // Loop to count the number of white and black pieces left on the board
    for(i = 0; i <= 7; i++)
        for(j = 0; j <= 7; j++)
            if(board[i][j] == 1)
                count_black++;
            else if(board[i][j] == -1)
                count_white++;
    if(count_black == 0)
        return -1; // White wins
    else if(count_white == 0)
        return 1; // Black wins
    else
        return 0; // Game not over yet
}

int main() {
    // Initialize the board
    int board[8][8];
    create_board(board);
    // Print the board
    printf("Starting board:\n");
    print_board(board);
    // Main game loop
    int player = 1;
    int x1, y1, x2, y2;
    while(1) {
        printf("\nPlayer %d's turn:\n", player);
        printf("Enter the x and y coordinates of the piece you want to move: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the x and y coordinates of the square you want to move to: ");
        scanf("%d %d", &x2, &y2);
        // Make the move
        if(make_move(board, x1, y1, x2, y2)) {
            // Check if the game is over
            int game_over = is_game_over(board);
            if(game_over == 1) {
                printf("\nGame over! Black wins!\n");
                break;
            }
            else if(game_over == -1) {
                printf("\nGame over! White wins!\n");
                break;
            }
            // Switch players
            player *= -1;
            // Print the updated board
            printf("\nUpdated board:\n");
            print_board(board);
        }
        else
            printf("\nInvalid move. Please try again.\n");
    }
    return 0;
}