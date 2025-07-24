//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // initialize board with empty spaces

int check_win() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return 1;
        }
    }
    // check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}

void print_board() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void player_move(int player) {
    int row, col;
    printf("Player %d's turn.\n", player);
    printf("Enter row (1-3): ");
    scanf("%d", &row);
    printf("Enter column (1-3): ");
    scanf("%d", &col);
    if (row < 1 || row > 3 || col < 1 || col > 3) { // check if move is valid
        printf("Invalid move. Please try again.\n");
        player_move(player);
    }
    row--;
    col--;
    if (board[row][col] != ' ') { // check if space is already occupied
        printf("That space is already occupied. Please try again.\n");
        player_move(player);
    }
    if (player == 1) {
        board[row][col] = 'X';
    } else {
        board[row][col] = 'O';
    }
    print_board();
}

void ai_move() {
    int row, col;
    printf("Computer's turn.\n");
    // check if there is a winning move for the computer
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                if (check_win()) {
                    printf("Computer wins!\n");
                    print_board();
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // check if there is a winning move for the player
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (check_win()) {
                    board[i][j] = 'O'; // block player's winning move
                    print_board();
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // if no winning moves, take a random spot
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
    print_board();
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    print_board();
    int player = 1;
    while (!check_win()) {
        if (player == 1) {
            player_move(player);
            player = 2;
        } else {
            ai_move();
            player = 1;
        }
    }
    printf("Game over!\n");
    return 0;
}