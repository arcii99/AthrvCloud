//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int *board) {
    printf("\n\n\nWelcome to the Bingo Simulator!\n\n");
    printf("Here is the current board:\n\n");
    printf("-----------------------------\n");
    for(int i = 0; i < 5; i++) {
        printf("|");
        for(int j = 0; j < 5; j++) {
            if(board[i * 5 + j] == -1) {
                printf("  X  |"); // marks the cell with an X if it has already been called
            } else {
                printf("  %d  |", board[i * 5 + j]);
            }
        }
        printf("\n-----------------------------\n");
    }
}

int check_win(int *board) {
    int row_sum, col_sum, diag_sum_l, diag_sum_r;
    for(int i = 0; i < 5; i++) {
        row_sum = col_sum = 0;
        for(int j = 0; j < 5; j++) {
            // check rows
            row_sum += board[i * 5 + j];
            // check columns
            col_sum += board[j * 5 + i];
        }
        if(row_sum == 0 || col_sum == 0) {
            return 1; // there is a win
        }
        // check diagonal
        diag_sum_l += board[i * 5 + i];
        diag_sum_r += board[(i + 1) * (5 - 1)];
    }
    if(diag_sum_l == 0 || diag_sum_r == 0) {
        return 1; // there is a win
    }
    return 0; // no win yet
}

int main(void) {
    int board[25];
    for(int i = 0; i < 25; i++) {
        board[i] = i + 1; // fill the board with numbers 1 to 25
    }
    srand(time(NULL)); // seed the random number generator with the time
    for(int i = 0; i < 25; i++) {
        int r = rand() % 25; // pick a random number between 0 and 24
        int temp = board[i];
        board[i] = board[r];
        board[r] = temp; // swap the two numbers
    }
    for(int i = 0; i < 25; i++) {
        int num;
        system("clear"); // clear the console
        print_board(board);
        printf("\n\nEnter the number called: ");
        scanf("%d", &num);
        int found = 0;
        for(int j = 0; j < 25; j++) {
            if(board[j] == num) {
                board[j] = -1; // mark the cell with an X to show that it has already been called
                found = 1;
                break;
            }
        }
        if(!found) {
            printf("\n\nThat number is not on the board!\n");
            sleep(2); // wait for 2 seconds
        }
        if(check_win(board)) { // check if there is a win
            printf("\n\nBingo! You win!\n");
            return 0;
        }
    }
    printf("\n\nGame over! Better luck next time!\n"); // all numbers have been called and there is no win
    return 0;
}