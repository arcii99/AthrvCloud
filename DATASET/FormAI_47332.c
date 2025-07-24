//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

//2D array for game board
char board[3][3];

//function to print the game board
void print_board() {
    printf("\n\n");
    printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

//function to check if the game is over
int game_over() {
    //check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == 'x') return 1;
            else if (board[row][0] == 'o') return 2;
        }
    }

    //check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == 'x') return 1;
            else if (board[0][col] == 'o') return 2;
        }
    }

    //check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'x') return 1;
        else if (board[0][0] == 'o') return 2;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'x') return 1;
        else if (board[0][2] == 'o') return 2;
    }

    //check for tie
    int count = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] != ' ') count++;
        }
    }
    if (count == 9) return 3;

    return 0;
}

//recursive function for minimax algorithm
int minimax(char player) {
    int score;
    int max_score = -100;
    int min_score = 100;

    //base case
    int result = game_over();
    if (result == 1) return -10;
    else if (result == 2) return 10;
    else if (result == 3) return 0;

    //recursive case
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = player;
                if (player == 'o') {
                    score = minimax('x');
                    if (score > max_score) max_score = score;
                } else if (player == 'x') {
                    score = minimax('o');
                    if (score < min_score) min_score = score;
                }
                board[row][col] = ' '; //undo move
            }
        }
    }

    if (player == 'o') return max_score;
    else if (player == 'x') return min_score;

    return 0;
}

//function for AI move
void ai_move() {
    int row, col, best_score = -100, score;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'o';
                score = minimax('x');
                board[i][j] = ' '; //undo move
                if (score > best_score) {
                    best_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    board[row][col] = 'o';
    printf("\nAI played at row %d col %d\n", row + 1, col + 1);
}

//main function
int main() {
    //initialize game board
    printf("\nWelcome to Tic Tac Toe!\n");
    printf("You are X and the computer is O.\n");
    printf("Enter the row (1-3) and column (1-3) of where you would like to play.\n\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }

    //game loop
    print_board();
    int result;
    while (1) {
        //player move
        int row, col;
        printf("Enter your move: ");
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (board[row-1][col-1] != ' ') {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        board[row-1][col-1] = 'x';
        print_board();
        result = game_over();
        if (result == 1) {
            printf("\nCongratulations! You win!\n");
            break;
        }
        else if (result == 2) {
            printf("\nSorry, you lose. Better luck next time!\n");
            break;
        }
        else if (result == 3) {
            printf("\nIt's a tie!\n");
            break;
        }

        //AI move
        ai_move();
        print_board();
        result = game_over();
        if (result == 1) {
            printf("\nCongratulations! You win!\n");
            break;
        }
        else if (result == 2) {
            printf("\nSorry, you lose. Better luck next time!\n");
            break;
        }
        else if (result == 3) {
            printf("\nIt's a tie!\n");
            break;
        }
    }

    return 0;
}