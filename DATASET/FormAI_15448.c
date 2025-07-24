//FormAI DATASET v1.0 Category: Checkers Game ; Style: lively
#include <stdio.h>

#define SIZE 8 // size of the board

char board[SIZE][SIZE]; // the board of the checkers game
char turn = 'w'; // white starts the game

void init_board() {
    // initialize the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) board[i][j] = 'b'; // black pieces
                else if (i > 4) board[i][j] = 'w'; // white pieces
                else board[i][j] = ' '; // empty spaces
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board() {
    // print the board to the console
    printf("\n   a b c d e f g h\n");
    printf("  -----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d| ", i+1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|%d\n", i+1);
    }
    printf("  -----------------\n");
    printf("   a b c d e f g h\n\n");
}

int main() {
    init_board();
    print_board();

    // main loop of the game
    while (1) {
        // get the user input for the move
        printf("%c's turn\n", turn);
        printf("Enter the starting and ending positions (ex. a3 b4): ");

        char start_col, end_col;
        int start_row, end_row;

        scanf(" %c%d %c%d", &start_col, &start_row, &end_col, &end_row);

        // convert the input to array indices
        int start_i = start_row - 1;
        int start_j = start_col - 'a';
        int end_i = end_row - 1;
        int end_j = end_col - 'a';

        // check if the input is valid
        if (start_i < 0 || start_i >= SIZE || start_j < 0 || start_j >= SIZE || 
            end_i < 0 || end_i >= SIZE || end_j < 0 || end_j >= SIZE) {
            printf("Invalid input\n");
            continue;
        }

        // check if the move is legal
        if (board[start_i][start_j] == ' ' || board[start_i][start_j] == '-') {
            printf("No piece to move\n");
            continue;
        }

        if (board[end_i][end_j] != ' ') {
            printf("Cannot move to occupied space\n");
            continue;
        }

        if (turn == 'w') {
            if (board[start_i][start_j] != 'w' && board[start_i][start_j] != 'W') {
                printf("Cannot move opponent's piece\n");
                continue;
            }

            if (end_i - start_i != 1 && end_i - start_i != 2) {
                printf("Invalid move\n");
                continue;
            }

            if (end_j - start_j != 1 && end_j - start_j != -1) {
                printf("Invalid move\n");
                continue;
            }
        } else {
            if (board[start_i][start_j] != 'b' && board[start_i][start_j] != 'B') {
                printf("Cannot move opponent's piece\n");
                continue;
            }

            if (start_i - end_i != 1 && start_i - end_i != 2) {
                printf("Invalid move\n");
                continue;
            }

            if (end_j - start_j != 1 && end_j - start_j != -1) {
                printf("Invalid move\n");
                continue;
            }
        }

        // execute the move
        char piece = board[start_i][start_j];
        board[start_i][start_j] = ' ';
        board[end_i][end_j] = piece;

        // check if there is a capture
        if (start_i - end_i == 2 || end_i - start_i == 2) {
            int mid_i = (start_i + end_i) / 2;
            int mid_j = (start_j + end_j) / 2;
            board[mid_i][mid_j] = '-';
        }

        // check if the piece becomes a king
        if (turn == 'w' && end_i == SIZE-1 && piece == 'w') {
            board[end_i][end_j] = 'W';
        } else if (turn == 'b' && end_i == 0 && piece == 'b') {
            board[end_i][end_j] = 'B';
        }

        print_board();

        // check if the game is over
        int white_count = 0, black_count = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 'w' || board[i][j] == 'W') {
                    white_count++;
                } else if (board[i][j] == 'b' || board[i][j] == 'B') {
                    black_count++;
                }
            }
        }

        if (white_count == 0) {
            printf("Black wins!\n");
            break;
        }

        if (black_count == 0) {
            printf("White wins!\n");
            break;
        }

        // switch turns
        turn = turn == 'w' ? 'b' : 'w';
    }

    return 0;
}