//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_ROWS 5     //bingo board has generally 5 rows
#define NUM_COLS 5     //bingo board has generally 5 columns

//Function to Initialize the Bingo Board
void initialize_board(int bingo_board[NUM_ROWS][NUM_COLS]) {
    int i, j;
    //Randomly assign values from 1-25 to the board cells
    for(i=0;i<NUM_ROWS;i++) {
        for(j=0;j<NUM_COLS;j++) {
            bingo_board[i][j] = rand()%25 + 1;
        }
    }
    //Set the center cell as "Free Space"
    bingo_board[NUM_ROWS/2][NUM_COLS/2] = -1;
}

//Function to Print the Bingo Board
void print_board(int bingo_board[NUM_ROWS][NUM_COLS]) {
    int i, j;
    printf("----------------------------------------\n");
    for(i=0;i<NUM_ROWS;i++) {
        printf("|");
        for(j=0;j<NUM_COLS;j++) {
            if(bingo_board[i][j] == -1) {
                printf("   \t|");
            }
            else {
                printf(" %d\t|",bingo_board[i][j]);
            }
        }
        printf("\n");
        printf("----------------------------------------\n");
    }
}

//Function to Check If the Board Has a Winner
int is_winner(int bingo_board[NUM_ROWS][NUM_COLS]) {
    int i, j, count = 0;

	//Check if all cells in any row are marked
    for(i=0;i<NUM_ROWS;i++) {
        count = 0;
        for(j=0;j<NUM_COLS;j++) {
            if(bingo_board[i][j] == -1) {
                count++;
            }
        }
        if(count == NUM_COLS) {
            return 1;
        }
    }

	//Check if all cells in any column are marked
    for(j=0;j<NUM_COLS;j++) {
        count = 0;
        for(i=0;i<NUM_ROWS;i++) {
            if(bingo_board[i][j] == -1) {
                count++;
            }
        }
        if(count == NUM_ROWS) {
            return 1;
        }
    }

	//Check if all cells in any diagonal are marked
    if(bingo_board[0][0] == -1 && bingo_board[1][1] == -1 && bingo_board[2][2] == -1 && bingo_board[3][3] == -1 && bingo_board[4][4] == -1) {
        return 1;
    }
    if(bingo_board[0][4] == -1 && bingo_board[1][3] == -1 && bingo_board[2][2] == -1 && bingo_board[3][1] == -1 && bingo_board[4][0] == -1) {
        return 1;
    }

    return 0;
}

int main() {
    int bingo_board[NUM_ROWS][NUM_COLS];
    int i, j, input_number;

    srand(time(NULL)); //Initialize rand function with current time

    initialize_board(bingo_board); //Initialize the bingo board
    printf("Welcome to Bingo Simulator\n");

    while(1) {
        printf("\nHere is your Bingo Board:\n");
        print_board(bingo_board); //Print the current board
        printf("Enter the next Bingo Number (0 to exit): ");
        scanf("%d", &input_number);

        if(input_number == 0) {
            break; //Exit if input is 0
        }

        for(i=0;i<NUM_ROWS;i++) {
            for(j=0;j<NUM_COLS;j++) {
                if(bingo_board[i][j] == input_number) {
                    bingo_board[i][j] = -1; //Mark the cell as "Free Space"
                }
            }
        }

        if(is_winner(bingo_board)) {
            printf("BINGO!! You Have Won the Game!\n");
            break; //Exit if there is a winner
        }
    }

    return 0;
}