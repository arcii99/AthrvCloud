//FormAI DATASET v1.0 Category: Chess AI ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int evaluate_board(char board[][SIZE]) {
    int score = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            switch (board[i][j]) {
                case 'P':
                    score += 1;
                    break;
                case 'N':
                    score += 3;
                    break;
                case 'B':
                    score += 3;
                    break;
                case 'R':
                    score += 5;
                    break;
                case 'Q':
                    score += 9;
                    break;
                case 'K':
                    score += 10;
                    break;
                case 'p':
                    score -= 1;
                    break;
                case 'n':
                    score -= 3;
                    break;
                case 'b':
                    score -= 3;
                    break;
                case 'r':
                    score -= 5;
                    break;
                case 'q':
                    score -= 9;
                    break;
                case 'k':
                    score -= 10;
                    break;
            }
        }
    }
    return score;
}

void display_board(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", SIZE - i); // print y-axis label
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n_|_|_|_|_|_|_|_|_\n");
    }
    printf(" a b c d e f g h\n"); // print x-axis label
}

int main() {
    char board[SIZE][SIZE] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
    display_board(board);
    int score = evaluate_board(board);
    printf("Score: %d\n", score);

    srand(time(NULL)); // seed the random number generator
    char moves[100][6]; // array to store moves (e.g. "e2e4")
    int num_moves = 0; // number of moves in array
    while (num_moves < 100) {
        char start_row, start_col, end_row, end_col;
        start_col = rand() % 8 + 'a'; // generate random starting position
        start_row = rand() % 8 + '1';
        end_col = rand() % 8 + 'a'; // generate random ending position
        end_row = rand() % 8 + '1';
        moves[num_moves][0] = start_col;
        moves[num_moves][1] = start_row;
        moves[num_moves][2] = end_col;
        moves[num_moves][3] = end_row;
        moves[num_moves][4] = '\0'; // null terminator
        printf("Move %d: %s\n", num_moves + 1, moves[num_moves]);
        char piece = board[start_row - '1'][start_col - 'a'];
        board[start_row - '1'][start_col - 'a'] = ' ';
        board[end_row - '1'][end_col - 'a'] = piece;
        display_board(board);
        score = evaluate_board(board);
        printf("Score: %d\n", score);
        if (score >= 20) {
            printf("I win!\n");
            break;
        }
        num_moves++;
    }
    if (num_moves == 100) {
        printf("I give up.\n");
    }
    return 0;
}