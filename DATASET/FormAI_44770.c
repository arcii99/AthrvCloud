//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>

char board[3][3]; // the Tic Tac Toe board
char computer_piece; // the piece that the computer will play with
char player_piece; // the piece that the player will play with

/*
 * This function prints the Tic Tac Toe board in the console
 */
void print_board() {
    printf("\n");

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }

    printf("\n");
}

/*
 * This function checks if a certain player has won the game
 */
int check_win(char piece) {
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == piece && board[row][1] == piece && board[row][2] == piece) {
            return 1;
        }
    }

    for (int col = 0; col < 3; col++) {
        if (board[0][col] == piece && board[1][col] == piece && board[2][col] == piece) {
            return 1;
        }
    }

    if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece) {
        return 1;
    }

    if (board[0][2] == piece && board[1][1] == piece && board[2][0] == piece) {
        return 1;
    }

    return 0;
}

/*
 * This function checks if the board is full
 */
int board_full() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

/*
 * This function gets the player's move and updates the board
 */
void player_move() {
    int row, col;

    printf("Enter your row and column (1-3): ");
    scanf("%d %d", &row, &col);

    if (board[row - 1][col - 1] != ' ') {
        printf("That spot is already taken. Try again.\n");
        player_move();
    } else {
        board[row - 1][col - 1] = player_piece;
    }
}

/*
 * This function gets the computer's move and updates the board
 */
void computer_move() {
    int row, col;

    // the AI strategy is to go for the win first, then to block the player if they are about to win,
    // and finally to make a random move if neither of those conditions are met

    // go for the win
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = computer_piece;

                if (check_win(computer_piece)) {
                    return;
                } else {
                    board[row][col] = ' ';
                }
            }
        }
    }

    // block the player's win
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = player_piece;

                if (check_win(player_piece)) {
                    board[row][col] = computer_piece;
                    return;
                } else {
                    board[row][col] = ' ';
                }
            }
        }
    }

    // make a random move
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = computer_piece;
}

/*
 * This function runs the main game loop
 */
void game_loop() {
    while (!board_full()) {
        printf("Player's turn:\n");
        player_move();
        print_board();

        if (check_win(player_piece)) {
            printf("Congratulations! You win!\n");
            return;
        }

        printf("Computer's turn:\n");
        computer_move();
        print_board();

        if (check_win(computer_piece)) {
            printf("Oh no! The computer wins.\n");
            return;
        }
    }

    printf("It's a draw.\n");
}

int main() {
    // initialize the board to be empty
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }

    // determine whether the player wants to be X or O
    int choice;

    printf("Do you want to be X or O? (1 for X, 2 for O): ");
    scanf("%d", &choice);

    if (choice == 1) {
        player_piece = 'X';
        computer_piece = 'O';
    } else {
        player_piece = 'O';
        computer_piece = 'X';
    }

    // run the game loop
    printf("Let's play Tic Tac Toe!\n");
    game_loop();

    return 0;
}