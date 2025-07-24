//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE];
char player_mark, computer_mark;

//function to print the game board
void print_board() {
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf(" %c ", board[i][j]);
            if(j<SIZE-1) {
                printf("|");
            }
        }
        printf("\n");
        if(i<SIZE-1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

//function to get user input for their move
void player_move() {
    int row, col;
    printf("Player's Move: \n");
    do {
        printf("Enter row (1-%d): ", SIZE);
        scanf("%d", &row);
        printf("Enter column (1-%d): ", SIZE);
        scanf("%d", &col);
        row--;
        col--;
        if(board[row][col] != ' ') {
            printf("Cell already taken.\n");
        }
    } while(board[row][col] != ' ');
    board[row][col] = player_mark;
}

//function to check if either player has won the game
int check_win(char mark) {
    int count;
    for(int i=0; i<SIZE; i++) {
        count = 0;
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == mark) {
                count++;
            }
        }
        if(count == SIZE) {
            return 1;
        }
    }
    for(int i=0; i<SIZE; i++) {
        count = 0;
        for(int j=0; j<SIZE; j++) {
            if(board[j][i] == mark) {
                count++;
            }
        }
        if(count == SIZE) {
            return 1;
        }
    }
    count = 0;
    for(int i=0; i<SIZE; i++) {
        if(board[i][i] == mark) {
            count++;
        }
    }
    if(count == SIZE) {
        return 1;
    }
    count = 0;
    for(int i=0; i<SIZE; i++) {
        if(board[i][SIZE-1-i] == mark) {
            count++;
        }
    }
    if(count == SIZE) {
        return 1;
    }
    return 0;
}

//function to check if the game is a tie
int check_tie() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

//function to get the computer's move using a simple AI algorithm
void computer_move() {
    int row, col, count;
    printf("Computer's Move: \n");
    //check rows
    for(int i=0; i<SIZE; i++) {
        count = 0;
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == computer_mark) {
                count++;
            }
        }
        if(count == SIZE-1) {
            for(int j=0; j<SIZE; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = computer_mark;
                    return;
                }
            }
        }
    }
    //check columns
    for(int i=0; i<SIZE; i++) {
        count = 0;
        for(int j=0; j<SIZE; j++) {
            if(board[j][i] == computer_mark) {
                count++;
            }
        }
        if(count == SIZE-1) {
            for(int j=0; j<SIZE; j++) {
                if(board[j][i] == ' ') {
                    board[j][i] = computer_mark;
                    return;
                }
            }
        }
    }
    //check diagonal
    count = 0;
    for(int i=0; i<SIZE; i++) {
        if(board[i][i] == computer_mark) {
            count++;
        }
    }
    if(count == SIZE-1) {
        for(int i=0; i<SIZE; i++) {
            if(board[i][i] == ' ') {
                board[i][i] = computer_mark;
                return;
            }
        }
    }
    //check other diagonal
    count = 0;
    for(int i=0; i<SIZE; i++) {
        if(board[i][SIZE-1-i] == computer_mark) {
            count++;
        }
    }
    if(count == SIZE-1) {
        for(int i=0; i<SIZE; i++) {
            if(board[i][SIZE-1-i] == ' ') {
                board[i][SIZE-1-i] = computer_mark;
                return;
            }
        }
    }
    //make random move
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while(board[row][col] != ' ');
    board[row][col] = computer_mark;
}

int main() {
    int mode, turn;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Select Mode: \n");
    printf("1. Play against the computer.\n");
    printf("2. Exit game.\n");
    scanf("%d", &mode);
    if(mode == 2) {
        return 0;
    }
    printf("Player Mark: ");
    scanf(" %c", &player_mark);
    if(player_mark == 'X') {
        computer_mark = 'O';
    } else {
        computer_mark = 'X';
    }
    printf("Player: %c Computer: %c\n", player_mark, computer_mark);
    printf("Press 1 if you want to go first or press 2 if you want the computer to go first.\n");
    scanf("%d", &turn);
    if(turn == 1) {
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                board[i][j] = ' ';
            }
        }
    } else {
        player_move();
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                board[i][j] = ' ';
            }
        }
        computer_move();
    }
    print_board();
    do {
        if(turn == 1) {
            player_move();
        } else {
            computer_move();
        }
        print_board();
        if(check_win(player_mark)) {
            printf("Congratulations! You won!\n");
            return 0;
        }
        if(check_win(computer_mark)) {
            printf("The computer won. Better luck next time!\n");
            return 0;
        }
        if(check_tie()) {
            printf("It's a tie!\n");
            return 0;
        }
        turn = (turn == 1) ? 2 : 1;
    } while(1);
    return 0;
}