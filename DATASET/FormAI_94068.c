//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// function to print the bingo board
void print_board(int board[][SIZE]) {
    printf("--------------------------\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf(" %d |", board[i][j]);
        }
        printf("\n--------------------------\n");
    }
}

int main(void) {
    int board[SIZE][SIZE] = {0}; // initialize the board with 0
    int nums[SIZE*SIZE] = {0}; // to keep track of the numbers
    int count = 0, row, col, num;
    
    srand(time(NULL)); // for random number generation
    
    printf("Welcome to the Bingo Simulator!\n");
    printf("Press enter to start!\n");
    getchar(); // wait for user input
    
    // generate random numbers and update the board
    while(count < SIZE*SIZE) {
        num = rand() % (SIZE*SIZE) + 1;
        
        // check if the number is already called
        int flag = 0;
        for(int i=0; i<count; i++) {
            if(nums[i] == num) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            continue;
        }
        nums[count] = num;
        count++;
        
        // find the position of the number on the board
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                if(board[i][j] == num) {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        // mark the position on the board as "X"
        board[row][col] = 'X';
        
        // print the updated board
        system("clear"); // for linux/macOS
        //system("cls"); // for windows
        printf("Number Generated: %d\n\n", num);
        print_board(board);
        
        // check for bingo
        int check_row, check_col, check_diagonal = 1, check_anti_diagonal = 1;
        for(int i=0; i<SIZE; i++) {
            check_row = 1;
            check_col = 1;
            for(int j=0; j<SIZE; j++) {
                if(board[i][j] != 'X') {
                    check_row = 0;
                }
                if(board[j][i] != 'X') {
                    check_col = 0;
                }
            }
            if(board[i][i] != 'X') {
                check_diagonal = 0;
            }
            if(board[i][SIZE-i-1] != 'X') {
                check_anti_diagonal = 0;
            }
            if(check_row || check_col || check_diagonal || check_anti_diagonal) {
                printf("\n\nBINGO!!!\n\n");
                return 0;
            }
        }
    }
    printf("\n\nNo more numbers left. Game Over!\n\n");
    return 0;
}