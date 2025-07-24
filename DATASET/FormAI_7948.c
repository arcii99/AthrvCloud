//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

void fill_card(int card[ROWS][COLS]);
void display_card(int card[ROWS][COLS]);
int generate_num(int nums[]);
void mark_card(int card[ROWS][COLS], int num);
int check_bingo(int card[ROWS][COLS]);

int main() {
    int card[ROWS][COLS]; // bingo card
    int nums[MAX_NUM]; // array to hold called numbers
    int num; // current called number
    int turn = 0; // current turn
    int winner = 0; // flag to indicate if there is a winner

    // initialize random seed
    srand(time(NULL));
    
    // fill and display bingo card
    fill_card(card);
    display_card(card);

    // loop until there is a winner or all numbers have been called
    while (!winner && turn < MAX_NUM) {
        num = generate_num(nums); // generate a new number
        printf("Number called: %d\n", num);
        mark_card(card, num); // mark the card with the called number
        display_card(card); // display the updated card
        winner = check_bingo(card); // check for a winner
        turn++; // increment the turn counter
    }

    // print end of game message
    if (winner) {
        printf("BINGO! You are the winner in %d turns!\n", turn);
    } else {
        printf("Game over. No winner.\n");
    }

    return 0;
}

// function to fill a bingo card with random numbers
void fill_card(int card[ROWS][COLS]) {
    int i, j, num;
    // loop through rows
    for (i = 0; i < ROWS; i++) {
        // loop through columns
        for (j = 0; j < COLS; j++) {
            // generate random number
            num = rand() % (10 * (j + 1)) + (10 * j + 1);
            // check for duplicate number in row
            while (num_in_row(card, i, num)) {
                num = rand() % (10 * (j + 1)) + (10 * j + 1);
            }
            card[i][j] = num; // add number to card
        }
    }
}

// function to display a bingo card
void display_card(int card[ROWS][COLS]) {
    int i, j;
    // loop through rows
    for (i = 0; i < ROWS; i++) {
        // loop through columns
        for (j = 0; j < COLS; j++) {
            printf("%2d ", card[i][j]); // print number with two-digit formatting
        }
        printf("\n"); // move to next row
    }
    printf("\n"); // add space after card
}

// function to generate a new number
int generate_num(int nums[]) {
    int num;
    do {
        num = rand() % MAX_NUM + 1; // generate random number between 1 and 75
    } while (num_in_array(nums, num)); // check for duplicate number
    return num;
}

// function to mark the bingo card with a called number
void mark_card(int card[ROWS][COLS], int num) {
    int i, j;
    // loop through rows
    for (i = 0; i < ROWS; i++) {
        // loop through columns
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == num) { // if number is on card
                card[i][j] = 0; // mark number as called by setting it to 0
                return; // exit function
            }
        }
    }
}

// function to check for a bingo
int check_bingo(int card[ROWS][COLS]) {
    int i, j, count;
    // check rows for bingo
    for (i = 0; i < ROWS; i++) {
        count = 0; // reset counter
        // loop through columns
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == 0) { // if number has been called
                count++; // increment counter
                if (count == COLS) { // if all numbers in row have been called
                    return 1; // bingo!
                }
            }
        }
    }
    // check columns for bingo
    for (j = 0; j < COLS; j++) {
        count = 0; // reset counter
        // loop through rows
        for (i = 0; i < ROWS; i++) {
            if (card[i][j] == 0) { // if number has been called
                count++; // increment counter
                if (count == ROWS) { // if all numbers in column have been called
                    return 1; // bingo!
                }
            }
        }
    }
    // check diagonal from top left to bottom right for bingo
    count = 0; // reset counter
    for (i = 0; i < ROWS; i++) {
        if (card[i][i] == 0) { // if number has been called
            count++; // increment counter
            if (count == ROWS) { // if all numbers in diagonal have been called
                return 1; // bingo!
            }
        }
    }
    // check diagonal from top right to bottom left for bingo
    count = 0; // reset counter
    for (i = 0; i < ROWS; i++) {
        if (card[i][COLS - 1 - i] == 0) { // if number has been called
            count++; // increment counter
            if (count == ROWS) { // if all numbers in diagonal have been called
                return 1; // bingo!
            }
        }
    }
    // no bingo yet
    return 0;
}

// function to check if a number is in an array
int num_in_array(int nums[], int num) {
    int i;
    // loop through array
    for (i = 0; i < MAX_NUM; i++) {
        if (nums[i] == num) { // if number is in array
            return 1; // return true
        }
    }
    return 0; // return false
}

// function to check if a number is in a row of the bingo card
int num_in_row(int card[ROWS][COLS], int row, int num) {
    int j;
    // loop through columns of specified row
    for (j = 0; j < COLS; j++) {
        if (card[row][j] == num) { // if number is in row
            return 1; // return true
        }
    }
    return 0; // return false
}