//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

char board[3][3];       // Initializes the 2D array that will hold our Tic Tac Toe board
void init_board();      // Function to initialize the board to blank spaces
void print_board();     // Function to print the current state of the board
int win_check(char);    // Function to check for a win condition based on the character input (either 'O' or 'X')
int ai_move();          // Function that implements the AI to select the next move
int user_move();        // Function that allows the user to make a move

int main()
{
    int turn = 0;       // Tracks the number of turns taken so far
    int winner = 0;     // Tracks whether a winner has been determined
    init_board();

    printf("Welcome to Tic Tac Toe!\n");
    printf("You are X and the AI is O. Good luck!\n\n");
    print_board();

    while (turn < 9 && winner == 0) {
        if (turn % 2 == 0) {
            user_move();    // User goes on even turns
        } else {
            ai_move();      // AI goes on odd turns
        }
        print_board();
        winner = win_check('O');
        if (winner == 0) {
            winner = win_check('X');
        }
        turn++;
    }
    if (winner == 1) {
        printf("Congratulations, you won!\n");
    } else if (winner == -1) {
        printf("Sorry, the AI won. Better luck next time!\n");
    } else {
        printf("It's a tie! Good game.\n");
    }

    return 0;
}

void init_board()
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board()
{
    int i, j;
    printf("-------------\n");
    for (i = 0; i < 3; i++) {
        printf("|");
        for (j = 0; j < 3; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

int win_check(char ch)
{
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == ch && board[i][1] == ch && board[i][2] == ch) {
            return 1;
        }
        if (board[0][i] == ch && board[1][i] == ch && board[2][i] == ch) {
            return 1;
        }
    }
    if (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) {
        return 1;
    }
    if (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch) {
        return 1;
    }
    return 0;
}

int ai_move()
{
    int i, j;
    int move = 0;
    printf("AI is thinking...");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = -user_move();   //recursive call
                board[i][j] = ' ';
                if (score > move) {
                    move = score;
                    if (move == 1) {    // optimal move found, exit search
                        goto END_SEARCH;
                    }
                }
            }
        }
    }

    END_SEARCH:;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                if (win_check('O')) {
                    return -1;
                }
                return 0;
            }
        }
    }
}

int user_move()
{
    int row, col;
    printf("Enter row (1-3): ");
    scanf("%d", &row);
    printf("Enter column (1-3): ");
    scanf("%d", &col);
    row--;
    col--;
    if (board[row][col] != ' ') {
        printf("That space is already taken. Please choose another.\n");
        return user_move();
    } else {
        board[row][col] = 'X';
        if (win_check('X')) {
            return 1;
        }
        return 0;
    }
}