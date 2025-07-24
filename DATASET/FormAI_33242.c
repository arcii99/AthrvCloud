//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

char board[3][3];

void print_board(); // function that displays the current board 
int check_win(); // function that checks if there is a winner yet 
void ai_move(); // function that makes the AI move 

int main() {
    int i, j;
    char c;
    // initialization of the board 
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
    printf("Welcome to Tic Tac Toe!\n");
    print_board();
    // game loop 
    while(1) {
        printf("Player 1's turn.\n");
        printf("Enter the row and column to place your mark: ");
        scanf("%d %d", &i, &j);
        // check if input is valid
        if(i<0 || i>2 || j<0 || j>2) {
            printf("Invalid input.\n");
            continue;
        }
        if(board[i][j] != '-') {
            printf("That spot is already taken.\n");
            continue;
        }
        board[i][j] = 'X';
        print_board();
        if(check_win() == 1) {
            printf("Player 1 wins!\n");
            break; // game over 
        }
        ai_move(); // AI makes a move 
        print_board();
        if(check_win() == 1) {
            printf("AI wins!\n");
            break; // game over 
        }
    }
    return 0;
}

void print_board() {
    int i, j;
    printf("\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_win() {
    int i;
    // check rows 
    for(i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return 1; // winner 
        }
    }
    // check columns 
    for(i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return 1; // winner 
        }
    }
    // check diagonals 
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return 1; // winner 
    }
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != '-') {
        return 1; // winner 
    }
    return 0; // no winner yet 
}

void ai_move() {
    int i, j, flag=0;
    // check for winning move 
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'O';
                if(check_win() == 1) {
                    flag = 1;
                    break;
                }
                board[i][j] = '-';
            }
        }
        if(flag == 1) break;
    }
    if(flag == 0) {
        // check for blocking move 
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'X';
                    if(check_win() == 1) {
                        board[i][j] = 'O';
                        flag = 1;
                        break;
                    }
                    board[i][j] = '-';
                }
            }
            if(flag == 1) break;
        }
    }
    if(flag == 0) {
        // make random move 
        while(1) {
            i = rand()%3;
            j = rand()%3;
            if(board[i][j] == '-') {
                board[i][j] = 'O';
                break;
            }
        }
    }
    printf("AI has made it's move.\n");
}