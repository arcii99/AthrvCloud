//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
	This program simulates the game of Tic Tac Toe between two players.
	Player 1 is always 'X' and Player 2 is always 'O'.
*/

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

bool check_win() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

void print_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int main() {
    pid_t pid;
    int status;

    pid = fork();
    if(pid > 0) { // First player, 'X'
        srand(time(NULL));
        int moves = 0;
        while(1) {
            int x = rand() % 3;
            int y = rand() % 3;
            if(board[x][y] != 'X' && board[x][y] != 'O') {
                printf("Player 1 ('X') chose position (%d, %d)\n", x+1, y+1);
                board[x][y] = 'X';
                print_board();
                if(check_win()) {
                    printf("Player 1 ('X') wins!\n");
                    exit(0);
                }
                if(moves == 4) {
                    printf("Draw\n");
                    exit(0);
                }
                moves++;
                sleep(2);
            }
        }
    } else if(pid == 0) { // Second player, 'O'
        srand(time(NULL));
        int moves = 0;
        while(1) {
            int x = rand() % 3;
            int y = rand() % 3;
            if(board[x][y] != 'X' && board[x][y] != 'O') {
                printf("Player 2 ('O') chose position (%d, %d)\n", x+1, y+1);
                board[x][y] = 'O';
                print_board();
                if(check_win()) {
                    printf("Player 2 ('O') wins!\n");
                    exit(0);
                }
                if(moves == 4) {
                    printf("Draw\n");
                    exit(0);
                }
                moves++;
                sleep(2);
            }
        }
    } else {
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    return 0;
}