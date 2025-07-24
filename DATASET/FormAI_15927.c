//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include<stdio.h>

char board[3][3];  // Global declaration of Tic Tac Toe board

// Function to display Tic Tac Toe board
void display_board() {
    printf("\n\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("\t\t\t     |     |     \n");
}

// Function to check if the game is over
int game_over() {
    int i, j;
    // Checking for rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Checking for columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    // Checking for diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    // Checking for tie game
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    // If all cells are filled and no winning combination found
    return 2;
}

// Function to play AI move
void play_AI_move() {
    int i, j, count = 0;
    // Checking for possible win
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char temp = board[i][j];
                board[i][j] = 'O';
                if (game_over() == 1) {
                    return;
                }
                board[i][j] = temp;
            }
        }
    }
    // Checking for possible block
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char temp = board[i][j];
                board[i][j] = 'X';
                if (game_over() == 1) {
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = temp;
            }
        }
    }
    // If center is available, take it
    if (board[1][1] != 'X' && board[1][1] != 'O') {
        board[1][1] = 'O';
        return;
    }
    // If any of the corner is available, take it
    if (board[0][0] != 'X' && board[0][0] != 'O') {
        board[0][0] = 'O';
        return;
    }
    if (board[0][2] != 'X' && board[0][2] != 'O') {
        board[0][2] = 'O';
        return;
    }
    if (board[2][0] != 'X' && board[2][0] != 'O') {
        board[2][0] = 'O';
        return;
    }
    if (board[2][2] != 'X' && board[2][2] != 'O') {
        board[2][2] = 'O';
        return;
    }
    // Play any available cell
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

// Function to play player move
void play_player_move() {
    int row, col;
    printf("Enter row number:");
    scanf("%d", &row);
    printf("Enter column number:");
    scanf("%d", &col);
    row -= 1;  // Converting to 0-based indexing
    col -= 1;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move, try again.\n");
        play_player_move();
    } else {
        board[row][col] = 'X';
    }
}

int main() {
    int result;
    int i, j;
    // Initializing board with empty cells
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    printf("LET'S PLAY TIC TAC TOE\n");
    display_board();
    while (1) {
        printf("YOUR TURN\n");
        play_player_move();
        display_board();
        result = game_over();
        if (result == 1) {
            printf("YOU WON!\n");
            break;
        } else if (result == 2) {
            printf("TIE GAME!\n");
            break;
        }
        printf("AI TURN\n");
        play_AI_move();
        display_board();
        result = game_over();
        if (result == 1) {
            printf("AI WON!\n");
            break;
        } else if (result == 2) {
            printf("TIE GAME!\n");
            break;
        }
    }
    return 0;
}