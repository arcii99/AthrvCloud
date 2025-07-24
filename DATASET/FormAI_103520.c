//FormAI DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void clear_screen() {
    printf("\033[2J\033[H");
}

void print_board(char board[SIZE][SIZE]) {
    int i, j;

    printf("\n\n");
    printf("\t\t--------------------------------------------------\n");
    printf("\t\t|\t    Memory Game - C Edition\t\t|\n");
    printf("\t\t--------------------------------------------------\n");

    for (i = 0; i < SIZE; i++) {
        printf("\t\t|");
        for (j = 0; j < SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("\t\t--------------------------------------------------\n");
    }
    printf("\n");
}

void fill_board(char board[SIZE][SIZE]) {
    int i, j, count = 97;
    for (i = 0; i < SIZE/2; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = (char)count;
        }
        count++;
    }

    count = 97;

    for (i = SIZE/2; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = (char)count;
        }
        count++;
    }
}

void shuffle_board(char board[SIZE][SIZE]) {
    int i, j;
    char temp;
    srand(time(0));

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            int r1 = rand() % SIZE;
            int c1 = rand() % SIZE;
            temp = board[i][j];
            board[i][j] = board[r1][c1];
            board[r1][c1] = temp;
        }
    }

    clear_screen();
    print_board(board);
}

int main () {
    char board[SIZE][SIZE];
    int r1, c1, r2, c2;

    fill_board(board);
    shuffle_board(board);

    while (1) {
        printf("Enter the coordinates of the first card:\n");
        scanf("%d %d", &r1, &c1);
        printf("Enter the coordinates of the second card:\n");
        scanf("%d %d", &r2, &c2);

        if (board[r1][c1] == board[r2][c2]) {
            board[r1][c1] = '*';
            board[r2][c2] = '*';
            clear_screen();
            print_board(board);

            int i, j;
            int flag = 1;
            for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {
                    if (board[i][j] != '*') {
                        flag = 0;
                        break;
                    }
                }
            }

            if (flag == 1) {
                printf("You have matched all the cards! Congratulation!\n");
                break;
            }
        }
        else {
            clear_screen();
            print_board(board);
        }
    }

    return 0;
}